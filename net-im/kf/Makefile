# New ports collection makefile for:	kf
# Date created:		Tue Oct 19 01:48:30 UTC 2004
# Whom:			Andrey Slusar <anray@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kf
PORTVERSION=	0.5.4.1
PORTREVISION=	8
CATEGORIES=	net-im
MASTER_SITES=	http://files.jabberstudio.org/kf/ \
		http://jabberstudio.rediris.es/kf/ \
		http://freebsd.unixfreunde.de/sources/

MAINTAINER=	anray@FreeBSD.org
COMMENT=	A simple Jabber client using the GTK+ 2.0 toolkit

LIB_DEPENDS=	loudmouth-1.0:${PORTSDIR}/net-im/loudmouth

USE_XORG=	x11 xscrnsaver
USE_GNOME=	libglade2
GNU_CONFIGURE=	yes

CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

OPTIONS=GTKSPELL "Spell checking support" on \
	NLS "Native Language Support" on

.include <bsd.port.pre.mk>

.ifndef(WITHOUT_GTKSPELL)
LIB_DEPENDS+=	gtkspell.0:${PORTSDIR}/textproc/gtkspell
CONFIGURE_ARGS+=	--enable-gtkspell
.endif

.ifndef(WITHOUT_NLS)
USE_GETTEXT=		yes
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB=		NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB=		NLS="@comment "
.endif

.include <bsd.port.post.mk>
