PORTNAME=	pam_howdy
PORTVERSION=	3.0.0.b.20230306
PORTREVISION=	2
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
RUN_DEPENDS=	${HOWDY_CMD}:security/howdy

USES=		gettext-runtime localbase:ldflags pkgconfig python:env meson ninja

USE_GITHUB=	yes
GH_ACCOUNT=	boltgolt
GH_PROJECT=	howdy
GH_TAGNAME=	30728a6d36

WRKSRC_SUBDIR=	howdy/src/pam
PLIST_FILES=	lib/pam_howdy.so

HOWDY_CMD=	${LOCALBASE}/libexec/howdy/compare.py

post-patch:
	${REINPLACE_CMD} \
		-e 's|/lib/security|${LOCALBASE}/lib|' \
		${WRKSRC}/meson.build
	${REINPLACE_CMD} \
		-e 's|"python3"|"${PYTHON_CMD}"|' \
		-e 's|"/lib/security/howdy/compare.py"|"${HOWDY_CMD}"|' \
		${WRKSRC}/main.cc

.include <bsd.port.mk>
