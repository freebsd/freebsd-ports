PORTNAME=	nmap
DISTVERSION=	7.991
CATEGORIES=	security
MASTER_SITES=	https://nmap.org/dist/

PATCH_SITES=	https://github.com/nmap/nmap/commit/
PATCHFILES=	9e88dd2da292ddd9f9d6ed836bc3ef443b4d35e7.patch:-p1 \
		d0fa89658c74607b6fd6fddc3df709e39ddffa3d.patch:-p1

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Port scanning utility for large networks
WWW=		https://nmap.org/

LICENSE=	NPSL
LICENSE_NAME=	Nmap Public Source License
LICENSE_PERMS=	auto-accept dist-mirror pkg-mirror pkg-sell
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpcap.so.1:net/libpcap \
		libpcre2-8.so:devel/pcre2

USES=		cpe gmake libtool lua:54 tar:bzip2

EXTRACT_AFTER_ARGS=	--exclude ${DISTNAME}/liblua \
			--exclude ${DISTNAME}/libpcap \
			--exclude ${DISTNAME}/libpcre \
			--exclude ${DISTNAME}/libssh2 \
			--exclude ${DISTNAME}/libz \
			--exclude ${DISTNAME}/macosx \
			--exclude ${DISTNAME}/mswin32 \
			--no-same-owner --no-same-permissions

GNU_CONFIGURE=		yes

DOCS=			CHANGELOG HACKING

CONFIGURE_ARGS=		--with-libpcap=${LOCALBASE} \
			--with-libpcre=${LOCALBASE} \
			--with-zlib=/usr \
			--without-ndiff \
			--without-zenmap \
			--with-liblua=${LUA_INCDIR} \
			--without-nmap-update

OPTIONS_DEFINE=		DOCS NLS LIBSSH2 OPENSSL
OPTIONS_DEFAULT=	NLS LIBSSH2 OPENSSL
OPTIONS_SUB=		yes

LIBSSH2_DESC=		SSH2 protocol support

NLS_CONFIGURE_ENABLE=	nls

LIBSSH2_LIB_DEPENDS=	libssh2.so:security/libssh2
LIBSSH2_CONFIGURE_ON=	--with-libssh2=${LOCALBASE}
LIBSSH2_CONFIGURE_OFF=	--without-libssh2
LIBSSH2_IMPLIES=	OPENSSL

OPENSSL_USES=		ssl
OPENSSL_CFLAGS=		-I${OPENSSLINC}
OPENSSL_CONFIGURE_ON=	--with-openssl=${OPENSSLBASE}
OPENSSL_CONFIGURE_OFF=	--without-openssl

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENSSL} && ${SSL_DEFAULT:Mlibressl*}
IGNORE=	LibreSSL is not supported
.endif

post-patch:
	@${REINPLACE_CMD} -e '\
		s|with_liblua\/include|with_liblua|g; \
		s|$$with_liblua\/lib |${LUA_LIBDIR} -llua-${LUA_VER} |g' \
	    ${PATCH_WRKSRC}/configure
	@${REINPLACE_CMD} -e '\
		s|with_liblua\/include|with_liblua|g; \
		s|$$with_liblua\/lib |${LUA_LIBDIR} -llua-${LUA_VER} |g' \
	    ${PATCH_WRKSRC}/ncat/configure

post-configure:
	@${REINPLACE_CMD} -e "s|^DESTDIR *=|& ${DESTDIR}|" ${WRKSRC}/Makefile

pre-install:
	${FIND} ${WRKSRC} -type f \( -name \*.orig -o -name \*.bak \) -delete

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ncat
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/nmap
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/nping

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
