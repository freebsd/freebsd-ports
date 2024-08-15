PORTNAME=	adguardhome
DISTVERSIONPREFIX=	v
DISTVERSION=	0.107.51
PORTREVISION=	4
CATEGORIES=	www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Network-wide ads & trackers blocking DNS server
WWW=		https://adguard.com/en/adguard-home/overview.html

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss

USES=		cpe go:1.22,modules

GO_MODULE=	github.com/AdguardTeam/AdGuardHome
GO_BUILDFLAGS=	-ldflags="-s -w -X github.com/AdguardTeam/AdGuardHome/internal/version.version=${DISTVERSION}" # workaround for https://github.com/AdguardTeam/AdGuardHome/issues/4774

# to rebuild the deps archives:
#   1. set DEV_UPDATE_MODE=yes
#   2. make makesum build
#   3. upload the *-html-{build,client}* archives
#   4. set DEV_UPDATE_MODE=no
#   5. make clean makesum

DEV_UPDATE_MODE=	no

USER=		root # it has to run as root because it listens on the privileged DNS port
GROUP=		wheel
SUB_LIST=	USER=${USER} GROUP=${GROUP}
USE_RC_SUBR=	${PORTNAME}

CPE_VENDOR=	adguard

.if (${DEV_UPDATE_MODE} == "yes")
BUILD_DEPENDS=	npm:www/npm \
		yarn:www/yarn
MAKE_ENV+=	NODE_OPTIONS=--openssl-legacy-provider # workaround suggested in https://github.com/AdguardTeam/AdGuardHome/issues/6585

do-build:
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} js-deps js-build && \
		${TAR} czf ${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}-html-build-${DISTVERSION}${EXTRACT_SUFX} build && \
		${TAR} czf ${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}-html-client-${DISTVERSION}${EXTRACT_SUFX} client && \
		${ECHO} "Please upload files ${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}-html-build-${DISTVERSION}${EXTRACT_SUFX} and ${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}-html-client-${DISTVERSION}${EXTRACT_SUFX}"
.else
MASTER_SITES=	LOCAL/yuri/:deps
DISTFILES=	${PORTNAME}-html-build-${DISTVERSION}${EXTRACT_SUFX}:deps \
		${PORTNAME}-html-client-${DISTVERSION}${EXTRACT_SUFX}:deps

pre-build:
	@${CP} -r ${WRKDIR}/build ${WRKDIR}/client ${WRKSRC}/
.endif

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
