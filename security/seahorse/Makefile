# New ports collection makefile for:	Seahorse
# Version required:	0.3.6
# Date created:		08 March 2000
# Whom:			Dave McKay <dave@mu.org>
#
# $FreeBSD$
#
#http://seahorse.sourceforge.net/

DISTNAME=	seahorse-0.3.6
CATEGORIES=	security 
MASTER_SITES=	http://www.mu.org/~dave/

MAINTAINER=	dave@mu.org

GNU_CONFIGURE=  yes
LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12
RUN_DEPENDS=	gnupg-1.0.1:${PORTSDIR}/security/gnupg
MAN1=           seahorse.1

WRKSRC=		${WRKDIR}/seahorse-0.3.6

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/seahorse ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/doc/seahorse.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
