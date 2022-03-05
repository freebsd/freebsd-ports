PORTNAME=	autoscan
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.0
CATEGORIES=	net-p2p

MAINTAINER=	michiel@vanbaak.eu
COMMENT=	Scan Plex library on webhook triggers

LICENSE=	MIT
LICENSE_FILE=   ${WRKSRC}/LICENSE

USES=		go:modules
USE_RC_SUBR=	autoscan

GO_MODULE=	github.com/cloudbox/autoscan
GO_TARGET=	./cmd/autoscan
GO_BUILDFLAGS+=	-ldflags="-s -w -X main.Version=${DISTVERSION}"

CONFLICTS_INSTALL=	autoconf-wrapper

SUB_LIST=	GROUPS=${GROUPS} \
		USERS=${USERS}

USERS=		autoscan
GROUPS=		autoscan

PLIST_FILES=	bin/autoscan

.include <bsd.port.mk>
