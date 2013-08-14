# Created by: Max Brazhnikov <makc@FreeBSD.org>
# $FreeBSD$

PORTNAME=	oxygen
PORTVERSION=	1.1.4
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTNAME}-gtk3/${PORTVERSION}/src/
PKGNAMEPREFIX=	gtk3-
PKGNAMESUFFIX=	-engine
DISTNAME=	${PORTNAME}-gtk3-${PORTVERSION}

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	Oxygen GTK+ 3 engine and theme

LICENSE=	LGPL21

LIB_DEPENDS=	cairo:${PORTSDIR}/graphics/cairo \
		dbus-glib-1:${PORTSDIR}/devel/dbus-glib

USE_BZIP2=	yes
USE_GNOME=	gtk30
USES=		cmake:outsource pkgconfig

.include <bsd.port.pre.mk>

# FreeBSD SVN r205606 was only MFC'ed to 8.1+, so we need to match
# the old function signature on previous versions.
.if ${OSVERSION} < 801000
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-demo-oxygengtkdeco_main.cpp
.endif

.include <bsd.port.post.mk>
