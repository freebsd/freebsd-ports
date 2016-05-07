# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	screenie
PORTVERSION=	1.30.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Small and lightweight screen(1) wrapper

LICENSE=	GPLv2

RUN_DEPENDS=	screen:sysutils/screen

NO_BUILD=	yes

PLIST_FILES=	sbin/screenie man/man1/screenie.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
