# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	Ipopt
PORTVERSION=	3.11.9
CATEGORIES=	math
MASTER_SITES=	http://www.coin-or.org/download/source/Ipopt/:srcs	\
		http://glaros.dtc.umn.edu/gkhome/fetch/sw/metis/OLD/:metis \
		http://mumps.enseeiht.fr/:mumps
DISTFILES=	${PORTNAME}-${PORTVERSION}.tgz:srcs	\
		metis-4.0.3.tar.gz:metis MUMPS_4.10.0.tar.gz:mumps
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	pfg@FreeBSD.org
COMMENT=	Software package for large-scale nonlinear optimization

LICENSE=	EPL

LIB_DEPENDS=	liblapack.so:${PORTSDIR}/math/lapack

USES=		fortran libtool pkgconfig tar:tgz
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CONFIGURE_ENV+=	PKG_CONFIG_PATH=${STAGEDIR}${PREFIX}/libdata/pkgconfig
CONFIGURE_ARGS=	--with-lapack-lib="-llapack -L/${LOCALBASE}/lib"	\
		--with-lapack-incdir=${LOCALBASE}/include/lapack

CXXFLAGS+=	-ffast-math

OPTIONS_DEFINE=	DEBUG DOCS
PORTDOCS=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
CXXFLAGS+=	-fomit-frame-pointer
.endif

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

post-install:
	${MV} ${STAGEDIR}${PREFIX}/share/coin/doc ${STAGEDIR}${DOCSDIR}
	${RM} -rf ${STAGEDIR}${PREFIX}/share/coin

check regression-test test: build
	@(cd ${WRKSRC};  ${SETENV} ${MAKE_ENV} ${MAKE} ${_MAKE_JOBS} \
	${MAKE_ARGS} test)

.include <bsd.port.mk>
