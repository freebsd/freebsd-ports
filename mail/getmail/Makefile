# New ports collection makefile for:   getmail
# Date created:        06 May 2001
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	getmail
PORTVERSION=	2.0.19
CATEGORIES=	mail
MASTER_SITES=	http://www.qcc.sk.ca/~charlesc/software/getmail-2.0/

MAINTAINER=	nakai@FreeBSD.org

RUN_DEPENDS=	python:${PORTSDIR}/lang/python

NO_BUILD=	yes

do-install:
		${MKDIR} ${PREFIX}/share/getmail
		${INSTALL_SCRIPT} ${WRKSRC}/getmail ${PREFIX}/bin
		${INSTALL_SCRIPT} ${WRKSRC}/*.py ${PREFIX}/share/getmail
		${INSTALL_DATA} ${WRKSRC}/getmailrc-example \
		${PREFIX}/share/getmail

.include <bsd.port.mk>
