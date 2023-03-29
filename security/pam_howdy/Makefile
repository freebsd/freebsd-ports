PORTNAME=	pam_howdy
PORTVERSION=	3.0.0.b
CATEGORIES=	security

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	PAM module for Howdy Face Recognition
WWW=		https://github.com/boltgolt/howdy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/../../../LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto
LIB_DEPENDS=	libevdev.so:devel/libevdev \
		libinih.so:devel/inih \
		libINIReader.so:devel/inih \
		libepoll-shim.so:devel/libepoll-shim

USES=		gettext-runtime localbase:ldflags pkgconfig meson ninja

USE_GITHUB=	yes
GH_ACCOUNT=	boltgolt
GH_PROJECT=	howdy
GH_TAGNAME=	30728a6d3634479c24ffd4e094c34a30bbb43058

WRKSRC_SUBDIR=	howdy/src/pam
PLIST_FILES=	lib/pam_howdy.so

post-patch:
	${REINPLACE_CMD} \
		-e 's|/lib/security|${LOCALBASE}/lib|' \
		${WRKSRC}/meson.build

.include <bsd.port.mk>
