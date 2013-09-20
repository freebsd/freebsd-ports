# Created by: Devin Teske <dteske@vicor.com>
# $FreeBSD$

PORTNAME=	host-setup
PORTVERSION=	4.0.2
CATEGORIES=	sysutils
MASTER_SITES=	http://druidbsd.sourceforge.net/download/

MAINTAINER=	dteske@vicor.com
COMMENT=	System configuration setup/management utility

NO_BUILD=	yes

PLIST_FILES=	sbin/${PORTNAME}
MAN1=		${PORTNAME}.1

NO_STAGE=	yes
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MANPREFIX}/man/man1/

.include <bsd.port.mk>
