# New ports collection makefile for:	gnumeric
# Version required:			0.51
# Date created:				08 October 1998
# Whom:					Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

DISTNAME=	gnumeric-0.51
CATEGORIES=	math gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/gnumeric

MAINTAINER=	ade@FreeBSD.org

BUILD_DEPENDS=	panel:${PORTSDIR}/x11/gnomecore \
		python:${PORTSDIR}/lang/python
RUN_DEPENDS=	panel:${PORTSDIR}/x11/gnomecore \
		python:${PORTSDIR}/lang/python
LIB_DEPENDS=	gnomeprint.6:${PORTSDIR}/print/gnomeprint \
		glade.3:${PORTSDIR}/devel/libglade

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_PERL5=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome \
		--with-gnome=${PREFIX} --with-guile
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"

PLIST_SUB=	GNUMERIC_REV=${DISTNAME:S/gnumeric-//g}

.include <bsd.port.mk>
