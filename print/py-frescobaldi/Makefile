PORTNAME=	frescobaldi
DISTVERSION=	4.0.7
CATEGORIES=	print kde python
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/v${DISTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	m.ne@gmx.net
COMMENT=	Music score editor for lilypond
WWW=		https://www.frescobaldi.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tox>0:devel/py-tox@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-ly>=0:print/py-python-ly@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qpageview>=0:graphics/py-qpageview@${PY_FLAVOR}

USES=		gettext-tools pyqt:6 python qt:6
USE_PYQT=	pyqt6 sip:build
USE_PYTHON=	autoplist noflavors pep517

NO_ARCH=	yes

OPTIONS_DEFINE=		WEBENGINE
OPTIONS_DEFAULT_aarch64=	WEBENGINE
OPTIONS_DEFAULT_amd64=		WEBENGINE
OPTIONS_DEFAULT_armv7=		WEBENGINE
OPTIONS_DEFAULT_i386=		WEBENGINE
OPTIONS_DEFAULT_powerpc64le=	WEBENGINE

WEBENGINE_DESC=		Documentation browser and SVG view (requires QtWebEngine)
WEBENGINE_USE=		PYQT=webengine

post-build:
	(cd ${WRKSRC} && tox -e linux-generate)

.include <bsd.port.mk>
