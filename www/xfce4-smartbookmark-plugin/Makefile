# Created by: Martin Wilke (miwi@FreeBSD.org)
# $FreeBSD$

PORTNAME=	xfce4-smartbookmark-plugin
PORTVERSION=	0.5.0
CATEGORIES=	www xfce
MASTER_SITES=	XFCE/src/panel-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Query search engines from the Xfce panel

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USE_GNOME=	gtk30 intltool cairo gdkpixbuf2
USES=		gettext gmake libtool pkgconfig tar:bzip2 xfce:gtk3
USE_XFCE=	panel
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
