# ex:ts=8
# Ports collection makefile for:	gretl
# Date created:			Mar 22, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gretl
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gnu Regression, Econometrics and Time-series Library

BUILD_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot
LIB_DEPENDS=	gmp.6:${PORTSDIR}/math/libgmp4 \
BUILD_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot

USE_X_PREFIX=	yes
USE_GNOME=	gtk20 libxml2
USE_GMAKE=	yes
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
USE_GNOME+=	gnomeprefix libgnomeprintui libgnomeui
PLIST_SUB+=	GNOME2:="" DATADIR="share/gnome"
.endif

.include <bsd.port.mk>
