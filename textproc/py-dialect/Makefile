PORTNAME=	dialect
DISTVERSION=	2.4.2
CATEGORIES=	textproc gnome python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Translation app for GNOME
WWW=		https://github.com/dialect-app/dialect

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	appstreamcli:devel/appstream \
		blueprint-compiler:devel/blueprint-compiler
LIB_DEPENDS=	libsoup-3.0.so:devel/libsoup3 \
		libsecret-1.so:security/libsecret
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gTTS>0:audio/py-gtts@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>0:www/py-beautifulsoup@${PY_FLAVOR}

USES=		desktop-file-utils gettext-tools gnome gstreamer meson \
		pkgconfig python

USE_GITHUB=	yes
GH_ACCOUNT=	dialect-app
GH_TUPLE=	dialect-app:po:dbb487db7eb05b11d8e0fba7a26d1ab5c05ef411:po/po

USE_GNOME=	glib20 gtk40 introspection:build libadwaita pygobject3
GLIB_SCHEMAS=	app.drey.Dialect.gschema.xml

# workaround to avoid filesystem violations during poudriere build
MAKE_ENV+=	PYTHONDONTWRITEBYTECODE=1

NO_ARCH=	yes

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's/python3/${PYTHON_VERSION}/' ${WRKSRC}/meson.build

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31000
IGNORE=		requires Python 3.10+
.endif

.include <bsd.port.post.mk>
