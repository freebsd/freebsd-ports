# Created by: Yukihiro Nakai <Nakai@technologist.com>

PORTNAME=	libxml2
DISTVERSION=	2.9.13
PORTREVISION?=	1
CATEGORIES?=	textproc gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${DISTVERSION:R}/
DIST_SUBDIR=	gnome2

MAINTAINER=	desktop@FreeBSD.org
COMMENT?=	XML parser library for GNOME

LICENSE=	MIT

USES+=		cmake cpe iconv localbase:ldflags pkgconfig tar:xz

CPE_VENDOR=	xmlsoft
USE_LDCONFIG=	yes

PLIST_SUB+=	LIBVERSION=${DISTVERSION}

# Don't build with Python support unless requested
CMAKE_${LIBXML2_SLAVE:DON:UOFF}=LIBXML2_WITH_PYTHON

OPTIONS_DEFINE=		DOCS ICU MEM_DEBUG READLINE TEST THREAD_ALLOC
OPTIONS_DEFAULT=	ICU READLINE
OPTIONS_SUB=		yes

MEM_DEBUG_DESC=		Memory debugging (DEVELOPERS ONLY!)
THREAD_ALLOC_DESC=	Per-thread memory (DEVELOPERS ONLY!)
READLINE_DESC=		History for xmllint

DOCS_EXTRA_PATCHES_OFF=	${PATCHDIR}/extra-patch-docs
ICU_LIB_DEPENDS=	libicudata.so:devel/icu
ICU_CMAKE_BOOL=		LIBXML2_WITH_ICU
MEM_DEBUG_CAKE_BOOL=	LIBXML2_WITH_MEM_DEBUG
READLINE_LIB_DEPENDS=	libreadline.so:devel/readline
READLINE_CMAKE_OFF=	-DHAVE_LIBHISTORY=false -DHAVE_LIBREADLINE=false
THREAD_ALLOC_CMAKE_BOOL=LIBXML2_WITH_THREAD_ALLOC
TEST_CMAKE_BOOL=	LIBXML2_WITH_TESTS
TEST_TEST_TARGET=	test

post-patch:
.for f in catalog.c xmlcatalog.c xmllint.c doc/xmllint.1
	@${REINPLACE_CMD} -e \
		's|/etc/xml/catalog|${LOCALBASE}/share/xml/catalog|g; \
		 s|/etc/sgml/catalog|${LOCALBASE}/share/sgml/catalog|g' \
		${WRKSRC}/${f}
.endfor

.if !defined(LIBXML2_SLAVE)
post-install:
	${RM} ${STAGEDIR}${DOCSDIR}/xmlcatalog.1
	${RM} ${STAGEDIR}${DOCSDIR}/xmllint.1.bak
	${RM} ${STAGEDIR}${DOCSDIR}/xmllint.1
	${RLN} ${STAGEDIR}${PREFIX}/lib/libxml2.so.${DISTVERSION} ${STAGEDIR}${PREFIX}/lib/libxml2.so.2
	${INSTALL_DATA} ${WRKSRC}/libxml.m4 ${STAGEDIR}${PREFIX}/share/aclocal/libxml.m4
.endif

.include <bsd.port.mk>
