# New ports collection makefile for:	wmmemfree
# Date created:				29 Mar 2003
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	wmmemfree
PORTVERSION=	0.7
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://ibiblio.org/pub/linux/X11/xutils/ \
		ftp://ftp.ibiblio.org/pub/linux/X11/xutils/

MAINTAINER=	danfe@regency.nsu.ru
COMMENT=	Memory and swap monitoring dockapp

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes

MAN1=		${PORTNAME}.1
PLIST_FILES=	bin/wmmemfree

post-patch:
	@${CP} ${FILESDIR}/mem_freebsd.* ${WRKSRC}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${CHMOD} g+s ${PREFIX}/bin/${PORTNAME}
	@${CHOWN} root:kmem ${PREFIX}/bin/${PORTNAME}
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
