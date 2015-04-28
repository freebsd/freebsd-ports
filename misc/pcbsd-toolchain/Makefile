# New ports collection makefile for:	pcbsd-toolchain
# $FreeBSD$

PORTNAME=	pcbsd-toolchain
PORTVERSION=	1.2
CATEGORIES=	misc
MASTER_SITES=
DISTFILES=

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	PC-BSD Development Utilities

RUN_DEPENDS=	sphinx-build:${PORTSDIR}/textproc/py-sphinx \
		py27-sphinx-intl>=0:${PORTSDIR}/textproc/py-sphinx-intl \
		py27-sphinx-httpdomain>=0:${PORTSDIR}/textproc/py-sphinxcontrib-httpdomain \
		tex-formats>=0:${PORTSDIR}/print/tex-formats \
		tex-dvipsk>=0:${PORTSDIR}/print/tex-dvipsk

USE_QT5=	core dbus designer graphicaleffects gui imageformats multimedia \
		network printsupport svg webkit widgets x11extras xml linguist qmake

NO_BUILD=	yes
NO_MTREE=	yes

do-install:
	${DO_NADA}

.include <bsd.port.mk>
