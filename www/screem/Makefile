# New ports collection makefile for:	SCREEM
# Version required:	0.1.92
# Date created:		05 Nov 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

DISTNAME=	screem-0.1.92
CATEGORIES=	www
MASTER_SITES=	http://www.screem.org/src/

MAINTAINER=	andrews@technologist.com

LIB_DEPENDS=	glade.3:${PORTSDIR}/devel/libglade \
		pthread.13:${PORTSDIR}/devel/pth-devel

LIBGLADE_CONFIG?=	${LOCALBASE}/bin/libglade-config
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
CONFIGURE_ENV=	GTK_CONFIG="${X11BASE}/bin/gtk12-config"
CONFIGURE_ARGS=	--with-gnome=${PREFIX}/include --prefix=${PREFIX} \
		--with-gtk-exec-prefix=${PREFIX} --with-gtk=${PREFIX} \
		--with-libglade-config=${LIBGLADE_CONFIG} \
		--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share --libdir=${PREFIX}/share

.include <bsd.port.mk>
