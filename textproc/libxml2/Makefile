PORTNAME=	libxml2
DISTVERSION=	2.14.4
PORTREVISION?=	0
CATEGORIES?=	textproc gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

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

CMAKE_TESTING_ON=	LIBXML2_WITH_TESTS

CMAKE_ARGS=	-DCMAKE_INSTALL_SYSCONFDIR=share
CMAKE_OFF+=	LIBXML2_WITH_TESTS
CMAKE_ON+=	LIBXML2_WITH_HTTP \
		LIBXML2_WITH_LZMA \
		LIBXML2_WITH_ZLIB

PLIST_SUB+=	LIBVERSION=${DISTVERSION}

OPTIONS_DEFINE=	DOCS ICU READLINE THREAD_ALLOC
OPTIONS_DEFAULT=	READLINE
OPTIONS_SUB=		yes

READLINE_DESC=		History for xmllint
THREAD_ALLOC_DESC=	Per-thread memory (DEVELOPERS ONLY!)

ICU_LIB_DEPENDS=		libicuuc.so:devel/icu
ICU_CMAKE_BOOL=			LIBXML2_WITH_ICU
READLINE_LIB_DEPENDS=		libreadline.so:devel/readline
READLINE_CMAKE_BOOL=		HAVE_LIBHISTORY \
				HAVE_LIBREADLINE
THREAD_ALLOC_CMAKE_BOOL=	LIBXML2_WITH_THREAD_ALLOC

post-patch:
	@${REINPLACE_CMD} -e \
		's|/etc/xml/catalog|${LOCALBASE}/share/xml/catalog|g; \
		 s|/etc/sgml/catalog|${LOCALBASE}/share/sgml/catalog|g' \
		${WRKSRC}/doc/xmllint.1
	@${RM} ${WRKSRC}/doc/xmllint.1.bak

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
