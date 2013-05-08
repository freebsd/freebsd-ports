# Created by: Oliver Lehmann (oliver@FreeBSD.org)
# $FreeBSD$
#

PORTNAME=	xfce4-dict
PORTVERSION=	0.6.0
PORTREVISION=	8
CATEGORIES=	textproc xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/apps/${PORTNAME}/${PORTVERSION:R}
PKGNAMESUFFIX=	-plugin
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce Plugin for searching for the translation or explanation of a word

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USES=		gettext pkgconfig
USE_GMAKE=	yes
USE_GNOME=	gtk20 intltool intlhack
USE_XFCE=	configenv libgui libutil panel
USE_XORG=	x11

MAN1=		xfce4-dict.1

.include <bsd.port.mk>
