# New ports collection makefile for:	aria2
# Date created:		1 May 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aria2
DISTVERSION=	0.10.2
CATEGORIES=	www
MASTER_SITES=	SFE

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Yet another download tool

#CPPFLAGS=	-g
#DONTSTRIP=	yes
#CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}"
#MAKE_ENV=	DONTSTRIP=
CONFIGURE_ARGS=	--with-libintl-prefix=${LOCALBASE} --mandir=${MANPREFIX}/man --with-openssl \
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
MAN1=		aria2c.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	Does not build on 4.x
.endif

.include <bsd.port.post.mk>
