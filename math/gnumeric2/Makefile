# New ports collection makefile for:	gnumeric
# Version required:			0.18
# Date created:				08 October 1998
# Whom:					Yukihiro Nakai <Nakai@technologist.com>
#
# $Id: Makefile,v 1.9 1999/03/26 04:48:08 nectar Exp $
#

DISTNAME=	gnumeric-0.18
CATEGORIES=	math gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnumeric

MAINTAINER=	nacai@iname.com

BUILD_DEPENDS=	panel:${PORTSDIR}/x11/gnomecore \
		python:${PORTSDIR}/lang/python
RUN_DEPENDS=	panel:${PORTSDIR}/x11/gnomecore \
		python:${PORTSDIR}/lang/python
LIB_DEPENDS=	xml.0:${PORTSDIR}/textproc/libxml

# implicit dependencies:
# gettext, xpm, gtk12, guile, gnomelibs

USE_X_PREFIX=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome \
		--with-gnome=${X11BASE} --with-guile
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		GTK_CONFIG="${X11BASE}/bin/gtk12-config" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib -lxpg4"

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
