# New ports collection makefile for:	xsearch
# Date created:		26 August 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xsearch
PORTVERSION=	0.3
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Search using regexes for file names and text

USE_GNOME=	gtk20
USE_GCC=	3.3+
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libintl-prefix=${LOCALBASE}
PLIST_FILES=	bin/xsearch

.include <bsd.port.mk>
