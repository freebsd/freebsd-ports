# $FreeBSD$

PORTNAME=	gnustep-examples
PORTVERSION=	1.4.0
PORTREVISION=	3
CATEGORIES=	misc gnustep
MASTER_SITES=	GNUSTEP/usr-apps

MAINTAINER=	ports@FreeBSD.org

USES=	gnustep
USE_GNUSTEP=	back build

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_GNUSTEP_MAKE_DIRS+=	. gui/Finger gui/GFractal gui/HostAddress gui/MyGL

post-patch:
	${REINPLACE_CMD} -e 's|^//|#|' \
		${WRKSRC}/gui/GFractal/GNUmakefile

do-build:
.for i in ${USE_GNUSTEP_MAKE_DIRS}
	@(cd ${BUILD_WRKSRC}/${i}; . ${GNUSTEP_MAKEFILES}/GNUstep.sh; \
	   ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${ALL_TARGET})
.endfor

# ---------------------------------------------------------------------------
# source GNUstep.sh
#
do-install:
.for i in ${USE_GNUSTEP_MAKE_DIRS}
	@(cd ${INSTALL_WRKSRC}/${i}; . ${GNUSTEP_MAKEFILES}/GNUstep.sh; \
	    ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
.endfor

.include <bsd.port.mk>
