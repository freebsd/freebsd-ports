# New ports collection makefile for:	poppy
# Date created:				13 June 2001
# Whom:					Kevin Lo <kevlo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	poppy
PORTVERSION=	4.01
CATEGORIES=	mail
MASTER_SITES=	http://www.cnpbagwell.com/

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	A client to perform simple tasks with a POP3/IMAP server

NO_BUILD=	yes

#USE_PERL5=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/poppy ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/spamkill ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/poppy.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
