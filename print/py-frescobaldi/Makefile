PORTNAME=	frescobaldi
DISTVERSION=	4.0.5
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
USE_PYQT=	pyqt6 webengine sip:build
USE_PYTHON=	autoplist noflavors pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	LILYPOND

LILYPOND_DESC=	Use unstable LilyPond (lilypond-devel)

LILYPOND_RUN_DEPENDS=		lilypond:print/lilypond-devel
LILYPOND_RUN_DEPENDS_OFF=	lilypond:print/lilypond

post-build:
	(cd ${WRKSRC} && tox -e linux-generate)

.include <bsd.port.mk>
