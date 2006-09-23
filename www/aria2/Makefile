# New ports collection makefile for:	aria2
# Date created:		1 May 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aria2
DISTVERSION=	0.8.0
CATEGORIES=	www
MASTER_SITES=	SF

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Yet another download tool

CONFIGURE_ARGS=	--with-libintl-prefix=${LOCALBASE} --with-openssl \
		--with-libxml2 --without-gnutls --without-libares --without-libcares

USE_GCC=	3.4+
USE_BZIP2=	yes
USE_GNOME=	gnomehack libxml2
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
PLIST_FILES=	bin/aria2c \
		share/locale/de/LC_MESSAGES/aria2c.mo \
		share/locale/ja/LC_MESSAGES/aria2c.mo \
		share/locale/ru/LC_MESSAGES/aria2c.mo

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	Does not build on 4.x
.endif

.include <bsd.port.post.mk>
