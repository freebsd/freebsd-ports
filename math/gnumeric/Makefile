# New ports collection makefile for:	gnumeric
# Version required:			0.26
# Date created:				08 October 1998
# Whom:					Yukihiro Nakai <Nakai@technologist.com>
#
# $Id: Makefile,v 1.11 1999/05/09 17:22:27 steve Exp $
#

DISTNAME=	gnumeric-0.26
CATEGORIES=	math gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnumeric

MAINTAINER=	nacai@iname.com

BUILD_DEPENDS=	panel:${PORTSDIR}/x11/gnomecore \
		python:${PORTSDIR}/lang/python
RUN_DEPENDS=	panel:${PORTSDIR}/x11/gnomecore \
		python:${PORTSDIR}/lang/python
LIB_DEPENDS=	xml.0:${PORTSDIR}/textproc/libxml

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
USE_PERL5=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome \
		--with-gnome=${PREFIX} --with-guile
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
