# New ports collection makefile for:	archivemail
# Date created:		2002/04/02
# Whom:			Alan Eldridge <ports@geeksrus.net>
#
# $FreeBSD$
#

PORTNAME=	archivemail
PORTVERSION=	0.1.0
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@geeksrus.net

NO_BUILD=	yes
USE_PYTHON=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
