# New ports collection makefile for:	trueos-toolchain
# $FreeBSD$

PORTNAME=	trueos-toolchain
PORTVERSION=	1.3
CATEGORIES=	misc
MASTER_SITES=
DISTFILES=

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	TrueOS Development Utilities

USES=		python

RUN_DEPENDS=	sphinx-build:${PORTSDIR}/textproc/py-sphinx \
		${PYTHON_PKGNAMEPREFIX}sphinx-intl>=0:${PORTSDIR}/textproc/py-sphinx-intl \
		${PYTHON_PKGNAMEPREFIX}sphinx_rtd_theme>=0:${PORTSDIR}/textproc/py-sphinx_rtd_theme \
		${PYTHON_PKGNAMEPREFIX}sphinx_numfig>=r13:${PORTSDIR}/textproc/py-sphinx_numfig \
		${PYTHON_PKGNAMEPREFIX}sphinx_wikipedia>=0:${PORTSDIR}/textproc/py-sphinx_wikipedia \
		${PYTHON_PKGNAMEPREFIX}alabaster>=0:${PORTSDIR}/textproc/py-alabaster \
		${PYTHON_PKGNAMEPREFIX}sphinxcontrib-httpdomain>=0:${PORTSDIR}/textproc/py-sphinxcontrib-httpdomain \
		tex-formats>=0:${PORTSDIR}/print/tex-formats \
		tex-dvipsk>=0:${PORTSDIR}/print/tex-dvipsk \
		jq>=0:${PORTSDIR}/textproc/jq

USE_QT5=	buildtools concurrent core dbus designer graphicaleffects gui imageformats multimedia \
		network printsupport svg webkit widgets x11extras xml linguist qmake

NO_BUILD=	yes
NO_MTREE=	yes

do-install:
	${DO_NADA}

.include <bsd.port.mk>
