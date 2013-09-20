# Created by: CHOI Junho <cjh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qdecoder
PORTVERSION=	12.0.4
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/
DISTNAME=	qDecoder-${PORTVERSION}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	C/C++ language library including CGI supports

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAKE_ARGS=	exec_prefix="${PREFIX}"
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	DEBUG
PORTEXAMPLES=	*

PLIST_FILES=	include/qdecoder.h \
		lib/libqdecoder.a \
		lib/libqdecoder.so \
		lib/libqdecoder.so.12

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+="--enable-debug"
.endif

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} "Makefile *.c *.html" ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
