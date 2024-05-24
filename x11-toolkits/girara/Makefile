PORTNAME=	girara
PORTVERSION=	0.4.4
CATEGORIES=	x11-toolkits graphics
MASTER_SITES=	https://pwmt.org/projects/girara/download/

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	GTK3 Interface Library for Zathura PDF Viewer
WWW=		https://pwmt.org/projects/girara/

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c11 gnome meson pathfix pkgconfig tar:xz
PATHFIX_MAKEFILEIN=	Makefile
USE_GNOME=	cairo glib20 gtk30
USE_LDCONFIG=	yes
MESON_ARGS=	-Ddocs=disabled \
		-Dtests=disabled

OPTIONS_DEFINE=	JSON NLS
OPTIONS_SUB=	yes

JSON_DESC=	Support json configuration dump

JSON_LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib
JSON_MESON_ENABLED=	json

NLS_USES=	gettext

post-patch-NLS-off: .SILENT
	${REINPLACE_CMD} -e "/subdir('po')/d" \
		${WRKSRC}/meson.build

.include <bsd.port.mk>
