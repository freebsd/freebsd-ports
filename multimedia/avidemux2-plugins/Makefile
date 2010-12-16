# New ports collection makefile for:    avidemux2
# Date created:         16 April 2003
# Whom:                 Anish Mistry
#                       with help from mean
# $FreeBSD$
#

PORTNAME=	avidemux2
PORTVERSION=	${AVIDEMUX2_VERSION}
PORTREVISION=	2
CATEGORIES=	multimedia
PKGNAMESUFFIX=	-plugins

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Simple GUI based video editor (Plugins)

BUILD_DEPENDS=	avidemux2_cli:${PORTSDIR}/multimedia/avidemux2
RUN_DEPENDS=	avidemux2_cli:${PORTSDIR}/multimedia/avidemux2

MASTERDIR=	${.CURDIR}/../avidemux2
PLIST=		${.CURDIR}/pkg-plist

.include "${MASTERDIR}/Makefile.common"

CMAKE_ARGS+=	-DAVIDEMUX_SOURCE_DIR=${WRKSRC} -DAVIDEMUX_INSTALL_PREFIX:PATH="${CMAKE_INSTALL_PREFIX}" -DAVIDEMUX_CORECONFIG_DIR=${CONFIGURE_WRKSRC}/config

post-configure: post-configure-common
	@${MKDIR} ${WRKDIR}/.build-plugins
	@cd ${WRKDIR}/.build-plugins && ${SETENV} ${CMAKE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} ${WRKSRC}/plugins

do-build:
	@cd ${WRKDIR}/.build-plugins && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS} ${ALL_TARGET}

do-install:
	@(cd ${WRKDIR}/.build-plugins && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})

.include <bsd.port.post.mk>
