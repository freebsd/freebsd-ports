# New ports collection makefile for:	bfilter
# Date created:				10.05.2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	bfilter
PORTVERSION=	0.9.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Smart filtering HTTP proxy

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt \
		tre.4:${PORTSDIR}/textproc/libtre \
		sigc-1.2.5:${PORTSDIR}/devel/libsigc++12

USE_SIZE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if defined(WITH_GUI)
USE_GNOME=	gtk20 pkgconfig
LIB_DEPENDS=	gtkmm-2.0:${PORTSDIR}/x11-toolkits/gtk--2
CONFIGURE_ARGS+=	--with-gui
PLIST_SUB+=	WITH_GUI=""
.else
PLIST_SUB+=	WITH_GUI="@comment "
.endif

.include <bsd.port.mk>
