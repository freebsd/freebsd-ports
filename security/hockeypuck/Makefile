PORTNAME=	hockeypuck
DISTVERSION=	2.2.4
PORTREVISION=	2
CATEGORIES=	security

MAINTAINER=	me@svmhdvn.name
COMMENT=	Synchronizing Key Server, a fast OpenPGP keyserver
WWW=		https://hockeypuck.github.io

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/server/LICENSE

USES=		go:modules
USE_GITHUB=	yes
USE_RC_SUBR=	hockeypuck

GO_TARGET=	./server/cmd/hockeypuck \
		./server/cmd/hockeypuck-dump \
		./server/cmd/hockeypuck-load \
		./server/cmd/hockeypuck-pbuild
GO_BUILDFLAGS=	-ldflags "-X github.com/hockeypuck/server.version=${PORTVERSION}"

WRKSRC_SUBDIR=	src/hockeypuck

USERS=		_hockeypuck
GROUPS=		_hockeypuck

PLIST_FILES=	bin/hockeypuck \
		bin/hockeypuck-dump \
		bin/hockeypuck-load \
		bin/hockeypuck-pbuild

.include "Makefile.modules"
.include <bsd.port.mk>
