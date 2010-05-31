# New ports collection makefile for:	trueprint
# Date created:			17 February 2000
# Whom:				Dmitry Sivachenko <dima@Chg.RU>
#
# $FreeBSD$
#

PORTNAME=	trueprint
PORTVERSION=	5.3
PORTREVISION=	2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	trueprint

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Print program listings on postscript printer

USE_GMAKE=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS}" LDFLAGS="-L${LOCALBASE}/lib -lintl"

MAN1=		trueprint.1
INFO=		trueprint

PLIST_FILES=	bin/trueprint

.include <bsd.port.mk>
