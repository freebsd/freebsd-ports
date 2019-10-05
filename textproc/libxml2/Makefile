# Created by: Yukihiro Nakai <Nakai@technologist.com>
# $FreeBSD$

PORTNAME=	libxml2
PORTVERSION=	2.9.9
PORTREVISION?=	0
CATEGORIES?=	textproc gnome
MASTER_SITES=	http://xmlsoft.org/sources/
DIST_SUBDIR=	gnome2

MAINTAINER?=	gnome@FreeBSD.org
COMMENT?=	XML parser library for GNOME

.if !defined(REFERENCE_PORT)

LICENSE=	MIT TRIO
LICENSE_COMB=	multi
LICENSE_NAME_TRIO=	Trio License
LICENSE_FILE_MIT=	${WRKSRC}/COPYING
LICENSE_FILE_TRIO=	${FILESDIR}/LICENSE.TRIO
LICENSE_PERMS_TRIO=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

GNU_CONFIGURE=	yes
USES+=		compiler cpe gmake iconv libtool pathfix pkgconfig shebangfix
CPE_VENDOR=	xmlsoft
USE_LDCONFIG=	yes
CONFIGURE_ARGS?=--with-iconv=${ICONV_PREFIX} \
		--with-html-dir=${PREFIX}/share/doc \
		--with-html-subdir=${PORTNAME} \
		--without-icu \
		--with-lzma=/usr \
		--without-python
INSTALL_TARGET=	install-strip
SHEBANG_FILES=	*.py */*.py */*/*.py

PLIST_SUB+=	LIBVERSION=${PORTVERSION}

.if !defined(MASTERDIR)

OPTIONS_DEFINE=	SCHEMA VALID THREADS MEM_DEBUG XMLLINT_HIST THREAD_ALLOC
OPTIONS_DEFAULT=SCHEMA VALID THREADS
SCHEMA_DESC=	XML schema support
SCHEMA_CONFIGURE_WITH=	schemas
VALID_DESC=	Validation support
VALID_CONFIGURE_OFF=	--without-valid
THREADS_DESC=	Threads support
THREADS_CONFIGURE_WITH=	threads
MEM_DEBUG_DESC=	Memory debugging (DEVELOPERS ONLY!)
MEM_DEBUG_CONFIGURE_WITH=	mem-debug
XMLLINT_HIST_DESC=	History for xmllint
XMLLINT_HIST_CONFIGURE_WITH=	history
THREAD_ALLOC_DESC=	Per-thread memory (DEVELOPERS ONLY!)
THREAD_ALLOC_CONFIGURE_WITH=	thread-alloc

.endif # !defined(MASTERDIR)

.if !defined(MASTERDIR)
post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/share/gtk-doc
.endif

.include <bsd.port.pre.mk>

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
.if ${CHOSEN_COMPILER_TYPE} == gcc
	@${REINPLACE_CMD} -e 's/ -Wno-array-bounds//' ${WRKSRC}/configure
.endif

.include <bsd.port.post.mk>

.endif
