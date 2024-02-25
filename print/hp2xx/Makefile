PORTNAME=	hp2xx
PORTVERSION=	3.4.4
PORTREVISION=	9
CATEGORIES=	print x11
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	HPGL to vector and raster formats converter and previewer for X11
WWW=		https://www.gnu.org/software/hp2xx/

LICENSE=	GPLv2+

LIB_DEPENDS=	libpng.so:graphics/png \
		libtiff.so:graphics/tiff

USES=		jpeg localbase:ldflags

MAKE_ENV=	DEFINES="${CPPFLAGS}" ALL_LIBS="${LDFLAGS}"

CPPFLAGS+=	-DUNIX
LDFLAGS+=	-lm -ltiff -lpng -lz

WRKSRC_SUBDIR=	sources

PLIST_FILES=	bin/hp2xx share/man/man1/hp2xx.1.gz

OPTIONS_DEFINE=		INFO X11
OPTIONS_DEFAULT=	INFO X11

INFO_USES=		makeinfo
INFO_MAKE_ARGS=	infodir=${PREFIX}/${INFO_PATH}
INFO_INFO=		hp2xx
X11_USES=		xorg
X11_USE=		XORG=x11
X11_MAKE_ENV=		PREVIEWER=to_x11
X11_MAKE_ENV_OFF=	PREVIEWER=no_prev
X11_CPPFLAGS=		-DHAS_UNIX_X11
X11_LDFLAGS=		-lX11

post-patch-INFO-off:
	@${REINPLACE_CMD} -e '/^all:/s|hp2xx.info||g; \
		/^install:/s|install-info||g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
