PORTNAME=	qutebrowser
DISTVERSION=	3.6.1
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

FLAVORS=	qt6 qt5
FLAVOR?=	${FLAVORS:[1]}

USES=		cpe desktop-file-utils python
USE_PYQT=	webengine
USE_PYTHON=	autoplist noflavors pep517

qt5_PKGNAMESUFFIX=	-qt5
qt5_CONFLICTS_INSTALL=	${PORTNAME}

qt6_CONFLICTS_INSTALL=	${PORTNAME}-qt5

.if ${FLAVOR:U} == "qt5"
USES+=		pyqt:5 qt:5
USE_PYQT+=	pyqt5
USE_QT=		sql-sqlite3
.else
USES+=		pyqt:6 qt:6
USE_PYQT+=	pyqt6
USE_QT=		base declarative quick3d sqldriver-sqlite:run webengine \
		websockets tools:build
.endif

# Upstream archive contains files with UTF-8 names
EXTRACT_CMD=	${SETENV} LC_ALL=en_US.UTF-8 ${TAR}
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
