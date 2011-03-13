# New ports collection makefile for:	wmavgload
# Date created:		20 July 1998
# Whom:			Vladimir Kushnir <kushn@mail.kar.net>
#
# $FreeBSD$
#

PORTNAME=	wmavgload
PORTVERSION=	0.7.0
PORTREVISION=	1
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	${MASTER_SITE_WINDOWMAKER}
MASTER_SITE_SUBDIR=	contrib/old/srcs/utils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Another WindowMaker load gauge

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

USE_IMAKE=	yes
USE_XORG=	xpm
ALL_TARGET=	wmavgload
NO_INSTALL_MANPAGES=	yes

PLIST_FILES=	bin/wmavgload

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmavgload ${PREFIX}/bin

.include <bsd.port.mk>
