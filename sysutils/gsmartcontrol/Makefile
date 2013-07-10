# Created by: Pawel Pekala <c0rn@o2.pl>
# $FreeBSD$

PORTNAME=	gsmartcontrol
PORTVERSION=	0.8.7
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://artificialtime.com/${PORTNAME}/

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Graphical user interface for smartmontools

LIB_DEPENDS=	atkmm-1.6:${PORTSDIR}/accessibility/atkmm \
		glibmm-2.4:${PORTSDIR}/devel/glibmm \
		pthread-stubs:${PORTSDIR}/devel/libpthread-stubs \
		sigc-2.0:${PORTSDIR}/devel/libsigc++20 \
		pcre:${PORTSDIR}/devel/pcre \
		cairo:${PORTSDIR}/graphics/cairo \
		cairomm-1.0:${PORTSDIR}/graphics/cairomm \
		png15:${PORTSDIR}/graphics/png \
		freetype:${PORTSDIR}/print/freetype2 \
		expat:${PORTSDIR}/textproc/expat2 \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig \
		gtkmm-2.4:${PORTSDIR}/x11-toolkits/gtkmm24 \
		pangomm-1.4:${PORTSDIR}/x11-toolkits/pangomm
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		smartctl:${PORTSDIR}/sysutils/smartmontools

USE_AUTOTOOLS=	libtool
USES=		pkgconfig gettext iconv
USE_BZIP2=	yes
USE_GNOME=	gtk20
USE_XORG=	pixman x11 xau xcb xcomposite xcursor xdamage xdmcp xext xfixes \
		xi xinerama xrandr xrender 
INSTALLS_ICONS=	yes

MAN1=		gsmartcontrol.1

CONFIGURE_ARGS=	--disable-libglade

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
.if !${PORT_OPTIONS:MDOCS}
EXTRA_PATCHES+=	${PATCHDIR}/extra-Makefile.in
.endif

.include <bsd.port.mk>
