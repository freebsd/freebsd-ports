# New ports collection makefile for:	libxml2
# Date created:				28 September 1998
# Whom:					Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#
# WITH_THREADS_BREAK enable pthread support (WILL BREAK OTHER PORTS!)
# WITHOUT_SCHEMA disable XML schema support
# WITH_MEM_DEBUG enable memory debugging (DEVELOPERS ONLY!)
# WITH_XMLLINT_HIST enable history for xmllint
# WITH_THREAD_ALLOC enable per-thread memory (DEVELOPERS ONLY!)
#

PORTNAME=	libxml2
PORTVERSION=	2.7.4
PORTREVISION?=	1
CATEGORIES?=	textproc gnome
MASTER_SITES=	ftp://fr.rpmfind.net/pub/libxml/ \
		ftp://gd.tuwien.ac.at/pub/libxml/ \
		ftp://xmlsoft.org/libxml2/
DIST_SUBDIR=	gnome2

MAINTAINER?=	gnome@FreeBSD.org
COMMENT?=	XML parser library for GNOME

.if !defined(REFERENCE_PORT)

USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes
USE_GNOME?=	gnomehack gnometarget pkgconfig
USE_LDCONFIG=	yes
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

.if defined(WITH_THREADS_BREAK)
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
.for d in . doc doc/devhelp doc/examples
	@${REINPLACE_CMD} -e '/^install-data-am:/ s|install-data-local||' \
		${WRKSRC}/${d}/Makefile.in
.endfor
.for f in catalog.c xmlcatalog.c xmllint.c doc/xmllint.1
	@${REINPLACE_CMD} -e \
		's|/etc/xml/catalog|${LOCALBASE}/share/xml/catalog|g; \
		 s|/etc/sgml/catalog|${LOCALBASE}/share/sgml/catalog|g' ${WRKSRC}/${f}
.endfor

.include <bsd.port.mk>

.endif
