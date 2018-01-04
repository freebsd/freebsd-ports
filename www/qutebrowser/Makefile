# $FreeBSD$

PORTNAME=	qutebrowser
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.4
CATEGORIES=	www

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Keyboard-focused browser with a minimal GUI

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=0:devel/py-attrs@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>=0:devel/py-colorama@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cssutils>=0:www/py-cssutils@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}MarkupSafe>=0:textproc/py-MarkupSafe@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=0:textproc/py-pygments@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyPEG2>=0:textproc/py-pyPEG2@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sip>=0:devel/py-sip@${FLAVOR}

NO_ARCH=	yes
USES=		python:3.5+ pyqt:5
USE_PYQT=	core opengl printsupport sql webkit webkitwidgets widgets qml
USE_QT5=	sql-sqlite3
USE_PYTHON=	distutils autoplist optsuffix
USE_GITHUB=	yes

.include <bsd.port.mk>
