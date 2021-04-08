# Created by: Nikola Lecic <nikola.lecic@anthesphoria.net>

PORTNAME=	ibus-m17n
DISTVERSION=	1.4.5
CATEGORIES=	textproc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	m17n IM engine for IBus framework

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libibus-1.0.so:textproc/ibus \
		libm17n.so:devel/m17n-lib \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig
RUN_DEPENDS=	ibus-daemon:textproc/ibus

PORTSCOUT=	limit:^[0-9]+\.[0-9].*$$

USES=		autoreconf gmake gnome libtool pkgconfig
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	ibus
USE_GNOME=	glib20 gtk20 atk gdkpixbuf2 cairo pango intltool

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/m17n|$${pkgdatadir}|g' \
		${WRKSRC}/src/m17n.xml.in*

.include <bsd.port.mk>
