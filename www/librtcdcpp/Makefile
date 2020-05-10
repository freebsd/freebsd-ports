# $FreeBSD$

PORTNAME=	librtcdcpp
DISTVERSION=	g20180627
PORTREVISION=	1
CATEGORIES=	www devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple WebRTC DataChannels library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	spdlog>0:devel/spdlog
LIB_DEPENDS=	libnice.so:net-im/libnice \
		libusrsctp.so:net/libusrsctp

USES=		cmake compiler:c++14-lang gnome ssl
USE_GITHUB=	yes
GH_ACCOUNT=	chadnickbok
GH_TAGNAME=	49ddb949ed5dd2c8e859097b6723347f52e01645
USE_GNOME=	glib20
USE_LDCONFIG=	yes

CFLAGS+=	-DSPDLOG_FMT_EXTERNAL

do-install:
	cd ${WRKSRC}/include && ${COPYTREE_SHARE} rtcdcpp ${STAGEDIR}${PREFIX}/include
	${INSTALL_LIB} ${BUILD_WRKSRC}/librtcdcpp.so ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
