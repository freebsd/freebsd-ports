# New ports collection makefile for:    qDecoder library
# Date created:         Sep 10 1999
# Whom:                 CHOI Junho <cjh@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qdecoder
PORTVERSION=	12.0.2
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/ \
		ftp://ftp.qdecoder.org/pub/qDecoder/
DISTNAME=	qDecoder-${PORTVERSION}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	C/C++ language library including CGI supports

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAKE_ARGS=	exec_prefix="${PREFIX}"

OPTIONS_DEFINE=	DEBUG

PLIST_FILES=	include/qdecoder.h \
		lib/libqdecoder.a \
		lib/libqdecoder.so \
		lib/libqdecoder.so.12

.include <bsd.port.options.mk>

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+="--enable-debug"
.endif

.include <bsd.port.pre.mk>

.if !defined(NOPORTEXAMPLES)
PORTEXAMPLES=	*
.endif

post-install:
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} "Makefile *.c *.html" ${EXAMPLESDIR})
.endif

.include <bsd.port.post.mk>
