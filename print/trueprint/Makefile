# New ports collection makefile for:	trueprint
# Date created:			17 February 2000
# Whom:				Dmitry Sivachenko <dima@Chg.RU>
#
# $FreeBSD$
#

PORTNAME=	trueprint
PORTVERSION=	5.2
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	trueprint

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Print program listings on postscript printer

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

# Doesn't configure on bento because of this
.if !exists(/usr/bin/lpr) || !exists(/usr/bin/lp)
IGNORE=		"missing /usr/bin/lp or /usr/bin/lpr (hi bento)"
.endif

MAN1=		trueprint.1

.include <bsd.port.mk>
