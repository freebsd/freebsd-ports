# New ports collection makefile for:	vlc
# Date created:		3rd August 2001
# Whom:			Brian Somers <brian@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vlc
PORTVERSION=	0.4.4
CATEGORIES=	graphics
MASTER_SITES=	http://www.videolan.org/pub/videolan/vlc/${PORTVERSION}/ \
		ftp://ftp.Awfulhak.org/pub/vlc/ \
		http://people.FreeBSD.org/~brian/vlc/

MAINTAINER=	brian@FreeBSD.org

LIB_DEPENDS=	dvdcss.2:${PORTSDIR}/multimedia/libdvdcss \
		dvdread.2:${PORTSDIR}/multimedia/libdvdread

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PATH_GTKCONFIG="${GTK_CONFIG}"
CONFIGURE_ARGS+=--with-dvdcss=${LOCALBASE} \
		--with-dvdread=${LOCALBASE} \
		--includedir="${LOCALBASE}/include" \
		--libdir="${LOCALBASE}/lib"

USE_GNOMENG=	yes
USE_GNOME=	gtk12
USE_GMAKE=	yes

.include <bsd.port.mk>
