# New ports collection makefile for:	mc
# Version required:	4.5.9
# Date created:		15 Jul 1995
# Whom:			torstenb@FreeBSD.ORG
#
# $Id: Makefile,v 1.26 1998/12/07 08:50:59 obrien Exp $
#

DISTNAME=	mc-4.5.9
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	mc

MAINTAINER=	reg@shale.csir.co.za

BUILD_DEPENDS=	gettext:${PORTSDIR}/devel/gettext
RUN_DEPENDS=	gettext:${PORTSDIR}/devel/gettext
LIB_DEPENDS=	glib11d.2:${PORTSDIR}/devel/glib11-devel

.if defined(USE_NCURSES_PORT)
LIB_DEPENDS+=	ncurses.4:${PORTSDIR}/devel/ncurses
.endif

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ncurses --without-gnome --without-edit
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		MAKE="gmake" \
		GLIB_CONFIG="${LOCALBASE}/bin/glib11d-config" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		midc.1
MAN8=		mcserv.8

.include <bsd.port.mk>
