# Created by: Vsevolod Stakhov <vsevolod@FreeBSD.org>
# $FreeBSD$

PORTNAME=	aspcud
PORTVERSION=	1.9.0
DISTVERSIONSUFFIX=	-source
CATEGORIES=	math ports-mgmt sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	potassco/${PORTNAME}/${PORTVERSION}

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Advanced solver for package dependencies

LICENSE=	GPLv3

BUILD_DEPENDS=	re2c:${PORTSDIR}/devel/re2c
LIB_DEPENDS=	libboost_thread.so:${PORTSDIR}/devel/boost-libs
RUN_DEPENDS=	gringo:${PORTSDIR}/math/gringo \
				clasp:${PORTSDIR}/math/clasp \
				bash:${PORTSDIR}/shells/bash

USES=	compiler:c++11-lang cmake:outsource python:run

CMAKE_ARGS+=	-DCMAKE_INSTALL_MANDIR=${MANPREFIX}/man

.include <bsd.port.mk>
