# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	glances
PORTVERSION=	1.4.1.1
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	A CLI curses based monitoring tool for GNU/Linux and BSD OS

LICENSE=	LGPL3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=2.0.0:${PORTSDIR}/devel/py-Jinja2 \
		${PYTHON_PKGNAMEPREFIX}psutil>=0.4.1:${PORTSDIR}/sysutils/py-psutil

USE_GITHUB=	yes
GH_ACCOUNT=	nicolargo
GH_PROJECT=	glances
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	2920dcc
USE_PYTHON=	2.6+
USE_PYDISTUTILS=easy_install
PYDISTUTILS_PKGNAME=	Glances

PLIST_FILES=	bin/glances \
		%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

.include <bsd.port.mk>
