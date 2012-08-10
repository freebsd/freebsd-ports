# New ports collection makefile for:	vertx
# Date created:		2012-08-08
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vertx
PORTVERSION=	1.2.3
#PORTREVISION=	0
CATEGORIES=	www
MASTER_SITES=	http://vertx.io/downloads/
DISTNAME=	vert.x-${PORTVERSION}.final

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Effortless asynchronous application development for the modern web

LICENSE=	AL2

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

JAVA_OS=	native
JAVA_RUN=	yes
JAVA_VERSION=	1.7+

NO_BUILD=	yes

REINPLACE_ARGS=	-i '' -E \
		-e 's,^\#!/bin/bash$$,\#!/usr/bin/env bash,1' \
		-e '/APP_BASE_NAME=/a \${SED_APPEND_ARGS}' \
		-e 's,(pattern=)%t,\1%h,1'

SED_APPEND_ARGS=	${nl}JAVA_HOME=${JAVA_HOME}

USE_JAVA=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES JYTHON JRUBY

JYTHON_DESC=	Use Python to write verticles
JRUBY_DESC=	Use Ruby to write verticles

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJYTHON}
SED_APPEND_ARGS+=	\${nl}JYTHON_HOME=${LOCALBASE}/lib/jython
REINPLACE_ARGS+=	-e 's,-Djruby.home=,-Dpython.cachedir=$${HOME}/.jython-cachedir &,1'
RUN_DEPENDS+=	jython:${PORTSDIR}/lang/jython
.endif

.if ${PORT_OPTIONS:MJRUBY}
PKGMESSAGE=	${PKGDIR}/pkg-message.jruby
RUN_DEPENDS+=	jruby:${PORTSDIR}/lang/jruby
SED_APPEND_ARGS+=	\${nl}JRUBY_HOME=${LOCALBASE}/share/jruby
.endif

nl=	${.newline}

post-patch:
	@${FIND} ${WRKSRC} -type f \( -name "*.bat" -o -name "*.orig" \) -delete
	@${REINPLACE_CMD} ${WRKSRC}/bin/${PORTNAME} ${WRKSRC}/conf/logging.properties

do-install:
	${MKDIR} ${DATADIR}
.for d in client conf lib
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${DATADIR}
.endfor
	${MKDIR} ${DATADIR}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${PORTNAME} ${DATADIR}/bin/${PORTNAME}
	${LN} -s ${DATADIR}/bin/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
.if ${PORT_OPTIONS:MDOCS}
	cd ${WRKSRC}/api-docs && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
.endif
.if ${PORT_OPTIONS:MJRUBY}
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
