# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ext4fuse
PORTVERSION=	0.1.3
DISTVERSIONPREFIX=	v
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	sysutils
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Read-only ext4 implementation for FUSE

LICENSE=	GPLv2

# PR associated with deprecation: 239564
DEPRECATED=	Please consider using sysutils/fusefs-ext2 as upstream development is stalled. \
		Contrary to what its name suggests it supports ext2, ext3, ext4 in read/write \
		mode.
EXPIRATION_DATE=2019-12-01

USES=		fuse pkgconfig gmake
USE_GITHUB=	yes
GH_ACCOUNT=	gerard

# explicitly empty to fix a cross compiling related issue (PR: 165480)
MAKE_ENV+=	TARGET_ARCH=

ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/ext4fuse

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
