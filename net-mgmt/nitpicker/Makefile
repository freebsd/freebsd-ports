# New ports collection makefile for:	nitpicker
# Date created:				22 May 2003
# Whom:					Michael Reifenberger
#
# $FreeBSD$
#

PORTNAME=	nitpicker
PORTVERSION=	1.2.1
PORTEPOCH=1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://nitpicker.de/

MAINTAINER=	mr@freebsd.org
COMMENT=	IP flow Accounting tools

NO_MAN= YES

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/nitpicker ${LOCALBASE}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/parse_flowfile/src/parse_flowfile ${LOCALBASE}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/dumpit/dumpit ${LOCALBASE}/bin

.include <bsd.port.post.mk>
