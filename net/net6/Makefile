# Ports collection makefile for:	net6
# Date created:				2005-10-14
# Whom:					Andreas Kohn <andreas@syndrom23.de>
#
# $FreeBSD$
#

PORTNAME=	net6
PORTVERSION=	1.1.0
CATEGORIES=	net devel
MASTER_SITES=	http://releases.0x539.de/net6/

MAINTAINER=	andreas@syndrom23.de
COMMENT=	Network access framework for IPv4/IPv6

LIB_DEPENDS=	sigc++-2.0.0:${PORTSDIR}/devel/libsigc++20

INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=15
USE_GNOME=	gnomehack

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
PLIST_SUB=	NLS=""
.else
CONFIGURE_ARGS=	--disable-nls
PLIST_SUB=	NLS="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		does not build on FreeBSD 4.x
.endif

.include <bsd.port.post.mk>
