# New ports collection makefile for:	clucene-contrib
# Date created:				2010-10-4
# Whom:					Tom Judge <tom@tomjudge.com>
#
# $FreeBSD$
#

PORTNAME=	clucene-contrib
PORTVERSION=	0.9.16a
CATEGORIES=	textproc
MASTER_SITES=	SF/clucene/clucene-contribs-unstable/${PORTVERSION}

MAINTAINER=	tom@tomjudge.com
COMMENT=	CLucene Contrib Code and Tools

LIB_DEPENDS=	clucene.0:${PORTSDIR}/textproc/clucene
BUILD_DEPENDS=	${LOCALBASE}/include/iconv.h:${PORTSDIR}/converters/libiconv

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
USE_DOS2UNIX=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_ASCII_SUPPORT)
CONFIGURE_ARGS+=	--enable-ascii
.endif

.include <bsd.port.post.mk>
