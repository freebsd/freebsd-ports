# New ports collection makefile for: 	xmailwatcher
# Date created:				14 II 2001
# Whom:					Harry Newton
#
# $FreeBSD$
#

PORTNAME=		xmailwatcher
PORTVERSION=		1.6
CATEGORIES=		mail
MASTER_SITES=		ftp://ftp.dcs.ed.ac.uk/pub/X11/
DISTNAME=		xmailwatcher

MAINTAINER=		harry_newton@telinco.co.uk

MAN1=			xmailwatcher.1
USE_IMAKE=		yes

post-install:
	strip ${PREFIX}/bin/xmailwatcher

.include <bsd.port.mk>
