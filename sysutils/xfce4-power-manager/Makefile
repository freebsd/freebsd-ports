# New ports collection makefile for:	xfce4-power-manager
# Date created:		2009-06-20
# Whom:			J.R. Oldroyd <fbsd@opal.com>
#
# $FreeBSD$
#

PORTNAME=	xfce4-power-manager
PORTVERSION=	1.0.10
PORTREVISION=	1
CATEGORIES=	sysutils xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/xfce/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce4 power manager

LIB_DEPENDS=	notify.4:${PORTSDIR}/devel/libnotify

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20 intltool intlhack pkgconfig
USE_XFCE=	configenv libutil libgui panel
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--disable-network-manager \
		--enable-polkit

MAN1=		xfce4-power-manager.1 xfce4-power-manager-settings.1

post-patch:
	@${REINPLACE_CMD} -e 's|--libs "libxfce4panel-1.0"|& "libxfcegui4-1.0"|g; \
		s|--cflags "libxfce4panel-1.0"|& "libxfcegui4-1.0"|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
