# New ports collection makefile for:	xfce4-power-manager
# Date created:		2009-06-20
# Whom:			J.R. Oldroyd <fbsd@opal.com>
#
# $FreeBSD$
#

PORTNAME=	xfce4-power-manager
PORTVERSION=	0.8.2
PORTREVISION=	6
CATEGORIES=	sysutils xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=/src/apps/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	fbsd@opal.com
COMMENT=	XFce4 power manager

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget gtk20 intltool intlhack pkgconfig
USE_XFCE=	configenv libutil libgui panel

MAN1=		xfce4-power-manager.1 xfce4-power-manager-settings.1

post-patch:
	@${REINPLACE_CMD} -e 's|--libs "libxfce4panel-1.0"|& "libxfcegui4-1.0"|g; \
		s|--cflags "libxfce4panel-1.0"|& "libxfcegui4-1.0"|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
