# New ports collection makefile for: offlineimap
# Date created:		08 Aug 2002
# Whom:			nbm
#
# $FreeBSD$
#

PORTNAME=	offlineimap
PORTVERSION=	3.2.6
CATEGORIES=	mail
MASTER_SITES=	http://gopher.quux.org:70/devel/offlineimap/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	nbm@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

MAN1=		offlineimap.1

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/offlineimap.py ${PREFIX}/bin/offlineimap
	${INSTALL_MAN} ${WRKSRC}/offlineimap.1 ${MANPREFIX}/man/man1/
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/offlineimap.conf ${EXAMPLESDIR}

.include <bsd.port.mk>
