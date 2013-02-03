# Created by: Max Brazhnikov <makc@FreeBSD.org>
# $FreeBSD$

PORTNAME=	oxygen
PORTVERSION=	1.3.2
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTNAME}-gtk2/${PORTVERSION}/src/
PKGNAMEPREFIX=	gtk-
PKGNAMESUFFIX=	-engine
DISTNAME=	${PORTNAME}-gtk2-${PORTVERSION}

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	Oxygen-Gtk engine and theme

LIB_DEPENDS=	cairo:${PORTSDIR}/graphics/cairo \
		dbus-glib-1:${PORTSDIR}/devel/dbus-glib

USE_BZIP2=	yes
USE_GNOME=	gtk20
USE_CMAKE=	yes
USE_PKGCONFIG=	yes
MAKE_JOBS_SAFE=	yes

.include <bsd.port.pre.mk>

# FreeBSD SVN r205606 was only MFC'ed to 8.1+, so we need to match
# the old function signature on previous versions.
.if ${OSVERSION} < 801000
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-demo-oxygengtkdeco_main.cpp
.endif

.include <bsd.port.post.mk>
