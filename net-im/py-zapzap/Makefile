PORTNAME=	zapzap
DISTVERSION=	6.3
CATEGORIES=	net-im python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	WhatsApp desktop application written in PyQt6
WWW=		https://rtosta.com/zapzap/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=63.1.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.45.1:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=1.3.2:devel/py-dbus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-gettext>=3.0:textproc/py-python-gettext@${PY_FLAVOR}

USES=		desktop-file-utils pyqt:6 python
USE_GITHUB=	yes
GH_ACCOUNT=	rafatosta
USE_PYQT=	webengine
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

PLIST_FILES=	share/applications/com.rtosta.zapzap.desktop \
		share/icons/hicolor/scalable/apps/com.rtosta.zapzap.svg

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/share/icons/com.rtosta.zapzap.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${MKDIR} ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/share/applications/com.rtosta.zapzap.desktop \
		${STAGEDIR}${PREFIX}/share/applications

.include <bsd.port.mk>
