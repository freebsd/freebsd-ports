PORTNAME?=	libxml2
DISTVERSION=	2.15.1
CATEGORIES?=	textproc gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX?=	-core
DISTNAME=	libxml2-${DISTVERSION}
DIST_SUBDIR=	gnome

MAINTAINER=	desktop@FreeBSD.org
COMMENT?=	XML parser library for GNOME
WWW=		http://xmlsoft.org/

LICENSE=	MIT

# Upstream recommends autotools on Unix-like systems
USES+=			cpe gmake iconv libtool localbase pathfix pkgconfig \
			tar:xz
CPE_VENDOR=		xmlsoft
USE_LDCONFIG=		yes
GNU_CONFIGURE=		yes
# Don't build with Python support unless requested
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/share/

PATCH_STRIP=		-p1

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

OPTIONS_DEFINE=		DOCS ICU PYTHON READLINE STATIC THREAD_ALLOC
OPTIONS_GROUP=		LEGACY
OPTIONS_GROUP_LEGACY=	HTTP ZLIB
OPTIONS_DEFAULT=	HTTP READLINE STATIC ZLIB
OPTIONS_SUB=		yes
# note: no DOCS - built by ../libxml2 instead, to
# avoid a circular dependency. libxml2 2.15.0 requires
# xsltproc (provided by libxslt, which depends on libxml2)
OPTIONS_EXCLUDE?=	DOCS PYTHON

HTTP_DESC=		HTTP support
LEGACY_DESC=		Enable legacy API compatibility
READLINE_DESC=		History for xmllint
THREAD_ALLOC_DESC=	Per-thread memory (DEVELOPERS ONLY!)

DOCS_BUILD_DEPENDS=		doxygen:devel/doxygen
DOCS_CONFIGURE_WITH=		docs
HTTP_CONFIGURE_WITH=		http
ICU_LIB_DEPENDS=		libicuuc.so:devel/icu
ICU_CONFIGURE_WITH=		icu
PYTHON_CONFIGURE_WITH=		python=${PYTHON_CMD}
PYTHON_BUILD_DEPENDS=		doxygen:devel/doxygen
READLINE_LIB_DEPENDS=		libreadline.so:devel/readline
READLINE_CONFIGURE_WITH=	history readline
STATIC_CONFIGURE_ENABLE=	static
THREAD_ALLOC_CONFIGURE_WITH=	thread-alloc
ZLIB_CONFIGURE_WITH=		zlib

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MDOCS)
CONFIGURE_ARGS+=	--without-docs
.endif

.if empty(PORT_OPTIONS:MPYTHON)
CONFIGURE_ARGS+=	--without-python
.endif

.include <bsd.port.mk>
