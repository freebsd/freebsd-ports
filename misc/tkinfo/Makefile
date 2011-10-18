# New ports collection makefile for:	tkinfo
# Date created:         16 Jan 1995
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tkinfo
PORTVERSION=	2.8
PORTREVISION=	2
CATEGORIES=	misc tk
MASTER_SITES=	http://math-www.uni-paderborn.de/~axel/tkinfo/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tk script to read GNU "info" files and display them

LICENSE=	BSD

NO_BUILD=	yes

USE_TK_WRAPPER=	yes

MAN1=		tkinfo.1
PLIST_FILES=	bin/tkinfo

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/local/info|${LOCALBASE}/info|' ${WRKSRC}/tkinfo

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tkinfo ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/tkinfo.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
