PORTNAME=	libdisplay-info
DISTVERSION=	0.3.0
CATEGORIES=	sysutils

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	EDID and DisplayID library
WWW=		https://gitlab.freedesktop.org/emersion/libdisplay-info

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	hwdata>0:misc/hwdata
TEST_DEPENDS=	edid-decode:sysutils/edid-decode

USES=		compiler:c11 meson pkgconfig python:build shebangfix
USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	emersion
SHEBANG_FILES=	tool/*.py
PLIST_SUB=	VERSION=${DISTVERSION:C/-.*//}

pre-test:
	@if [ ! -e ${WRKDIR}/.meson_build_tests ]; then \
		${RM} ${CONFIGURE_COOKIE} ${BUILD_COOKIE}; \
		${MAKE} -C${.CURDIR} build MESON_ARGS="${MESON_ARGS} --reconfigure"; \
		${TOUCH} ${WRKDIR}/.meson_build_tests; \
	fi

.include <bsd.port.mk>
