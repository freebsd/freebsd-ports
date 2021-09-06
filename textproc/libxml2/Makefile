# Created by: Yukihiro Nakai <Nakai@technologist.com>

PORTNAME=	libxml2
DISTVERSION=	2.9.12
PORTREVISION?=	0
CATEGORIES?=	textproc gnome
MASTER_SITES=	http://xmlsoft.org/sources/
DIST_SUBDIR=	gnome2

MAINTAINER?=	desktop@FreeBSD.org
COMMENT?=	XML parser library for GNOME

LICENSE=	MIT TRIO
LICENSE_COMB=	multi
LICENSE_NAME_TRIO=	Trio License
LICENSE_FILE_MIT=	${WRKSRC}/COPYING
LICENSE_FILE_TRIO=	${FILESDIR}/LICENSE.TRIO
LICENSE_PERMS_TRIO=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES+=		compiler cpe iconv libtool pathfix pkgconfig shebangfix
GNU_CONFIGURE=	yes
CPE_VENDOR=	xmlsoft
SHEBANG_FILES=	*.py */*.py */*/*.py
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

CONFIGURE_ARGS?=--with-iconv=${ICONV_PREFIX} \
		--with-html-dir=${PREFIX}/share/doc \
		--with-html-subdir=${PORTNAME} \
		--without-icu \
		--with-lzma=/usr \
		--without-python

PLIST_SUB+=	LIBVERSION=${DISTVERSION}

.if !defined(MASTERDIR)

OPTIONS_DEFINE=		MEM_DEBUG SCHEMA THREAD_ALLOC THREADS VALIDATION \
			XMLLINT_HIST
OPTIONS_DEFAULT=	SCHEMA VALIDATION THREADS

MEM_DEBUG_DESC=		Memory debugging (DEVELOPERS ONLY!)
SCHEMA_DESC=		XML schema support
THREAD_ALLOC_DESC=	Per-thread memory (DEVELOPERS ONLY!)
VALIDATION_DESC=	Validation support
XMLLINT_HIST_DESC=	History for xmllint

MEM_DEBUG_CONFIGURE_WITH=	mem-debug
SCHEMA_CONFIGURE_WITH=		schemas
THREAD_ALLOC_CONFIGURE_WITH=	thread-alloc
THREADS_CONFIGURE_WITH=		threads
VALIDATION_CONFIGURE_OFF=	--without-valid
XMLLINT_HIST_CONFIGURE_WITH=	history

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
