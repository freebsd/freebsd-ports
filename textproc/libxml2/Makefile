# New ports collection makefile for:	libxml2
# Date created:				28 September 1998
# Whom:					Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#
# WITH_THREADS enable pthread support (WILL BREAK OTHER PORTS!)
# WITHOUT_SCHEMA disable XML schema support
# WITH_MEM_DEBUG enable memory debugging (DEVELOPERS ONLY!)
# WITH_XMLLINT_HIST enable history for xmllint
# WITH_THREAD_ALLOC enable per-thread memory (DEVELOPERS ONLY!)
#

PORTNAME=	libxml2
PORTVERSION=	2.6.19
CATEGORIES?=	textproc gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.6
DIST_SUBDIR=	gnome2

MAINTAINER?=	gnome@FreeBSD.org
COMMENT?=	XML parser library for GNOME

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
USE_LIBTOOL_VER=15
USE_GNOME?=	gnomehack gnometarget pkgconfig
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes
CONFIGURE_ARGS?= --with-iconv=${LOCALBASE} \
		--with-html-dir=${PREFIX}/share/doc \
		--with-html-subdir=${PORTNAME} \
		--without-python
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.if !defined(MASTERDIR)
MAN1=		xml2-config.1 xmllint.1 xmlcatalog.1
MAN3=		libxml.3
.endif

.if defined(WITH_THREADS)
CONFIGURE_ARGS+=	--with-threads
.else
CONFIGURE_ARGS+=	--without-threads
.endif

.if defined(WITHOUT_SCHEMA)
CONFIGURE_ARGS+=	--without-schemas
.endif

.if defined(WITH_MEM_DEBUG)
CONFIGURE_ARGS+=	--with-mem-debug
.endif

.if defined(WITH_XMLLINT_HIST)
CONFIGURE_ARGS+=	--with-history
.endif

.if defined(WITH_THREAD_ALLOC)
CONFIGURE_ARGS+=	--with-thread-alloc
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/catalog.c ${WRKSRC}/xmlcatalog.c

.include <bsd.port.mk>
