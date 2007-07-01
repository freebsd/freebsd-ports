# Ports collection makefile for:	net6
# Date created:				2005-10-14
# Whom:					Andreas Kohn <andreas@syndrom23.de>
#
# $FreeBSD$
#

PORTNAME=	net6
PORTVERSION=	1.3.5
PORTREVISION=	1
CATEGORIES=	net devel
MASTER_SITES=	http://releases.0x539.de/net6/ \
		http://www.atarininja.org/~wxs/distfiles/

MAINTAINER=	wxs@atarininja.org
COMMENT=	Network access framework for IPv4/IPv6

LIB_DEPENDS=	sigc-2.0.0:${PORTSDIR}/devel/libsigc++20 \
		gnutls.13:${PORTSDIR}/security/gnutls

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
USE_ICONV=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
PLIST_SUB=	NLS=""
.else
CONFIGURE_ARGS=	--disable-nls
PLIST_SUB=	NLS="@comment "
.endif

.include <bsd.port.mk>
