# Created by: Martin Wilke (miwi@FreeBSD.org)
# $FreeBSD$

PORTNAME=	xfce4-mailwatch-plugin
PORTVERSION=	1.1.0
PORTREVISION=	18
CATEGORIES=	mail xfce
MASTER_SITES=	http://spuriousinterrupt.org/files/mailwatch/ \
		http://freebsd.unixfreunde.de/sources/
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	A mailwatch plugin for Xfce

LIB_DEPENDS=	gnutls.26:${PORTSDIR}/security/gnutls \
		gcrypt:${PORTSDIR}/security/libgcrypt

USE_BZIP2=	yes
INSTALLS_ICONS=	yes
USES=		gettext pathfix gmake pkgconfig
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 intltool intlhack
USE_XFCE=	configenv libgui libutil panel
USE_XORG=	x11 xt xaw

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|--libs "libxfce4panel-1.0"|& "libxfcegui4-1.0"|g; \
		s|--cflags "libxfce4panel-1.0"|& "libxfcegui4-1.0"|g' \
		${WRKSRC}/configure
post-configure:
	@${REINPLACE_CMD} -e 's|-lgnutls|-lgnutls -lgcrypt|g' \
		${WRKSRC}/panel-plugin/Makefile

.include <bsd.port.mk>
