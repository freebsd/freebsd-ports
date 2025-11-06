PORTNAME=	openbao
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4.1
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES+=	https://raw.githubusercontent.com/${PORTNAME}/${PORTNAME}/${DISTVERSIONFULL}/
DISTFILES=	go.mod \
		api/go.mod \
		api/auth/approle/go.mod \
		api/auth/kubernetes/go.mod \
		api/auth/userpass/go.mod \
		sdk/go.mod

MAINTAINER=	jake@metalrip.com
COMMENT=	Tool for securely accessing secrets
WWW=		https://openbao.org/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
USE_RC_SUBR=	${PORTNAME}

GO_MODULE=	github.com/${PORTNAME}/${PORTNAME}
GO_TARGET=	:${BIN_NAME}
GO_BUILDFLAGS=	-ldflags="-s \
		-X ${GO_MODULE}/version.GitCommit=${GITID} \
		-X ${GO_MODULE}/version.BuildDate=${SOURCE_DATE_EPOCH} \
		-X ${GO_MODULE}/version.fullVersion=${DISTVERSION}"

SUB_FILES=	pkg-message
SUB_LIST=	USER=${USERS} GROUP=${GROUPS}
USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

PLIST_FILES=	bin/${BIN_NAME}

BIN_NAME=		bao
GITID=			efb9efa12f550e8322f3cec040862355e966f565
SOURCE_DATE_EPOCH=	${TIMEEPOCHNOW:gmtime}
TIMEEPOCHNOW=		%Y-%m-%dT%H:%M:%SZ

.include <bsd.port.mk>
