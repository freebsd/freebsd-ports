# ex:ts=8
# Ports collection makefile for:	gretl
# Date created:			Mar 22, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gretl
PORTVERSION=	1.0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot
LIB_DEPENDS=	gmp.6:${PORTSDIR}/math/libgmp4 \
		xml2.5:${PORTSDIR}/textproc/libxml2 \
		gtk-x11-2.0.0:${PORTSDIR}/x11-toolkits/gtk20
BUILD_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
GNU_CONFIGURE=	yes
USE_AUTOCONF_VER=	253
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-static --enable-shared --with-gmake
INSTALLS_SHLIB=	yes

MAN1=	gretl.1 gretl-config.1

.if defined(WITHOUT_GNOME2)
CONFIGURE_ARGS+=	--without-gnome
PLIST_SUB+=	GNOME2:="@comment " DATADIR="share"
.else
LIB_DEPENDS+=	gnomeprintui-2.0:${PORTSDIR}/x11-toolkits/libgnomeprintui \
		gnomeui-2.0:${PORTSDIR}/x11-toolkits/libgnomeui
USE_GNOME=	gnomeprefix
PLIST_SUB+=	GNOME2:="" DATADIR="share/gnome"
.endif

.include <bsd.port.mk>
