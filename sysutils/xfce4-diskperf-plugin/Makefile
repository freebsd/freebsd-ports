# Created by: Danilo Egea Gondolfo <danilogondolfo@gmail.com>
# $FreeBSD$

PORTNAME=	xfce4-diskperf-plugin
PORTVERSION=	2.6.0
CATEGORIES=	sysutils xfce
MASTER_SITES=	XFCE/src/panel-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Graphical representation of the disk IO

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip
USES=		gettext-tools gmake libtool pkgconfig tar:bzip2 xfce:gtk3
USE_GNOME=	gtk30 intltool cairo
USE_XFCE=	panel

LIBS+=		-ldevstat

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext-runtime

.include <bsd.port.options.mk>

post-patch:
.if empty(PORT_OPTIONS:MNLS)
	@${REINPLACE_CMD} -e 's|[[:blank:]]po||' \
		-e 's|po$$||'  ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
