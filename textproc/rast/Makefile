# New ports collection makefile for:	rast
# Date created:		Jan 2 2006
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rast
PORTVERSION=	0.3.1
CATEGORIES=	textproc
MASTER_SITES=	http://projects.netlab.jp/rast/archives/ \
		http://dist.bsdlab.org/

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Full-text search system using N-gram

BUILD_DEPENDS=	nkf:${PORTSDIR}/japanese/nkf
LIB_DEPENDS=	apr-1:${PORTSDIR}/devel/apr

USE_BZIP2=	YES
USE_BDB=	42
GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_RUBY=	YES
CONFIGURE_ARGS=	--with-apr-config=${LOCALBASE}/bin/apr-1-config \
	--with-apu-config=${LOCALBASE}/bin/apu-1-config \
	--with-db-includes="-I${BDB_INCLUDE_DIR}" \
	--with-db-libs="-L${BDB_LIB_DIR} -l${BDB_LIB_NAME}" \
	--with-ruby=${LOCALBASE}/bin/ruby \
	--with-default-encoding=${DEFAULT_ENCODING} \
	--with-filter-moduledir=${PREFIX}/lib/rast/filters
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" LDFLAGS="-lz"
INSTALLS_SHLIB=	YES

MAN1=	rast-config.1 rast-create.1 rast-delete.1 rast-optimize.1 \
	rast-register.1 rast-search.1

.if defined(WITH_ICU)
CONFIGURE_ARGS+=	--with-icu-config=${LOCALBASE}/bin/icu-config
BUILD_DEPENDS+=		icu-config:${PORTSDIR}/devel/icu
DEFAULT_ENCODING=	utf8
PLIST_SUB+=		WITH_UTF8=""
.else
CONFIGURE_ARGS+=	--without-icu-config
PLIST_SUB+=		WITH_UTF8="@comment "
.endif

.if defined(WITH_MECAB)
CONFIGURE_ARGS+=	--with-mecab-config=${LOCALBASE}/bin/mecab-config
BUILD_DEPENDS+=		mecab-config:${PORTSDIR}/japanese/mecab
PLIST_SUB+=		WITH_MECAB_EUC_JP=""
.else
CONFIGURE_ARGS+=	--without-mecab-config
PLIST_SUB+=		WITH_MECAB_EUC_JP="@comment "
.endif

.if defined(WITH_XMLRPC_C)
CONFIGURE_ARGS+=	--with-xmlrpc-c-config=${LOCALBASE}/bin/xmlrpc-c-config
BUILD_DEPENDS+=		xmlrpc-c-config:${PORTSDIR}/net/xmlrpc-c
PLIST_SUB+=		WITH_XMLRPC_C=""
MAN1+=			rast_xmlrpc_server_abyss.1
.else
CONFIGURE_ARGS+=	--without-xmlrpc-c-config
PLIST_SUB+=		WITH_XMLRPC_C="@comment "
.endif

.include <bsd.port.pre.mk>

# For 4.x systems.
.if ${OSVERSION} <= 503000
BUILD_DEPENDS+=		${LOCALBASE}/include/magic.h:${PORTSDIR}/sysutils/file
.endif

DEFAULT_ENCODING?=	euc_jp

.include <bsd.port.post.mk>
