# New ports collection makefile for:	poppy
# Date created:				13 June 2001
# Whom:					Kevin Lo <kevlo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	poppy
PORTVERSION=	3.1
CATEGORIES=	mail
MASTER_SITES=	http://home.sprynet.com/~cbagwell/

MAINTAINER=	kevlo@FreeBSD.org

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/poppy ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/poppy.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
