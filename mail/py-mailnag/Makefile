PORTNAME=	mailnag
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.0
CATEGORIES=	mail python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Extensible mail notification daemon

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libnotify.so:devel/libnotify \
		libsecret-1.so:security/libsecret
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setproctitle>0:devel/py-setproctitle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xdg>0:devel/py-xdg@${PY_FLAVOR}

USES=		desktop-file-utils gettext-tools gnome python:3.5+ shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	pulb

USE_GNOME=	gdkpixbuf2 glib20 gtk30 pygobject3
USE_GSTREAMER1=	yes
USE_PYTHON=	autoplist distutils

SHEBANG_FILES=	mailnag mailnag-config
SHEBANG_GLOB=	*.py

NO_ARCH=	yes

PORTDOCS=	AUTHORS NEWS README.md

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e 's|/usr/bin|${PREFIX}/bin|' \
		${WRKSRC}/data/mailnag-config.desktop \
		${WRKSRC}/data/mailnag.desktop

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
