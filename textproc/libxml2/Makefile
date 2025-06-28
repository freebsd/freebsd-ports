PORTNAME?=	libxml2
DISTVERSION=	2.14.4
PORTREVISION?=	0
CATEGORIES?=	textproc gnome
MASTER_SITES=	GNOME
DISTNAME=	libxml2-${DISTVERSION}
DIST_SUBDIR=	gnome

PATCH_SITES=	https://gitlab.gnome.org/GNOME/libxml2/-/commit/
PATCHFILES=	cf52139b4170be13b51b62da11c208dc66e6eff0.patch:-p1 \
		356542324fa439de544b5e419b91ae68d42c306c.patch:-p1

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
			--with-lzma=/usr \
			--${LIBXML2_SLAVE:Dwith:Uwithout}-python${LIBXML2_SLAVE:D=${PYTHON_CMD}:U}

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

OPTIONS_DEFINE=	DOCS ICU READLINE STATIC THREAD_ALLOC
OPTIONS_GROUP=	LEGACY
OPTIONS_GROUP_LEGACY=	HTTP LZMA ZLIB
OPTIONS_DEFAULT=	HTTP LZMA READLINE STATIC ZLIB
OPTIONS_SUB=		yes

HTTP_DESC=		HTTP support
LEGACY_DESC=		Enable legacy API compatibility
READLINE_DESC=		History for xmllint
THREAD_ALLOC_DESC=	Per-thread memory (DEVELOPERS ONLY!)

HTTP_CONFIGURE_WITH=		http
ICU_LIB_DEPENDS=		libicuuc.so:devel/icu
ICU_CONFIGURE_WITH=		icu
LZMA_CONFIGURE_WITH=		lzma
READLINE_LIB_DEPENDS=		libreadline.so:devel/readline
READLINE_CONFIGURE_WITH=	history \
				readline
STATIC_CONFIGURE_ENABLE=	static
THREAD_ALLOC_CONFIGURE_WITH=	thread-alloc
ZLIB_CONFIGURE_WITH=		zlib

post-patch:
	@${REINPLACE_CMD} -e \
		's|/etc/xml/catalog|${LOCALBASE}/share/xml/catalog|g; \
		 s|/etc/sgml/catalog|${LOCALBASE}/share/sgml/catalog|g' \
		${WRKSRC}/doc/xmllint.1

post-install:
.if !defined(LIBXML2_SLAVE)
# Documentation should be in DOCSDIR
	@${MV} ${STAGEDIR}${PREFIX}/share/gtk-doc/html/libxml2 \
		${STAGEDIR}${DOCSDIR}/devhelp
	@${RM} -r ${STAGEDIR}${PREFIX}/share/gtk-doc
# Install remaining documentation that's not connected to autotools
	${INSTALL_MAN} ${WRKSRC}/doc/*.html ${STAGEDIR}${DOCSDIR}
.else
	${STRIP_CMD} ${STAGEDIR}${PYTHON_LIBDIR}/site-packages/libxml2mod${PYTHON_SOABI}.so
.endif

.include <bsd.port.mk>
