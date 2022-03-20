PORTNAME=	cglm
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.5
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Highly optimized graphics math (glm) for C

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c11 meson # was cmake before
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	recp

pre-test:
	@if [ ! -e ${WRKDIR}/.meson_build_testing ]; then \
		${RM} ${CONFIGURE_COOKIE} ${BUILD_COOKIE}; \
		${MAKE} -C${.CURDIR} build MESON_ARGS="${MESON_ARGS} --reconfigure -Dbuild_tests=true"; \
		${TOUCH} ${WRKDIR}/.meson_build_testing; \
	fi

.include <bsd.port.mk>
