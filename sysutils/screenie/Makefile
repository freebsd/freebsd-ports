# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	screenie
PORTVERSION=	1.30.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Small and lightweight screen(1) wrapper

LICENSE=	GPLv2

RUN_DEPENDS=	screen:${PORTSDIR}/sysutils/screen

NO_BUILD=	yes

MAN1=		screenie.1
PLIST_FILES=	sbin/screenie

NO_STAGE=	yes
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MANPREFIX}/man/man1

.include <bsd.port.mk>
