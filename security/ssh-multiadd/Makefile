# New ports collection makefile for:	ssh-multiadd
# Date created:				29 April 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	ssh-multiadd
PORTVERSION=	1.3.2
CATEGORIES=	security
MASTER_SITES=	http://www.dakotacom.net/~donut/programs/ssh-multiadd/

MAINTAINER=	petef@FreeBSD.org
COMMENT=	Tool to add multiple ssh keys to the authentication agent

USE_PYTHON=	yes
USE_REINPLACE=	yes
NO_BUILD=	yes
MAN1=		ssh-multiadd.1
PLIST_FILES=	bin/ssh-multiadd

post-patch:
	@${REINPLACE_CMD} -e 's!/usr/bin/python2!${PYTHON_CMD}!' \
			-e 's!#break!break!' ${WRKSRC}/ssh-multiadd

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ssh-multiadd ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ssh-multiadd.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
