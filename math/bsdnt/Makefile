# $FreeBSD$

PORTNAME=	bsdnt
PORTVERSION=	1.0
CATEGORIES=	math
MASTER_SITES=	GH

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Bignum Library

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	wbhart
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	72e20a7

USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/wbhart-${PORTNAME}-${GH_TAGNAME}

pre-configure:
	@${REINPLACE_CMD} -e "s,#!/bin/bash,#!${LOCALBASE}/bin/bash," ${WRKSRC}/configure

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ./configure --prefix=${STAGEDIR}${PREFIX} CC=cc CXX=c++ AS=cc

.include <bsd.port.mk>
