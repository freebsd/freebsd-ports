# New ports collection makefile for:	groonga
# Date created:		17 Nov 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	groonga
PORTVERSION=	1.1.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://groonga.org/files/groonga/
MASTER_SITE_SUBDIR=	kuriyama

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Open-source fulltext search engine and column store

LICENSE=	LGPL21
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	pkgconfig

OPTIONS=	MECAB	"use mecab for morphological analysis" on

MAN1=	groonga.1

.include <bsd.port.pre.mk>

.if defined(WITH_MECAB) || exists(${LOCALBASE}/lib/libmecab.so)
CONFIGURE_ARGS+=	--with-mecab
LIB_DEPENDS+=	mecab:${PORTSDIR}/japanese/mecab
PLIST_SUB+=	MECAB=""
.else
CONFIGURE_ARGS+=	--without-mecab
PLIST_SUB+=	MECAB="@comment "
.endif

.include <bsd.port.post.mk>
