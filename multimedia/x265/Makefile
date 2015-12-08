# Created by: adamw
# $FreeBSD$

PORTNAME=	x265
PORTVERSION=	1.8
CATEGORIES=	multimedia
MASTER_SITES=	http://bitbucket.org/multicoreware/${PORTNAME}/get/
DISTNAME=	${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	H.265/High Efficiency Video Coding (HEVC) format

LICENSE=	GPLv2 # or later
LICENSE_FILE=	${WRKSRC}/../COPYING

BUILD_DEPENDS=	yasm:${PORTSDIR}/devel/yasm

USES=		cmake tar:bz2
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/multicoreware-${PORTNAME}-e27327f5da35/source

post-patch:
	@${REINPLACE_CMD} -e \
		's|$${LIB_INSTALL_DIR}/pkgconfig|libdata/pkgconfig|' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
