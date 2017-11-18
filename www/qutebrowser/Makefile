# $FreeBSD$

PORTNAME=	qutebrowser
DISTVERSION=	1.0.3
CATEGORIES=	www

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Keyboard-focused browser with a minimal GUI

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=0:devel/py-attrs \
		${PYTHON_PKGNAMEPREFIX}pygments>=0:textproc/py-pygments \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2 \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml \
		${PYTHON_PKGNAMEPREFIX}pyPEG2>=0:textproc/py3-pyPEG2

USES=		python:3.5+ pyqt:5
USE_PYQT=	core opengl printsupport sql webkit webkitwidgets widgets qml
USE_QT5=	sql-sqlite3
USE_PYTHON=	distutils autoplist
USE_GITHUB=	yes
GH_TAGNAME=	v${DISTVERSION}

.include <bsd.port.mk>
