# New ports collection makefile for:	Seahorse
# Date created:		08 March 2000
# Whom:			Dave McKay <dave@mu.org>
#
# $FreeBSD$
#

PORTNAME=	seahorse
PORTVERSION=	0.3.6
CATEGORIES=	security
MASTER_SITES=	http://www.mu.org/~dave/

MAINTAINER=	dave@mu.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12
RUN_DEPENDS=	gnupg-1.0.1:${PORTSDIR}/security/gnupg

GNU_CONFIGURE=	yes
MAN1=		seahorse.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/seahorse ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/doc/seahorse.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
