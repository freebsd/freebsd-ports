# New ports collection makefile for:	genplist
# Date created:		2007-04-19
# Whom:			Jason Bacon bacon@smithers.neuro.mcw.edu
#
# $FreeBSD$
#

PORTNAME=	genplist
PORTVERSION=	0.1
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://www.neuro.mcw.edu/~bacon/Ports/distfiles/

MAINTAINER=	bacon@smithers.neuro.mcw.edu
COMMENT=	Generates a static plist for a port

NO_BUILD=	yes

PLIST_FILES=	bin/genplist

MAN1=		genplist.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/genplist ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/genplist.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
