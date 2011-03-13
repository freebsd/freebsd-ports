# New ports collection makefile for:	rc5pipe
# Date created:				25 June 2002
# Whom:				Frerich Raabe <frerich.raabe@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	rc5pipe
PORTVERSION=	1.1
CATEGORIES=	security
MASTER_SITES=	http://people.fruitsalad.org/bdavis/FreeBSD/ports/distfiles/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	RC5 en-/decryption via UNIX pipes

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

PLIST_FILES=	bin/rc5pipe
WRKSRC=		${WRKDIR}/rc5pipe

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rc5pipe ${PREFIX}/bin/rc5pipe

.include <bsd.port.mk>
