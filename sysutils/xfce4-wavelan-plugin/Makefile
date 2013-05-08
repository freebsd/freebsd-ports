# Created by: Manuel Rabade Garica <mig@mig-29.net>
# $FreeBSD$
#    $MCom: ports/sysutils/xfce4-wavelan-plugin/Makefile,v 1.1 2006/10/02 20:43:59 ahze Exp $

PORTNAME=	xfce4-wavelan-plugin
PORTVERSION=	0.5.4
PORTREVISION=	18
CATEGORIES=	sysutils xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=/src/panel-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Displays various information about a WaveLAN device

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png

GNU_CONFIGURE=	yes
USES=		gettext pkgconfig
USE_GMAKE=	yes
USE_GNOME=	gtk20 intltool intlhack
USE_XFCE=	configenv libutil libgui panel

post-patch:
	@${REINPLACE_CMD} -e 's|--libs "libxfce4panel-1.0"|& "libxfcegui4-1.0"|g; \
		s|--cflags "libxfce4panel-1.0"|& "libxfcegui4-1.0"|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
