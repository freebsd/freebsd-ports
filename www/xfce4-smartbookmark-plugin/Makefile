# Created by: Martin Wilke (miwi@FreeBSD.org)
# $FreeBSD$

PORTNAME=	xfce4-smartbookmark-plugin
PORTVERSION=	0.4.5
PORTREVISION=	1
CATEGORIES=	www xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/panel-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Query search engines from the Xfce panel

LICENSE=	GPLv2

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 intltool intlhack
USES=		pkgconfig gettext gmake
USE_XFCE=	configenv libexo libmenu libutil panel
USE_XORG=	ice

.include <bsd.port.mk>
