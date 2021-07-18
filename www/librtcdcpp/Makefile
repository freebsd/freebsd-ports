PORTNAME=	librtcdcpp
DISTVERSION=	g20210129
CATEGORIES=	www devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple WebRTC DataChannels library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	spdlog>0:devel/spdlog
LIB_DEPENDS=	libnice.so:net-im/libnice \
		libusrsctp.so:net/libusrsctp

USES=		cmake compiler:c++14-lang gnome ssl
USE_GNOME=	glib20
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	chadnickbok
GH_TAGNAME=	2fe92c38b48b6acf1217a8a812c2408310dec437

CFLAGS+=	-DSPDLOG_FMT_EXTERNAL

do-install:
	cd ${WRKSRC}/include && ${COPYTREE_SHARE} rtcdcpp ${STAGEDIR}${PREFIX}/include
	${INSTALL_LIB} ${BUILD_WRKSRC}/librtcdcpp.so ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
