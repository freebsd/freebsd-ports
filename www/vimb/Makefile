PORTNAME=	vimb
DISTVERSION=	4.0.0
CATEGORIES=	www

MAINTAINER=	mce@FreeBSD.org
COMMENT=	Vim like browser
WWW=		https://fanglingsu.github.io/vimb/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsoup-3.0.so:devel/libsoup3 \
		libwebkitgtk-6.0.so:www/webkit2-gtk@60

USES=		desktop-file-utils gmake gnome pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	fanglingsu
USE_GNOME=	glib20 gtk40

MAKE_ARGS=	V=1
LDFLAGS+=	-Wl,--as-needed

PLIST_FILES=	bin/vimb \
		lib/vimb/webext_main.so \
		share/applications/vimb.desktop \
		share/man/man1/vimb.1.gz \
		share/metainfo/vimb.metainfo.xml

OPTIONS_DEFINE=	GSTREAMER
GSTREAMER_USES=	gstreamer
GSTREAMER_USE=	GSTREAMER=good,libav

# Create version.h before building to eliminate the need for MAKE_JOBS_UNSAFE=yes.
post-patch:
	${ECHO_CMD} "#define VERSION \"${DISTVERSION}\"" > ${WRKSRC}/version.h

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/vimb \
		${STAGEDIR}${PREFIX}/lib/vimb/webext_main.so

.include <bsd.port.mk>
