# $FreeBSD$

PORTNAME=	qutebrowser
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Keyboard-focused browser with a minimal GUI

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=0:devel/py-attrs \
		${PYTHON_PKGNAMEPREFIX}colorama>=0:devel/py3-colorama \
		${PYTHON_PKGNAMEPREFIX}cssutils>=0:www/py3-cssutils \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2 \
		${PYTHON_PKGNAMEPREFIX}MarkupSafe>=0:textproc/py3-MarkupSafe \
		${PYTHON_PKGNAMEPREFIX}pygments>=0:textproc/py-pygments \
		${PYTHON_PKGNAMEPREFIX}pyPEG2>=0:textproc/py3-pyPEG2 \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml \
		${PYTHON_PKGNAMEPREFIX}sip>=0:devel/py-sip

NO_ARCH=	yes
USES=		python:3.5+ pyqt:5
USE_PYQT=	core opengl printsupport sql webkit webkitwidgets widgets qml
USE_QT5=	sql-sqlite3
USE_PYTHON=	distutils autoplist
USE_GITHUB=	yes

.include <bsd.port.mk>
