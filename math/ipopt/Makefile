# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	Ipopt
PORTVERSION=	3.12.4
CATEGORIES=	math
MASTER_SITES=	http://www.coin-or.org/download/source/Ipopt/ \
		http://glaros.dtc.umn.edu/gkhome/fetch/sw/metis/OLD/:metis \
		http://mumps.enseeiht.fr/:mumps
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		metis-4.0.3.tar.gz:metis MUMPS_4.10.0.tar.gz:mumps
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	pfg@FreeBSD.org
COMMENT=	Software package for large-scale nonlinear optimization

LICENSE=	EPL

USES=		blaslapack fortran libtool pkgconfig tar:tgz
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CONFIGURE_ENV+=	PKG_CONFIG_PATH=${STAGEDIR}${PREFIX}/libdata/pkgconfig
CONFIGURE_ARGS=	--with-lapack-lib="${LAPACKLIB} -L${LOCALBASE}/lib"	\
		--with-blas-lib="${BLASLIB} -L${LOCALBASE}/lib"

CXXFLAGS+=	-ffast-math

OPTIONS_DEFINE=	DEBUG DOCS
PORTDOCS=	*

DEBUG_CXXFLAGS=	-fomit-frame-pointer

post-patch::
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		's|$$(libdir)/pkgconfig|${PREFIX}/libdata/pkgconfig|' \
		-e 's|$$(DESTDIR)$$(addlibsdir)|$$(addlibsdir)|g'
post-extract:
	@(${ECHO} "Extracting Metis and Mumps ThirdParty libraries ..." )
	@(cd ${WRKSRC}/ThirdParty/Metis && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/metis-4.0.3.tar.gz ${EXTRACT_AFTER_ARGS});
	@(${MV} ${WRKSRC}/ThirdParty/Metis/metis-4.0.? ${WRKSRC}/ThirdParty/Metis/metis-4.0);
	@(cd ${WRKSRC}/ThirdParty/Mumps && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/MUMPS_4.10.0.tar.gz ${EXTRACT_AFTER_ARGS});
	@(${MV} ${WRKSRC}/ThirdParty/Mumps/MUMPS_4.10.0 ${WRKSRC}/ThirdParty/Mumps/MUMPS);

post-install-DOCS-off:
	${RM} -rf ${STAGEDIR}${PREFIX}/share/coin

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Ipopt/doc/documentation.pdf\
	   ${STAGEDIR}${DOCSDIR}
	${MV} ${STAGEDIR}${PREFIX}/share/coin/doc ${STAGEDIR}${DOCSDIR}
	${RM} -rf ${STAGEDIR}${PREFIX}/share/coin

check regression-test test: build
	@(cd ${WRKSRC};  ${SETENV} ${MAKE_ENV} ${MAKE} ${_MAKE_JOBS} \
	${MAKE_ARGS} test)

.include <bsd.port.mk>
