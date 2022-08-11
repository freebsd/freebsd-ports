PORTNAME=	ggobi
PORTVERSION=	2.1.11
PORTREVISION=	4
CATEGORIES=	math graphics
MASTER_SITES=	http://www.ggobi.org/downloads/

MAINTAINER=	rhurlin@FreeBSD.org
COMMENT=	Data visualization system

LICENSE=	EPL

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libcgraph.so:graphics/graphviz \
		libltdl.so:devel/libltdl

USES=		desktop-file-utils gnome libtool pathfix pkgconfig tar:bzip2
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk20 libxml2
USE_GCC=	yes
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-all-plugins

SUB_FILES=	pkg-message

ALL_TARGET=	all ggobirc
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS

post-build:
	@${REINPLACE_CMD} -e 's|plugin.la|plugin.so|g' ${WRKSRC}/ggobirc

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/xdg/ggobi
	${INSTALL_DATA} ${WRKSRC}/ggobirc ${STAGEDIR}${PREFIX}/etc/xdg/ggobi/ggobirc.sample

.include <bsd.port.mk>
