# New ports collection makefile for:	libquvi-scripts
# Date created:		2011-10-06
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libquvi-scripts
PORTVERSION=	0.4.0
CATEGORIES=	multimedia devel
MASTER_SITES=	SF/quvi/${PORTVERSION:R}/${PORTNAME}/ \
		GOOGLE_CODE

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Embedded lua scripts for libquvi and utility scripts

OPTIONS=	NSFW "Enable adult website support" off

GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack pkgconfig
USE_XZ=		yes

MAN7=		libquvi-scripts.7

PROJECTHOST=	quvi

.include <bsd.port.options.mk>

.if defined(WITH_NSFW)
CONFIGURE_ARGS+=--with-nsfw
PLIST_SUB+=	NSFW=""
.else
PLIST_SUB+=	NSFW="@comment "
.endif

.include <bsd.port.mk>
