PORTNAME=	tinyauth
DISTVERSIONPREFIX=	v
DISTVERSION=	5.0.4
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	LOCAL/dtxdf/${PORTNAME}/:assets
# For instructions on how to create assets:
#   https://github.com/DtxdF/port-assets-makejails/tree/main/tinyauth
DISTFILES=	${PORTNAME}-${DISTVERSIONPREFIX}${DISTVERSION}.frontend${EXTRACT_SUFX}:assets \
		${PORTNAME}-${DISTVERSIONPREFIX}${DISTVERSION}.vendor${EXTRACT_SUFX}:assets

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Simplest way to protect your apps with a login screen
WWW=		https://tinyauth.app

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	module modernc.org/sqlite only supported on aarch64 and amd64

USES=		go:1.25+,modules
USE_GITHUB=	yes
GH_ACCOUNT=	steveiliop56

USE_RC_SUBR=	${PORTNAME}

GO_MOD_DIST=	github
GO_TARGET=		./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
			-X 'tinyauth/internal/constants.Version=${DISTVERSIONPREFIX}${DISTVERSION}' \
			-X 'tinyauth/internal/constants.CommitHash=${GITID}' \
			-X 'tinyauth/internal/constants.BuildTimestamp=${BUILD_DATE}'"

SUB_FILES=	pkg-message
SUB_LIST=	USER=${USERS:[1]}

USERS=		${TINYAUTH_USER}
GROUPS=		${TINYAUTH_GROUP}

PLIST_FILES=	bin/${PORTNAME} \
		"@dir(${TINYAUTH_USER},${TINYAUTH_GROUP},0750) /var/db/${PORTNAME}"

# Run 'git checkout ${DISTVERSIONPREFIX}${DISTVERSION} && git rev-parse HEAD'
# in the Tinyauth repository to get the value of GITID.
GITID=		03f13efc77554e5b7f52fa419912d24b0a5f2648

BUILD_DATE=	$$(date -u '+%Y-%m-%dT%H:%M:%S')

TINYAUTH_USER=	${PORTNAME}
TINYAUTH_GROUP=	${TINYAUTH_USER}

post-extract:
	@${MKDIR} ${WRKSRC}/vendor
	@cd ${WRKDIR}/${PORTNAME}-vendor && ${COPYTREE_SHARE} . ${WRKSRC}/vendor
	@${MKDIR} ${WRKSRC}/internal/assets/dist
	@cd ${WRKDIR}/${PORTNAME}-frontend && ${COPYTREE_SHARE} . ${WRKSRC}/internal/assets/dist

post-install:
	@${MKDIR} ${STAGEDIR}/var/db/${PORTNAME}

.include <bsd.port.mk>
