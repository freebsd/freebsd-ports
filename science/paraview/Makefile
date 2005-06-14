# New ports collection makefile for:    paraview
# Date created:         		25 May, 2005
# Whom:					anholt@FreeBSD.ORG
#
# $FreeBSD$
#

PORTNAME=	paraview
PORTVERSION=	2.0.2
CATEGORIES=	science graphics
MASTER_SITES=	http://www.paraview.org/files/v2.0/

MAINTAINER=	anholt@FreeBSD.org
COMMENT=	ParaView is a powerful scientific data visualization application

BUILD_DEPENDS=	cmake:${PORTSDIR}/devel/cmake
LIB_DEPENDS=	hdf5.0:${PORTSDIR}/science/hdf5

USE_GL=		yes
WRKSRC=		${WRKDIR}/${DISTNAME}-build
PATCH_WRKSRC=	${WRKDIR}/${DISTNAME}

do-configure:
	${MKDIR} ${WRKSRC}
	cd ${WRKSRC} && \
	${LOCALBASE}/bin/cmake ../${DISTNAME} \
		-DCMAKE_INSTALL_PREFIX:PATH=${PREFIX} \
		-DCMAKE_C_COMPILER=${CC} \
		-DCMAKE_CXX_COMPILER=${CXX} \
		-DPARAVIEW_USE_SYSTEM_HDF5=1

.include <bsd.port.mk>
