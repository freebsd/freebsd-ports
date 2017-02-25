# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xfce4-netload-plugin
PORTVERSION=	1.3.1
CATEGORIES=	sysutils xfce
MASTER_SITES=	XFCE/src/panel-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Network Load plugin for Xfce4

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USE_GNOME=	gtk30 intltool cairo
USE_XFCE=	panel
USES=		gettext-tools gmake libtool pkgconfig tar:bzip2 xfce:gtk3
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext-runtime

post-patch:
	@${REINPLACE_CMD} -e 's, || __FreeBSD_kernel__,,' \
		${WRKSRC}/panel-plugin/net.c \
		${WRKSRC}/panel-plugin/net.h \
		${WRKSRC}/panel-plugin/os.h

post-patch-NLS-off:
	${REINPLACE_CMD} -e 's|po ||' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
