# New ports collection makefile for:	rman
# Date created:         27 Dec 1994
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rman
PORTVERSION=	3.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	polyglotman

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Reverse compile man pages from formatted form

MAN1=		rman.1
PLIST_FILES=	bin/rman

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/rman

.include <bsd.port.mk>
