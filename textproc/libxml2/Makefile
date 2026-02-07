PORTNAME?=	libxml2
DISTVERSION=	2.15.1
PORTREVISION=	1
CATEGORIES?=	textproc gnome
MASTER_SITES=	GNOME
DISTNAME=	libxml2-${DISTVERSION}
DIST_SUBDIR=	gnome

PATCH_SITES=	https://gitlab.gnome.org/GNOME/libxml2/-/commit/
PATCHFILES=	0e50b31902cdb1eb242eb361c123e9e033b2af87.patch:-p1

MAINTAINER=	desktop@FreeBSD.org
COMMENT?=	XML parser library for GNOME
WWW=		http://xmlsoft.org/

LICENSE=	MIT

# Upstream recommends autotools on Unix-like systems
USES+=		cpe gmake iconv libtool localbase pathfix pkgconfig tar:xz
CPE_VENDOR=	xmlsoft
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
# Don't build with Python support unless requested
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/share/ \
			--${LIBXML2_SLAVE:Dwith:Uwithout}-python${LIBXML2_SLAVE:D=${PYTHON_CMD}:U}

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

OPTIONS_DEFINE=	ICU MANPAGES READLINE STATIC THREAD_ALLOC
OPTIONS_GROUP=	LEGACY
OPTIONS_GROUP_LEGACY=	HTTP ZLIB
OPTIONS_DEFAULT=	HTTP READLINE STATIC ZLIB
OPTIONS_SUB=		yes

HTTP_DESC=		HTTP support
LEGACY_DESC=		Enable legacy API compatibility
READLINE_DESC=		History for xmllint
THREAD_ALLOC_DESC=	Per-thread memory (DEVELOPERS ONLY!)

HTTP_CONFIGURE_WITH=		http
ICU_LIB_DEPENDS=		libicuuc.so:devel/icu
ICU_CONFIGURE_WITH=		icu
READLINE_LIB_DEPENDS=		libreadline.so:devel/readline
READLINE_CONFIGURE_WITH=	history \
				readline
STATIC_CONFIGURE_ENABLE=	static
THREAD_ALLOC_CONFIGURE_WITH=	thread-alloc
ZLIB_CONFIGURE_WITH=		zlib

.include <bsd.port.options.mk>

post-install:
.if defined(LIBXML2_SLAVE) && ${LIBXML2_SLAVE} == "python"
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_LIBDIR}/site-packages/libxml2mod${PYTHON_SOABI}.so
.endif

# To (manually) generate man pages, during every update:
# - install textproc/libxslt and textproc/docbook-xsl
# - xml2-config.1 is already present
# - in ${WRKSRC}/doc, run `xsltproc --nonet --novalid --param man.output.quietly 1 -o xmlcatalog.1 ${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl xmlcatalog.xml`
# - repeat for xmllint.1
# - copy results into ${FILESDIR}
# - ${INSTALL_MAN} into ${STAGEDIR} as below
post-install-MANPAGES-on:
	${INSTALL_MAN} ${FILESDIR}/*.1 ${STAGEDIR}${MANDIRS}/man1

.include <bsd.port.mk>
