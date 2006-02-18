# New ports collection makefile for:	psearch
# Date created:				17 February 2006
# Whom:					Benjamin Lutz
#
# $FreeBSD$
#

PORTNAME=	psearch
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.maxlor.com/files/

MAINTAINER=	benlutz@datacomm.ch
COMMENT=	An utility for searching the FreeBSD Ports Collection

USE_PYTHON_RUN=	yes
NO_BUILD=	yes

MAN1=		psearch.1
PLIST_FILES=	bin/psearch

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/psearch ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/psearch.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
