# New ports collection makefile for:	rman
# Date created:         27 Dec 1994
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rman
PORTVERSION=	3.0.9
CATEGORIES=	textproc
MASTER_SITES=	ftp://polyglot.sourceforge.net/pub/polyglotman/

MAINTAINER=	tg@FreeBSD.org

MAN1=		rman.1

post-install:
	@strip ${PREFIX}/bin/rman

.include <bsd.port.mk>
