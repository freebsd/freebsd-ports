# New ports collection makefile for:	gtk-murrine-engine
# Date created:		2006-08-20
# Whom:			Phillip Neumann <pneumann@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	gtk-murrine-engine
PORTVERSION=	0.13
CATEGORIES=	x11-themes
MASTER_SITES=	http://cimi.netsons.org/media/download_gallery/murrie/
DISTNAME=	murrine-${PORTVERSION}

MAINTAINER=	pneumann@gmail.com
COMMENT=	Murrine GTK+ 2.x cairo based engine

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gtk-engines-2.pc:${PORTSDIR}/x11-themes/gtk-engines2
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gtk-engines-2.pc:${PORTSDIR}/x11-themes/gtk-engines2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-animation
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_GNOME=	gtk20
FETCH_CMD=	/usr/bin/fetch
USE_LDCONFIG=	yes

.include <bsd.port.mk>
