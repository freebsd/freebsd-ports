# Created by: Andrew Stevenson <andrew@ugh.net.au>
# $FreeBSD$

PORTNAME=	gpart
PORTVERSION=	0.1h
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	SUNSITE/system/filesystems \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Tries to recover lost partition tables and file systems

LICENSE=	GPLv2

USES=		gmake
MAN8=		gpart.8
PLIST_FILES=	sbin/gpart
CFLAGS+=	-std=c99

.if defined(WANT_STATIC)
MAKE_ARGS+=	LDFLAGS=-static
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386" && ${ARCH} != "alpha" && ${ARCH} != "amd64"
BROKEN=		Only compiles on i386, amd64 and alpha.
.endif

.include <bsd.port.post.mk>
