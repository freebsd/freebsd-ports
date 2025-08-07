PORTNAME=	autoscan
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.0
PORTREVISION=	14
CATEGORIES=	net-p2p

MAINTAINER=	michiel@vanbaak.eu
COMMENT=	Scan Plex library on webhook triggers

LICENSE=	MIT
LICENSE_FILE=   ${WRKSRC}/LICENSE

# See https://gitlab.com/cznic/libc/-/issues/15
ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	Some dependencies only build on amd64 and i386

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
