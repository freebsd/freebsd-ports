# New ports collection makefile for:	cheese
# Date created:				13 January 2008
# Whom:					FreeBSD GNOME Team <gnome@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/multimedia/cheese/Makefile,v 1.9 2008/03/10 21:10:13 mezz Exp $
#

PORTNAME=	cheese
PORTVERSION=	2.22.3
CATEGORIES=	multimedia gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A Photobooth-inspired app for taking pictures and videos from webcam

USE_XORG=	xxf86vm
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget intlhack evolutiondataserver \
		librsvg2 gnomedocutils
USE_GETTEXT=	yes
USE_GSTREAMER=	good
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

DOCS=		AUTHORS COPYING ChangeLog NEWS README
GCONF_SCHEMAS=	cheese.schemas

.ifndef (NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
