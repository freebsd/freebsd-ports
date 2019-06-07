# Created by: Danilo Egea Gondolfo <danilogondolfo@gmail.com>
# $FreeBSD$

PORTNAME=	xfce4-diskperf-plugin
PORTVERSION=	2.6.1
CATEGORIES=	sysutils xfce
MASTER_SITES=	XFCE/src/panel-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Graphical representation of the disk IO

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gettext-tools gnome gmake libtool pkgconfig tar:bzip2 xfce:gtk3
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip
USE_GNOME=	gtk30 intltool cairo
USE_XFCE=	panel

LIBS+=		-ldevstat

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext-runtime

post-patch-NLS-off:
	@${REINPLACE_CMD} -e 's|[[:blank:]]po||' \
		-e 's|po$$||'  ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
