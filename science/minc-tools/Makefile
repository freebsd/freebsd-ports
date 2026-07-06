PORTNAME=	minc-tools
DISTVERSION=	2-3-00
CATEGORIES=	science biology
MASTER_SITES=	https://github.com/BIC-MNI/${PORTNAME}/archive/refs/tags/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Basic minc-tools from former minc repository
WWW=		https://www.bic.mni.mcgill.ca/ServicesSoftware/MINC

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	nifticlib>0:science/nifticlib
LIB_DEPENDS=	libhdf5.so:science/hdf5 \
		libnetcdf.so:science/netcdf \
		libminc2.so:science/libminc
RUN_DEPENDS=	bash:shells/bash

#USE_GITHUB=	yes
#GH_ACCOUNT=	BIC-MNI

USES=		bison cmake localbase perl5 shebangfix
SHEBANG_FILES=	progs/mincview/mincview Testing/*.sh
CMAKE_ARGS=	-DCMAKE_PREFIX_PATH=${LOCALBASE}/lib/cmake

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTNAME}-${DISTVERSION}
USE_LDCONFIG=	yes

#CFLAGS+=	-Wno-error=return-type

pre-patch:
	${RM} ${WRKSRC}/progs/minccalc/gram.[ch]
	${RM} ${WRKSRC}/progs/mincgen/ncgentab.[ch]
	${RM} ${WRKSRC}/cmake-modules/FindHDF5.cmake

.include <bsd.port.mk>
