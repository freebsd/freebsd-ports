# New ports collection makefile for:	lookout
# Date created:		12 Apr 2002
# Whom:			janos.mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	lookout
PORTVERSION=	1.2
CATEGORIES=	mail
MASTER_SITES=	http://tuxedo.org/~esr/lookout/

MAINTAINER=	janos.mohacsi@bsd.hu

USE_PYTHON=	yes
NO_BUILD=	yes

MAN1=	lookout.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/lookout ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/lookout.1 ${PREFIX}/man/man1/lookout.1

.include <bsd.port.mk>
