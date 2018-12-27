# Created by: martin.dieringer@gmx.de
# $FreeBSD$

PORTNAME=	frescobaldi
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.0
CATEGORIES=	print kde

MAINTAINER=	m.ne@gmx.net
COMMENT=	Music score editor for lilypond

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-poppler-qt5>=0:graphics/py-python-poppler-qt5@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-ly>=0:print/py-python-ly@${PY_FLAVOR}

USES=		gettext pyqt:5 python:3.4+ qmake qt:5 desktop-file-utils
USE_PYQT=	network printsupport sip svg webkit webkitwidgets widgets
USE_PYTHON=	distutils autoplist noflavors
USE_GITHUB=	yes
GH_ACCOUNT=	wbsoft

NO_ARCH=	yes

OPTIONS_DEFINE=	LILYPOND

LILYPOND_DESC=	Use unstable LilyPond (lilypond-devel)

LILYPOND_RUN_DEPENDS=		lilypond:print/lilypond-devel
LILYPOND_RUN_DEPENDS_OFF=	lilypond:print/lilypond

post-patch:
	@${REINPLACE_CMD} -e 's|'share/man/man1'|'man/man1'|' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
