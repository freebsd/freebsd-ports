# New ports collection makefile for:   microdc
# Date created:                2006-12-02
# Whom:                        Pankov Pavel <pankov_p@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	microdc2
PORTVERSION=	0.15.6
PORTREVISION=	3
CATEGORIES=	net-p2p
MASTER_SITES=	http://corsair626.no-ip.org/microdc/ \
		http://corsair626.no-ip.org/microdc/archive/

MAINTAINER=	pankov_p@mail.ru
COMMENT=	A command-line based Direct Connect client

GNU_CONFIGURE=	yes
USE_ICONV=	yes
USE_GNOME=	libxml2

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	 NLS="@comment "
.endif

.include <bsd.port.mk>
