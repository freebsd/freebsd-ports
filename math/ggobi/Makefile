PORTNAME=	ggobi
DISTVERSION=	2.1.12
PORTREVISION=	2
CATEGORIES=	math graphics

MAINTAINER=	rhurlin@FreeBSD.org
COMMENT=	Data visualization system
WWW=		http://www.ggobi.org/

LICENSE=	EPL

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libcgraph.so:graphics/graphviz

USES=		autoreconf desktop-file-utils gettext-tools \
		gmake gnome libtool pathfix pkgconfig tex
USE_GITHUB=	yes
GH_TAGNAME=	93a7148  # The 'official' tarball misses last commit with pstricks removal!
USE_GNOME=	cairo gdkpixbuf glib20 gtk20 libxml2
USE_LDCONFIG=	yes
USE_TEX=	web2c:build dvipdfmx:build

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-all-plugins MAKE=gmake

ALL_TARGET=	all ggobirc
INSTALL_TARGET=	install-strip

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

post-build:
	@${REINPLACE_CMD} -e 's|plugin.la|plugin.so|g' ${WRKSRC}/ggobirc

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/xdg/ggobi
	${INSTALL_DATA} ${WRKSRC}/ggobirc ${STAGEDIR}${PREFIX}/etc/xdg/ggobi/ggobirc.sample

.include <bsd.port.mk>
