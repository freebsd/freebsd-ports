PORTNAME=	qalculate-gtk
PORTVERSION=	4.2.0
CATEGORIES=	math
MASTER_SITES=	https://github.com/Qalculate/${PORTNAME}/releases/download/v${PORTVERSION}/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Multi-purpose desktop calculator (GTK+3 frontend)

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libqalculate.so:math/libqalculate \
		libharfbuzz.so:print/harfbuzz
RUN_DEPENDS=	gnuplot:math/gnuplot

USES=		compiler:c++11-lang gettext gmake gnome \
		libtool:build localbase pkgconfig
USE_GNOME=	cairo gdkpixbuf2 gtk30 intltool libxml2

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

post-patch-NLS-off:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s|po ||g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
