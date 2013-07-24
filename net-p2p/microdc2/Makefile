# Created by: Pankov Pavel <pankov_p@mail.ru>
# $FreeBSD$

PORTNAME=	microdc2
PORTVERSION=	0.15.6
PORTREVISION=	4
CATEGORIES=	net-p2p
MASTER_SITES=	http://corsair626.no-ip.org/microdc/ \
		http://corsair626.no-ip.org/microdc/archive/

MAINTAINER=	pankov_p@mail.ru
COMMENT=	Command-line based Direct Connect client

CONFLICTS=	tthsum-[0-9]*

BROKEN=		Does not link

GNU_CONFIGURE=	yes
USES=		iconv
USE_GNOME=	libxml2

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	 NLS="@comment "
.endif

.include <bsd.port.mk>
