PORTNAME=	libdisplay-info
DISTVERSION=	0.1.1
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
GL_COMMIT=	92b031749c0fe84ef5cdf895067b84a829920e25
SHEBANG_FILES=	tool/*.py

post-patch:
# XXX Drop after FreeBSD 12.3 EOL around 2023-03-31
# https://cgit.freebsd.org/src/commit/?id=773538247007
	@if [ ${OPSYS} = FreeBSD -a ${OSVERSION} -lt 1203501 ]; then \
		${REINPLACE_CMD} -e 's/static_assert/_Static_assert/' \
			${WRKSRC}/edid.c; \
	fi

pre-test:
	@if [ ! -e ${WRKDIR}/.meson_build_tests ]; then \
		${RM} ${CONFIGURE_COOKIE} ${BUILD_COOKIE}; \
		${MAKE} -C${.CURDIR} build MESON_ARGS="${MESON_ARGS} --reconfigure"; \
		${TOUCH} ${WRKDIR}/.meson_build_tests; \
	fi

.include <bsd.port.mk>
