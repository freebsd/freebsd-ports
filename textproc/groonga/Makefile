# New ports collection makefile for:	groonga
# Date created:		17 Nov 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	groonga
PORTVERSION=	1.3.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://packages.groonga.org/source/groonga/
MASTER_SITE_SUBDIR=	kuriyama

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Open-source fulltext search engine and column store

#BUILD_DEPENDS=	sphinx-build:${PORTSDIR}/textproc/py-sphinx

LICENSE=	LGPL21
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	pkgconfig
CONFIGURE_ARGS=	--with-munin-plugins
# We cannot enable this document option until textproc/py-sphinx be upgraded to 1.2.
CONFIGURE_ARGS+=	--disable-document

OPTIONS=	MECAB	"use mecab for morphological analysis" on

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64
.endif

.if defined(WITH_MECAB) || exists(${LOCALBASE}/lib/libmecab.so)
CONFIGURE_ARGS+=	--with-mecab
LIB_DEPENDS+=	mecab:${PORTSDIR}/japanese/mecab
PLIST_SUB+=	MECAB=""
.else
CONFIGURE_ARGS+=	--without-mecab
PLIST_SUB+=	MECAB="@comment "
.endif

.include <bsd.port.post.mk>
