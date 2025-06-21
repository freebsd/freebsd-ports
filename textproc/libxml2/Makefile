PORTNAME=	libxml2
DISTVERSION=	2.11.9
PORTREVISION?=	1
CATEGORIES?=	textproc gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

PATCH_SITES=	https://gitlab.gnome.org/GNOME/${PORTNAME}/-/commit/
PATCHFILES+=	245b70d7d2768572ae1b05b3668ca858b9ec4ed4.patch:-p1 # CVE-2024-56171
PATCHFILES+=	858ca26c0689161a6b903a6682cc8a1cc10a0ea8.patch:-p1 # CVE-2025-24928
PATCHFILES+=	d7657811964eac1cb9743bb98649278ad948f0d2.patch:-p1 # CVE-2025-32414

MAINTAINER=	desktop@FreeBSD.org
COMMENT?=	XML parser library for GNOME
WWW=		http://xmlsoft.org/

LICENSE=	MIT

USES+=		cmake:testing cpe iconv localbase:ldflags pathfix \
		pkgconfig tar:xz
CPE_VENDOR=	xmlsoft
USE_LDCONFIG=	yes
# Don't build with Python support unless requested
CMAKE_${LIBXML2_SLAVE:DON:UOFF}=LIBXML2_WITH_PYTHON

# Many symbols in the linker version script libxml2.syms are only defined when
# --with-xptr-locs is enabled at configure time. Suppress errors with lld >= 17
# due to these undefined symbols.
LDFLAGS+=	-Wl,--undefined-version

CMAKE_TESTING_ON=	LIBXML2_WITH_TESTS

CMAKE_ARGS=	-DCMAKE_INSTALL_SYSCONFDIR=share
CMAKE_OFF+=	LIBXML2_WITH_TESTS

PLIST_SUB+=	LIBVERSION=${DISTVERSION}

OPTIONS_DEFINE=	DOCS ICU MEM_DEBUG READLINE THREAD_ALLOC
OPTIONS_DEFAULT=	READLINE
OPTIONS_SUB=		yes

MEM_DEBUG_DESC=		Memory debugging (DEVELOPERS ONLY!)
READLINE_DESC=		History for xmllint
THREAD_ALLOC_DESC=	Per-thread memory (DEVELOPERS ONLY!)

ICU_LIB_DEPENDS=		libicudata.so:devel/icu
ICU_CMAKE_BOOL=			LIBXML2_WITH_ICU
MEM_DEBUG_CONFIGURE_WITH=	LIBXML2_WITH_MEM_DEBUG
READLINE_LIB_DEPENDS=		libreadline.so:devel/readline
READLINE_CMAKE_OFF=		-DHAVE_LIBHISTORY=false \
				-DHAVE_LIBREADLINE=false
THREAD_ALLOC_CMAKE_BOOL=	LIBXML2_WITH_THREAD_ALLOC

post-patch:
	@${REINPLACE_CMD} -e \
		's|/etc/xml/catalog|${LOCALBASE}/share/xml/catalog|g; \
		 s|/etc/sgml/catalog|${LOCALBASE}/share/sgml/catalog|g' \
		${WRKSRC}/doc/xmllint.1

post-install:
.if defined(LIBXML2_SLAVE)
	${STRIP_CMD} ${STAGEDIR}${PYTHON_LIBDIR}/site-packages/libxml2mod.so
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-f -d ${PYTHONPREFIX_SITELIBDIR} \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-f -d ${PYTHONPREFIX_SITELIBDIR} \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
.endif

.include <bsd.port.mk>
