# New ports collection makefile for:	bfilter
# Date created:				10.05.2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	bfilter
PORTVERSION=	0.10.3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Smart filtering HTTP proxy

LIB_DEPENDS=	ACE.5:${PORTSDIR}/devel/ace \
		sigc-2.0.0:${PORTSDIR}/devel/libsigc++20

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_RC_SUBR=	bfilter.sh

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if defined(WITH_GUI)
USE_GNOME=	gtk20 pkgconfig
LIB_DEPENDS+=	gtkmm-2.0:${PORTSDIR}/x11-toolkits/gtk--2
CONFIGURE_ARGS+=	--with-gui
PLIST_SUB+=	WITH_GUI=""
.else
PLIST_SUB+=	WITH_GUI="@comment "
.endif

.include <bsd.port.mk>
