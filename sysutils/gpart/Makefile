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
PLIST_FILES=	sbin/gpart man/man8/gpart.8.gz
CFLAGS+=	-std=c99

OPTIONS_DEFINE=	STATIC
STATIC_LDFLAGS=	-static

.include <bsd.port.options.mk>

.if ${ARCH} != "i386" && ${ARCH} != "amd64"
BROKEN=		only compiles on i386 and amd64
.endif

.include <bsd.port.mk>
