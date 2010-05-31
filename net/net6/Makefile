# Ports collection makefile for:	net6
# Date created:				2005-10-14
# Whom:					Andreas Kohn <andreas@syndrom23.de>
#
# $FreeBSD$
#

PORTNAME=	net6
PORTVERSION=	1.3.12
PORTREVISION=	1
CATEGORIES=	net devel
MASTER_SITES=	http://releases.0x539.de/net6/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Network access framework for IPv4/IPv6

LIB_DEPENDS=	sigc-2.0.0:${PORTSDIR}/devel/libsigc++20 \
		gnutls.40:${PORTSDIR}/security/gnutls

USE_GNOME=	gnomehack pkgconfig
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
.endif

.include <bsd.port.mk>
