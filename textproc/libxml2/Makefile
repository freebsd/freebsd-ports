# Created by: Yukihiro Nakai <Nakai@technologist.com>
# $FreeBSD$
#    $MCom: ports/trunk/textproc/libxml2/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	libxml2
PORTVERSION=	2.8.0
PORTREVISION?=	3
CATEGORIES?=	textproc gnome
MASTER_SITES=	ftp://xmlsoft.org/libxml2/ \
		http://xmlsoft.org/sources/ \
		ftp://gd.tuwien.ac.at/pub/libxml/
DIST_SUBDIR=	gnome2

MAINTAINER?=	gnome@FreeBSD.org
COMMENT?=	XML parser library for GNOME

NO_STAGE=	yes

.if !defined(REFERENCE_PORT)

GNU_CONFIGURE=	yes
USES=		gmake iconv pathfix pkgconfig
USE_LDCONFIG=	yes
CONFIGURE_ARGS?=--with-iconv=${LOCALBASE} \
		--with-html-dir=${PREFIX}/share/doc \
		--with-html-subdir=${PORTNAME} \
		--with-lzma=/usr \
		--without-python

.if !defined(MASTERDIR)
OPTIONS_DEFINE= SCHEMA THREADS MEM_DEBUG XMLLINT_HIST THREAD_ALLOC
OPTIONS_DEFAULT=SCHEMA THREADS

SCHEMA_DESC=	XML schema support
SCHEMA_CONFIGURE_WITH=	schemas
THREADS_DESC=	Threads support
THREADS_CONFIGURE_WITH=	threads
MEM_DEBUG_DESC= Memory debugging (DEVELOPERS ONLY!)
MEM_DEBUG_CONFIGURE_WITH=	mem-debug
XMLLINT_HIST_DESC= History for xmllint
XMLLINT_HIST_CONFIGURE_WITH=	history
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
	     s|/etc/sgml/catalog|${LOCALBASE}/share/sgml/catalog|g' \
	    ${WRKSRC}/${f}
.endfor
# manual patch because WITH_FBSD10_FIX break the python bindings
	${FIND} ${WRKSRC} -type f -name configure \
		-exec ${SH} -c " \
		mtime=\$$(date -r \$$(stat -f '%m' \$$0) '+%Y%m%d%H%M.%S'); \
		${SED} -i '.batman' -e 's|freebsd1\*)|freebsd1.\*)|g' \
		-e 's|freebsd\[123\]\*)|freebsd[123].*)|g' \$$0; \
		touch -mt \$$mtime \$$0" {} \; || /usr/bin/true

.include <bsd.port.mk>

.endif
