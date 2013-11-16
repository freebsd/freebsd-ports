# Created by: Alexey Dokuchaev <danfe@regency.nsu.ru>
# $FreeBSD$

PORTNAME=	wmmemfree
PORTVERSION=	0.7
PORTREVISION=	3
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	X11/xutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Memory and swap monitoring dockapp

USE_BZIP2=	yes
USE_XORG=	xpm

PLIST_FILES=	bin/wmmemfree man/man1/${PORTNAME}.1.gz

post-patch:
	@${CP} ${FILESDIR}/mem_freebsd.* ${WRKSRC}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${CHMOD} g+s ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${CHOWN} root:kmem ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
