# Created by: Vsevolod Stakhov <vsevolod@FreeBSD.org>
# $FreeBSD$

PORTNAME=	aspcud
PORTVERSION=	1.9.4
DISTVERSIONPREFIX=     v
PORTREVISION=	3
CATEGORIES=	math ports-mgmt sysutils

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Advanced solver for package dependencies

LICENSE=	GPLv3

BUILD_DEPENDS=	re2c:devel/re2c
LIB_DEPENDS=	libboost_thread.so:devel/boost-libs
RUN_DEPENDS=	gringo:math/gringo \
		clasp:math/clasp \
		bash:shells/bash

USES=		compiler:c++11-lang cmake python:run
USE_GITHUB=	yes
GH_ACCOUNT=	potassco

CMAKE_ARGS+=	-DCMAKE_INSTALL_MANDIR=${MANPREFIX}/man

.include <bsd.port.mk>
