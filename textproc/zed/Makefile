PORTNAME?=	zed
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.0
#PORTREVISION=	0
CATEGORIES=	textproc

MAINTAINER=	meta@FreeBSD.org
COMMENT=	Command-line tool to manage and query Zed data lakes
WWW=		https://zed.brimdata.io/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_i386=	fails to build: cannot use math.MaxUint32 (untyped int constant 4294967295) as int value in assignment (overflows)

USES=		go:modules

GO_MODULE?=	github.com/brimdata/zed
GO_PKGNAME?=	github.com/brimdata/zed/cmd/zed

PLIST_FILES?=	bin/zed

.include <bsd.port.mk>
