# Created by: Alexey Dokuchaev <danfe@regency.nsu.ru>
# $FreeBSD$

PORTNAME=	wmmemfree
PORTVERSION=	0.7
PORTREVISION=	4
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	SUNSITE/X11/xutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Memory and swap monitoring dockapp

BROKEN_FreeBSD_12=	fails to compile: read_mem.c: invalid use of undefined type 'struct vmmeter'
BROKEN_FreeBSD_13=	fails to compile: read_mem.c: invalid use of undefined type 'struct vmmeter'
BROKEN_mips=		fails to compile: mem_freebsd.c: storage size of 'vm' isn't known
BROKEN_mips64=		fails to compile: mem_freebsd.c: storage size of 'vm' isn't known

USES=		tar:bzip2 xorg
USE_XORG=	xpm

PLIST_FILES=	"@(,kmem,2555) bin/wmmemfree" man/man1/${PORTNAME}.1.gz

post-patch:
	@${CP} ${FILESDIR}/mem_freebsd.* ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
