# New ports collection makefile for:	tracker
# Date created:		2006-12-09
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/sysutils/tracker/Makefile,v 1.2 2006/12/10 17:33:17 ahze Exp $
#

PORTNAME=	tracker
PORTVERSION=	0.5.4
PORTREVISION=	1
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://www.gnome.org/~jamiemcc/tracker/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Object database, tag/metadata database, search tool and indexer

LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		poppler-glib.1:${PORTSDIR}/graphics/poppler-gtk \
		exif.12:${PORTSDIR}/graphics/libexif \
		wv-1.2.3:${PORTSDIR}/textproc/wv \
		gmime-2.0.4:${PORTSDIR}/mail/gmime2

USE_FAM=	yes
WANT_FAM_SYSTEM=gamin
USE_GNOME=	gnomedesktop gnomehack gnomeprefix libgsf
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_GSTREAMER=	core
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--enable-gstreamer \
		--disable-inotify \
		--with-deskbar-applet-handler-dir=${PREFIX}/lib/deskbar-applet/handlers

MAN1=		tracker-extract.1 tracker-files.1 tracker-meta-folder.1 \
		tracker-query.1 tracker-search.1 tracker-stats.1 trackerd.1

post-patch:
	@${REINPLACE_CMD} -e 's|libpng|libpng12|' ${WRKSRC}/configure

.include <bsd.port.mk>
