# New ports collection makefile for:	searchmonkey
# Date created:		26 August 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	searchmonkey
PORTVERSION=	0.7.4
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Search using regexes for file names and text

USE_GNOME=	gtk20
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libintl-prefix=${LOCALBASE}
CONFIGURE_ENV=	CPPFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"
PLIST_FILES=	bin/${PORTNAME} share/pixmaps/${PORTNAME}-32x32.png
CFLAGS=	-I${LOCALBASE}/include
LDFLAGS=-L${LOCALBASE}/lib

.include <bsd.port.mk>
