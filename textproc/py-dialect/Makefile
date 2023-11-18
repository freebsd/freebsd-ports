PORTNAME=	dialect
DISTVERSION=	2.2.0
CATEGORIES=	textproc gnome python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Translation app for GNOME
WWW=		https://github.com/dialect-app/dialect

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	appstream-util:devel/appstream-glib \
		blueprint-compiler:devel/blueprint-compiler
LIB_DEPENDS=	libsoup-3.0.so:devel/libsoup3
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gTTS>0:audio/py-gtts@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>0:www/py-beautifulsoup@${PY_FLAVOR}

USES=		desktop-file-utils gettext-tools gnome gstreamer meson \
		pkgconfig python

USE_GITHUB=	yes
GH_ACCOUNT=	dialect-app
GH_TUPLE=	dialect-app:po:9155653c4493730508989617d8bf86980e6029ae:po/po

USE_GNOME=	glib20 gtk40 introspection:build libadwaita pygobject3
GLIB_SCHEMAS=	app.drey.Dialect.gschema.xml

# workaround to avoid filesystem violations during poudriere build
MAKE_ENV+=	PYTHONDONTWRITEBYTECODE=1

NO_ARCH=	yes

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e 's/python3/${PYTHON_VERSION}/' ${WRKSRC}/meson.build

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
