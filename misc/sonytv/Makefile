# New ports collection makefile for:	sonytv
# Date created:		21 June 2003
# Whom:			Eric P. Scott <eps+sonytv@ana.com>
#
# $FreeBSD$
#

PORTNAME=	sonytv
PORTVERSION=	1.0
CATEGORIES=	misc tk83
MASTER_SITES=	http://tools.ana.com/demos/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sony-compatible TV remote

RUN_DEPENDS=	wish8.3:${PORTSDIR}/x11-toolkits/tk83

USE_X_PREFIX=	yes

NO_BUILD=	yes

IS_INTERACTIVE=	yes
NO_PACKAGE=	Hardcoded IR device name

SCRIPTS_ENV=	CP="${CP}" RM="${RM}" SED="${SED}"

MAN1=		sonytv.1
MLINKS=		sonytv.1 sonytv+.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sonytv ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/sonytv+ ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sonytv.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
