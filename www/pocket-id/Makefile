PORTNAME=	pocket-id
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.2
CATEGORIES=	www
MASTER_SITES=	LOCAL/dtxdf/${PORTNAME}/
DISTFILES=	${PORTNAME}-${DISTVERSIONPREFIX}${DISTVERSION}.frontend${EXTRACT_SUFX}

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	OIDC provider that allows users to authenticate with their passkeys
WWW=		https://pocket-id.org

LICENSE=	BSD2CLAUSE

BROKEN_i386=	cannot use int64(off) (value of type int64) as int32 value in assignment

USES=		go:modules
USE_GITHUB=	yes
USE_RC_SUBR=	${PORTNAME}

GO_MOD_DIST=	github
GO_MODULE=	https://github.com/pocket-id/${PORTNAME}
GO_TARGET=	./cmd:${PORTNAME}
GO_BUILDFLAGS=	-ldflags "-X github.com/pocket-id/pocket-id/backend/internal/common.Version=${DISTVERSION} -buildid=${DISTVERSION}"

SUB_FILES=	pkg-message
SUB_LIST=	USER=${USERS:[1]}

WRKSRC_SUBDIR=	backend

USERS=		${POCKET_ID_USER}
GROUPS=		${POCKET_ID_GROUP}

PLIST_FILES=	bin/${PORTNAME}

POCKET_ID_USER=		${PORTNAME}
POCKET_ID_GROUP=	${POCKET_ID_USER}

pre-build:
	@cd ${WRKDIR}/pocket-id-frontend && ${COPYTREE_SHARE} . ${WRKSRC}/frontend/dist

.include <bsd.port.mk>
