# New ports collection makefile for:	mc
# Version required:	4.5.40
# Date created:		15 Jul 1995
# Whom:			torstenb@FreeBSD.org
#
# $FreeBSD$
#

DISTNAME=	mc-4.5.40
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/mc

MAINTAINER=	reg@shale.csir.co.za

LIB_DEPENDS=	glib12.3:${PORTSDIR}/devel/glib12 \
		intl.1:${PORTSDIR}/devel/gettext

.if defined(USE_NCURSES_PORT)
LIB_DEPENDS+=	ncurses.4:${PORTSDIR}/devel/ncurses
.endif

GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ncurses --without-gnome --without-edit
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		MAKE="gmake" \
		GLIB_CONFIG="${GLIB_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		midc.1
MAN8=		mcserv.8

.include <bsd.port.mk>
