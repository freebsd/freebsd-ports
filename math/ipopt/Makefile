# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	Ipopt
DISTVERSION=	3.12.13
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	https://www.coin-or.org/download/source/Ipopt/ \
		http://glaros.dtc.umn.edu/gkhome/fetch/sw/metis/OLD/:metis \
		http://mumps.enseeiht.fr/:mumps
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		metis-4.0.3.tar.gz:metis MUMPS_4.10.0.tar.gz:mumps
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Software package for large-scale nonlinear optimization

LICENSE=	EPL

USES=		blaslapack compiler:c++11-lang fortran libtool pathfix \
		pkgconfig tar:tgz
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
TEST_TARGET=	test
INSTALL_TARGET=	install-strip

CONFIGURE_ENV+=	PKG_CONFIG_PATH=${PREFIX}/libdata/pkgconfig \
		CXX="${CXX} -B${LOCALBASE}/bin"
CONFIGURE_ARGS=	--with-lapack-lib="${LAPACKLIB} -L${LOCALBASE}/lib"	\
		--with-blas-lib="${BLASLIB} -L${LOCALBASE}/lib"

CXXFLAGS+=	-ffast-math
DEBUG_CXXFLAGS=	-fomit-frame-pointer

DOCSDIR=	${PREFIX}/share/coin/doc/${PORTNAME}

OPTIONS_DEFINE=		DEBUG DOCS

DOCS_ALL_TARGET=	all doxydoc
DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen

PORTDOCS=		*

post-extract:
	@(${ECHO} "Extracting Metis and Mumps ThirdParty libraries ..." )
	@(cd ${WRKSRC}/ThirdParty/Metis && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/metis-4.0.3.tar.gz ${EXTRACT_AFTER_ARGS});
	@(${MV} ${WRKSRC}/ThirdParty/Metis/metis-4.0.? ${WRKSRC}/ThirdParty/Metis/metis-4.0);
	@(cd ${WRKSRC}/ThirdParty/Mumps && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/MUMPS_4.10.0.tar.gz ${EXTRACT_AFTER_ARGS});
	@(${MV} ${WRKSRC}/ThirdParty/Mumps/MUMPS_4.10.0 ${WRKSRC}/ThirdParty/Mumps/MUMPS);

pre-patch:
	@(cd ${WRKSRC}/ThirdParty/Mumps && ${PATCH} -p0 < mumps.patch && ${PATCH} -p0 < mumps_mpi.patch )
	@(${MV} ${WRKSRC}/ThirdParty/Mumps/MUMPS/libseq/mpi.h ${WRKSRC}/ThirdParty/Mumps/MUMPS/libseq/mumps_mpi.h);

pre-build: # workaround: configure fails to find the 'rand' function, need to investigate. This patch unbreaks the build.
	@${REINPLACE_CMD} -e 's|.*HAVE_RAND.*|#define HAVE_RAND 1|' ${WRKSRC}/Ipopt/src/Common/config.h

.include <bsd.port.mk>
