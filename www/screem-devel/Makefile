# New ports collection makefile for:	SCREEM
# Date created:		05 Nov 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	screem
PORTVERSION= 	0.2.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.screem.org/src/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	will@FreeBSD.org

LIB_DEPENDS=	glade.3:${PORTSDIR}/devel/libglade

LIBGLADE_CONFIG?=	${LOCALBASE}/bin/libglade-config
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_X_PREFIX=	yes
CONFIGURE_ENV=	GTK_CONFIG="${X11BASE}/bin/gtk12-config"
CONFIGURE_ARGS=	--with-gnome=${PREFIX}/include --prefix=${PREFIX} \
		--with-gtk-exec-prefix=${PREFIX} --with-gtk=${PREFIX} \
		--with-libglade-config=${LIBGLADE_CONFIG} \
		--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share --libdir=${PREFIX}/share

.include <bsd.port.mk>
