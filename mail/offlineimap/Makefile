# New ports collection makefile for: offlineimap
# Date created:		08 Aug 2002
# Whom:			nbm
#
# $FreeBSD$
#

PORTNAME=	offlineimap
PORTVERSION=	3.2.2
CATEGORIES=	mail
MASTER_SITES=	http://gopher.quux.org:70/devel/offlineimap/
DISTNAME=	offlineimap_3.2.2

MAINTAINER=	nbm@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

MAN1=		offlineimap.1

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/offlineimap.py ${PREFIX}/bin/offlineimap
	${INSTALL_MAN} ${WRKSRC}/offlineimap.1 ${MANPREFIX}/man/man1/
	${MKDIR} ${PREFIX}/share/examples/offlineimap
	${INSTALL_DATA} ${WRKSRC}/offlineimap.conf ${PREFIX}/share/examples/offlineimap

.include <bsd.port.mk>
