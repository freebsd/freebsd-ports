PORTNAME=	tinyauth
DISTVERSIONPREFIX=	v
DISTVERSION=	3.6.2
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	LOCAL/dtxdf/${PORTNAME}/
DISTFILES=	${PORTNAME}-${DISTVERSIONPREFIX}${DISTVERSION}.frontend${EXTRACT_SUFX}

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Simplest way to protect your apps with a login screen
WWW=		https://tinyauth.app

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.23,modules
USE_GITHUB=	yes
GH_ACCOUNT=	steveiliop56

USE_RC_SUBR=	${PORTNAME}

GO_MOD_DIST=	github
GO_MODULE=	github.com/steveiliop56/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
			-X 'tinyauth/internal/constants.Version=${DISTVERSIONPREFIX}${DISTVERSION}' \
			-X 'tinyauth/internal/constants.CommitHash=${GITID}' \
			-X 'tinyauth/internal/constants.BuildTimestamp=${BUILD_DATE}'"

SUB_FILES=	pkg-message
SUB_LIST=	USER=${USERS:[1]}

USERS=		${TINYAUTH_USER}
GROUPS=		${TINYAUTH_GROUP}

PLIST_FILES=	bin/${PORTNAME}

# Run 'git checkout ${DISTVERSIONPREFIX}${DISTVERSION} && git rev-parse HEAD'
# in the Tinyauth repository to get the value of GITID.
GITID=		5f7f88421ee0d2cc8fd17316fa378b958386a000

BUILD_DATE=	$$(date -u '+%Y-%m-%dT%H:%M:%S')

TINYAUTH_USER=	${PORTNAME}
TINYAUTH_GROUP=	${TINYAUTH_USER}

pre-build:
	@${MKDIR} ${WRKSRC}/internal/assets/dist
	@cd ${WRKDIR}/tinyauth-frontend && ${COPYTREE_SHARE} . ${WRKSRC}/internal/assets/dist

.include <bsd.port.mk>
