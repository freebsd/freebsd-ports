PORTNAME=	xfce4-diskperf-plugin
PORTVERSION=	2.7.0
PORTREVISION=	3
CATEGORIES=	sysutils xfce
MASTER_SITES=	XFCE/panel-plugins
DIST_SUBDIR=	xfce4

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Graphical representation of the disk IO
WWW=		https://goodies.xfce.org/projects/panel-plugins/xfce4-diskperf-plugin

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz

USES=		compiler:c11 gettext-tools gnome gmake libtool pkgconfig \
		tar:bzip2 xfce
USE_GNOME=	cairo gdkpixbuf2 gtk30 intltool
USE_XFCE=	libmenu panel

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

LIBS+=		-ldevstat

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext-runtime

post-patch-NLS-off:
	@${REINPLACE_CMD} -e 's|[[:blank:]]po||' \
		-e 's|po$$||'  ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
