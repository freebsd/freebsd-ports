# Created by: rokaz
# $FreeBSD$

PORTNAME=	belier
PORTVERSION=	1.2
CATEGORIES=	security net
MASTER_SITES=	http://www.ohmytux.com/belier/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	romain.garbage@gmail.com
COMMENT=	easily cross several machines with ssh

RUN_DEPENDS=	expect>=5.42.1:${PORTSDIR}/lang/expect

PLIST_FILES=	lib/${PYTHON_VERSION}/site-packages/belier/corps.pyo \
		lib/${PYTHON_VERSION}/site-packages/belier/terminal.pyc \
		lib/${PYTHON_VERSION}/site-packages/belier/options.pyo \
		lib/${PYTHON_VERSION}/site-packages/belier/corps.py \
		lib/${PYTHON_VERSION}/site-packages/belier/__init__.pyo \
		lib/${PYTHON_VERSION}/site-packages/belier/optionstunnel.pyc \
		lib/${PYTHON_VERSION}/site-packages/belier/terminal.py \
		lib/${PYTHON_VERSION}/site-packages/belier/__init__.py \
		lib/${PYTHON_VERSION}/site-packages/belier/corps.pyc \
		lib/${PYTHON_VERSION}/site-packages/belier/optionstunnel.py \
		lib/${PYTHON_VERSION}/site-packages/belier/terminal.pyo \
		lib/${PYTHON_VERSION}/site-packages/belier/options.pyc \
		lib/${PYTHON_VERSION}/site-packages/belier/__init__.pyc \
		lib/${PYTHON_VERSION}/site-packages/belier/options.py \
		lib/${PYTHON_VERSION}/site-packages/belier/optionstunnel.pyo \
		bin/bel \
		share/locale/fr/LC_MESSAGES/bel.mo
PLIST_DIRS=	lib/${PYTHON_VERSION}/site-packages/belier

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
