# New ports collection makefile for:    gtk-qt-engine
# Date created:                         23 February 2004
# Whom:                                 Danny Pansters <danny@ricin.com>
#
# $FreeBSD$
#

PORTNAME=	gtk-qt-engine
PORTVERSION=	0.8
PORTREVISION=	8
CATEGORIES=	x11-themes
MASTER_SITES=	http://gtk-qt.ecs.soton.ac.uk/files/${PORTVERSION}/ \
		http://freebsd.ricin.com/ports/distfiles/

MAINTAINER=	danny@ricin.com
COMMENT=	GTK-QT Theme Engine allows GTK2 apps to use QT/KDE themes

BROKEN=		Doesn't build with Glib 2.26.x

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20
USE_QT_VER=	3
USE_KDEBASE_VER=3
HAS_CONFIGURE=	yes
USE_CMAKE=	yes

OPTIONS=	LIBBONOBOUI "Install libbonoboui if missing" off

WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.pre.mk>

.if defined(WITH_LIBBONOBOUI)
USE_GNOME+=	libbonoboui
.endif

.include <bsd.port.post.mk>
