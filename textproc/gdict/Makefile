# New ports collection makefile for:	gdict
# Date created:			Sun Jul 18 1999
# Whom:				domi@saargate.de
#
# $FreeBSD$
#

PORTNAME=	gdict
PORTVERSION=	0.7
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.brettnacher.org/users/dominik/FreeBSD/

MAINTAINER=	domi@saargate.de
COMMENT=	Small program that finds definitions of arbitrary (english) words

USE_GNOME=	gtk12

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gdict ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/dict ${PREFIX}/bin/cdict

.include <bsd.port.mk>
