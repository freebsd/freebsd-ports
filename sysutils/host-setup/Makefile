# Created by: Devin Teske <dteske@vicor.com>
# $FreeBSD$

PORTNAME=	host-setup
PORTVERSION=	4.0.2
CATEGORIES=	sysutils
MASTER_SITES=	http://druidbsd.sourceforge.net/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	System configuration setup/management utility

NO_BUILD=	yes

PLIST_FILES=	sbin/${PORTNAME} man/man1/${PORTNAME}.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
