# New ports collection makefile for:	mls
# Date created:		21 apr 2003
# Whom:			The Anarcat <anarcat@anarcat.ath.cx>
#
# $FreeBSD$
#

PORTNAME=	mls
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://marki.host.sk/MLS/
EXTRACT_SUFX=	.tgz

MAINTAINER=	anarcat@anarcat.ath.cx
COMMENT=	Program for generating various statistics on emails

MAN1=		mls.1
MANCOMPRESSED=	yes
PLIST_FILES=	bin/mls

MAKE_ARGS+=	DESTDIR=${PREFIX}
USE_GMAKE=	yes
ALL_TARGET=	mls

.include <bsd.port.mk>
