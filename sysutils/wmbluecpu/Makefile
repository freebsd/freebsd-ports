# New ports collection makefile for:	wmbluecpu
# Date created:				29 Mar 2003
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	wmbluecpu
PORTVERSION=	0.4
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	X11/xutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A CPU monitoring dockapp

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes

MAN1=		wmbluecpu.1
PLIST_FILES=	bin/wmbluecpu

post-patch:
	@${CP} ${FILESDIR}/cpu_freebsd.* ${WRKSRC}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${CHMOD} g+s ${PREFIX}/bin/${PORTNAME}
	@${CHOWN} root:kmem ${PREFIX}/bin/${PORTNAME}
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
