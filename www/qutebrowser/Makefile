PORTNAME=	qutebrowser
DISTVERSION=	3.7.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	PYPI

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Keyboard-focused browser with a minimal GUI
WWW=		https://www.qutebrowser.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}colorama>=0:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markupsafe>=0:textproc/py-markupsafe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR}

USES=		cpe desktop-file-utils python pyqt:6 qt:6
USE_PYTHON=	autoplist noflavors pep517
USE_PYQT=	webengine pyqt6
USE_QT=		base declarative quick3d sqldriver-sqlite:run webengine \
		websockets tools:build

NO_ARCH=	yes
PLIST_FILES=	share/applications/${PORTNAME}-${PYTHON_VER}.desktop \
		share/man/man1/${PORTNAME}.1.gz

OPTIONS_DEFINE_amd64=	ADBLOCK
OPTIONS_DEFAULT_amd64=	ADBLOCK

ADBLOCK_DESC=	Enable the newer adblocking support

ADBLOCK_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}adblock>=0.4.2:www/py-adblock@${PY_FLAVOR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/misc/org.qutebrowser.qutebrowser.desktop \
		${STAGEDIR}${PREFIX}/share/applications/${PORTNAME}-${PYTHON_VER}.desktop

	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
