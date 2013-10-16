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

.include <bsd.port.options.mk>

.if ${ARCH} != "i386" && ${ARCH} != "alpha" && ${ARCH} != "amd64"
BROKEN=		Only compiles on i386, amd64 and alpha.
.endif

.if ${PORT_OPTIONS:MSTATIC}
LDFLAGS+=	-static
.endif

.include <bsd.port.mk>
