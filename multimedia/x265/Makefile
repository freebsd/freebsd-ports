# Created by: adamw
# $FreeBSD$

PORTNAME=	x265
PORTVERSION=	1.4
CATEGORIES=	multimedia
MASTER_SITES=	http://bitbucket.org/multicoreware/${PORTNAME}/get/
DISTNAME=	${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	H.265/High Efficiency Video Coding (HEVC) format

LICENSE=	GPLv2

BUILD_DEPENDS=	yasm:${PORTSDIR}/devel/yasm

USES=		tar:bz2 cmake
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/multicoreware-${PORTNAME}-5e604833c5aa/source

post-patch:
	@${REINPLACE_CMD} -e \
		's|$${LIB_INSTALL_DIR}/pkgconfig|libdata/pkgconfig|' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
