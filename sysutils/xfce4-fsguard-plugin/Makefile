# Created by: Matt Lancereau <matt@rimasec.net>
# $FreeBSD$

PORTNAME=	xfce4-fsguard-plugin
PORTVERSION=	1.1.0
CATEGORIES=	sysutils xfce
MASTER_SITES=	XFCE/src/panel-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Panel plugin which displays free space of mountpoint

# COPYING file is wrong compared to license header
LICENSE=	BSD2CLAUSE

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip
USES=		gettext-tools gmake libtool pkgconfig tar:bzip2 xfce:gtk3
USE_GNOME=	gtk30 intltool cairo
USE_XFCE=	panel
USE_XORG=	x11

OPTIONS_DEFINE= NLS
NLS_USES=	gettext-runtime
NLS_CONFIGURE_ENABLE=	nls
OPTIONS_SUB=	yes

post-patch-NLS-off:
	@${REINPLACE_CMD} -e 's|	po||' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
