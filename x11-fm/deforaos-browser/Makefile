PORTNAME=	deforaos-browser
PORTVERSION=	0.6.0
PORTREVISION=	1
CATEGORIES=	x11-fm
MASTER_SITES=	https://ftp.defora.org/pub/DeforaOS/Apps/Desktop/src/Browser/
DISTNAME=	Browser-${PORTVERSION}

MAINTAINER=	khorben@defora.org
COMMENT=	DeforaOS desktop file browser
WWW=		https://www.defora.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libDesktop.so:x11/deforaos-libdesktop \
		libharfbuzz.so:print/harfbuzz \
		libSystem.so:devel/deforaos-libsystem \
		libXrandr.so:x11/libXrandr

USES=		desktop-file-utils gnome pkgconfig xorg
USE_GNOME=	cairo gdkpixbuf2 gtk30
USE_LDCONFIG=	yes
USE_XORG=	x11

MAKE_ARGS+=	PREFIX=${PREFIX}
MAKE_ENV+= MANDIR=${STAGEDIR}${PREFIX}/share/man

MAKE_ARGS+=	CPPFLAGS+=-DPROGNAME_BROWSER=\\\"deforaos-browser\\\"
MAKE_ARGS+=	CPPFLAGS+=-DPROGNAME_COPY=\\\"deforaos-copy\\\"
MAKE_ARGS+=	CPPFLAGS+=-DPROGNAME_DESKTOP=\\\"deforaos-desktop\\\"
MAKE_ARGS+=	CPPFLAGS+=-DPROGNAME_DESKTOPCTL=\\\"deforaos-desktopctl\\\"
MAKE_ARGS+=	CPPFLAGS+=-DPROGNAME_MOVE=\\\"deforaos-move\\\"
MAKE_ARGS+=	CPPFLAGS+=-DPROGNAME_OPEN=\\\"deforaos-open\\\"
MAKE_ARGS+=	CPPFLAGS+=-DPROGNAME_PROPERTIES=\\\"deforaos-properties\\\"
MAKE_ARGS+=	CPPFLAGS+=-DPROGNAME_VIEW=\\\"deforaos-view\\\"

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes
DOCS_BUILD_DEPENDS=	${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl \
		xsltproc:textproc/libxslt
NLS_USES=	gettext

post-patch:
	${REINPLACE_CMD} -e 's|/lib/|/libdata/|g' \
		${WRKSRC}/data/pkgconfig.sh

post-patch-DOCS-off:
	${REINPLACE_CMD} -e '/^SUBDIRS/ s|doc||' ${WRKSRC}/Makefile

post-patch-NLS-off:
	${REINPLACE_CMD} 's|include po src|include src|' \
		${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/* \
		${STAGEDIR}${PREFIX}/lib/Desktop/widget/browser.so \
		${STAGEDIR}${PREFIX}/lib/Browser/plugins/* \
		${STAGEDIR}${PREFIX}/lib/libBrowser.so.0.0

.include <bsd.port.mk>
