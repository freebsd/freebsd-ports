PORTNAME=	ibus-m17n
DISTVERSION=	1.4.36
CATEGORIES=	textproc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	m17n IM engine for IBus framework
WWW=		https://github.com/ibus/ibus-m17n

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libibus-1.0.so:textproc/ibus \
		libm17n.so:devel/m17n-lib \
		libharfbuzz.so:print/harfbuzz
RUN_DEPENDS=	ibus-daemon:textproc/ibus

PORTSCOUT=	limit:^[0-9]+\.[0-9].*$$

USES=		autoreconf gmake gnome libtool pkgconfig
USE_GNOME=	glib20 gtk20 gtk30 atk gdkpixbuf cairo pango intltool

USE_GITHUB=	yes
GH_ACCOUNT=	ibus

GNU_CONFIGURE=	yes

GLIB_SCHEMAS=	org.freedesktop.ibus.engine.m17n.gschema.xml

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/m17n|$${pkgdatadir}|g' \
		${WRKSRC}/src/m17n.xml.in*

.include <bsd.port.mk>
