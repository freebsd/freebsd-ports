# New ports collection makefile for:	rc5pipe
# Date created:				25 June 2002
# Whom:				Frerich Raabe <frerich.raabe@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	rc5pipe
PORTVERSION=	1.1
CATEGORIES=	security
MASTER_SITES=	http://krazykiwi.homeip.net/FreeBSD/ports/rc5pipe/
EXTRACT_SUFX=	.tgz

MAINTAINER=	frerich.raabe@gmx.de

WRKSRC=		${WRKDIR}/rc5pipe

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rc5pipe ${PREFIX}/bin/rc5pipe

.include <bsd.port.mk>
