PORTNAME=	adguardhome
DISTVERSIONPREFIX=	v
DISTVERSION=	0.106.0
CATEGORIES=	www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Network-wide ads & trackers blocking DNS server

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		go:modules

GO_MODULE=	github.com/AdguardTeam/AdGuardHome

# to rebuild the deps archives:
#   1. set DEV_UPDATE_MODE=yes
#   2. make makesum patch build
#   3. upload the *-html-build* archives
#   4. set DEV_UPDATE_MODE=no
#   5. make clean makesum

DEV_UPDATE_MODE=	no

USER=		root # it has to run as root because it listens on the privileged DNS port
SUB_LIST=	USER=${USER}
USE_RC_SUBR=	${PORTNAME}

.if (${DEV_UPDATE_MODE} == "yes")
BUILD_DEPENDS=	npm:www/npm \
		yarn:www/yarn
do-build:
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} js-deps js-build && \
		${TAR} czf ${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}-html-build-${DISTVERSION}${EXTRACT_SUFX} build && \
		${TAR} czf ${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}-html-build2-${DISTVERSION}${EXTRACT_SUFX} build2 && \
		${ECHO} "Please upload files ${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}-html-build-${DISTVERSION}${EXTRACT_SUFX} and ${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}-html-build2-${DISTVERSION}${EXTRACT_SUFX}"
.else
MASTER_SITES=	LOCAL/yuri/:deps
DISTFILES=	${PORTNAME}-html-build-${DISTVERSION}${EXTRACT_SUFX}:deps \
		${PORTNAME}-html-build2-${DISTVERSION}${EXTRACT_SUFX}:deps
EXTRACT_ONLY=	${PORTNAME}-html-build-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-html-build2-${DISTVERSION}${EXTRACT_SUFX}

pre-build:
	@${CP} -r ${WRKDIR}/build ${WRKDIR}/build2 ${WRKSRC}/
.endif

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
