# Created by: Yukihiro Nakai <Nakai@technologist.com>
# $FreeBSD$
#    $MCom: ports/trunk/textproc/libxml2/Makefile 18920 2013-11-24 09:21:11Z kwm $

PORTNAME=	libxml2
PORTVERSION=	2.9.1
PORTREVISION?=	0
CATEGORIES?=	textproc gnome
MASTER_SITES=	ftp://xmlsoft.org/libxml2/ \
		http://xmlsoft.org/sources/ \
		ftp://gd.tuwien.ac.at/pub/libxml/
DIST_SUBDIR=	gnome2

MAINTAINER?=	gnome@FreeBSD.org
COMMENT?=	XML parser library for GNOME

.if !defined(REFERENCE_PORT)

GNU_CONFIGURE=	yes
USES=		gmake iconv pathfix pkgconfig shebangfix
USE_GNOME+=	ltverhack
USE_LDCONFIG=	yes
CONFIGURE_ARGS?=--with-iconv=${ICONVBASE} \
		--with-html-dir=${PREFIX}/share/doc \
		--with-html-subdir=${PORTNAME} \
		--with-lzma=/usr \
		--without-python
SHEBANG_FILES=	*.py */*.py */*/*.py

.if !defined(MASTERDIR)

OPTIONS_DEFINE= SCHEMA THREADS MEM_DEBUG XMLLINT_HIST THREAD_ALLOC
OPTIONS_DEFAULT=SCHEMA THREADS
SCHEMA_DESC=	XML schema support
THREADS_DESC=	Threads support
MEM_DEBUG_DESC= Memory debugging (DEVELOPERS ONLY!)
XMLLINT_HIST_DESC= History for xmllint
THREAD_ALLOC_DESC= Per-thread memory (DEVELOPERS ONLY!)

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MSCHEMA}
CONFIGURE_ARGS+=	--without-schemas
.endif

.if ! ${PORT_OPTIONS:MTHREADS}
CONFIGURE_ARGS+=	--without-threads
.endif

.if ${PORT_OPTIONS:MMEM_DEBUG}
CONFIGURE_ARGS+=	--with-mem-debug
.endif

.if ${PORT_OPTIONS:MXMLLINT_HIST}
CONFIGURE_ARGS+=	--with-history
.endif

.if ${PORT_OPTIONS:MTHREAD_ALLOC}
CONFIGURE_ARGS+=	--with-thread-alloc
.endif
.endif # !defined(MASTERDIR)

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

.if !defined(MASTERDIR)
post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libxml2.so.2
.endif

.include <bsd.port.mk>

.endif
