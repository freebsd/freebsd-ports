# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	aria2
PORTVERSION=	1.18.3
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/stable/${PORTNAME}-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Yet another download tool

LICENSE=	GPLv2

OPTIONS_DEFINE=	CA_BUNDLE DOCS NLS SQLITE
OPTIONS_DEFAULT=SQLITE
OPTIONS_SUB=	yes
CA_BUNDLE_DESC=	Use CA bundle from Mozilla Project

CONFIGURE_ARGS=	--disable-epoll --enable-bittorrent --enable-libaria2 \
		--enable-metalink --enable-shared --enable-static \
		--enable-threads=posix --with-disk-cache=${ARIA2_DISK_CACHE} \
		--with-libxml2 --with-libz --with-openssl --without-gnutls \
		--without-libcares --without-libexpat --without-libgcrypt \
		--without-libgmp --without-libnettle
CONFIGURE_ENV=	OPENSSL_CFLAGS=-I${OPENSSLINC} \
		OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto -lssl" \
		ZLIB_CFLAGS=-I${INCLUDEDIR} \
		ZLIB_LIBS="-L${LIBDIR} -lz" \
		ac_cv_path_RST2HTML=no
GNU_CONFIGURE=	yes
USE_CXXSTD=	c++11
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
USES=		compiler:c++11-lib pathfix pkgconfig tar:xz

CA_BUNDLE_CONFIGURE_OFF=--without-ca-bundle
CA_BUNDLE_CONFIGURE_ON=	--with-ca-bundle=${LOCALBASE}/share/certs/ca-root-nss.crt
CA_BUNDLE_RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss
NLS_CONFIGURE_OFF=	--disable-nls
NLS_CONFIGURE_ON=	--with-libintl-prefix=${LOCALBASE}
NLS_USES=		gettext
SQLITE_CONFIGURE_OFF=	--without-sqlite3
SQLITE_CONFIGURE_ON=	--with-sqlite3
SQLITE_USE=		SQLITE=yes

ARIA2_DISK_CACHE?=	16M

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc" && ${OSVERSION} > 900000
BROKEN=		Does not install on powerpc-9
.endif

post-patch:
.if !${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e 's|\(install-exec-am\) install-data-am|\1|' ${WRKSRC}/Makefile.in ${WRKSRC}/doc/Makefile.in
.endif

post-build:
	@${STRIP_CMD} ${WRKSRC}/src/.libs/libaria2.so.0

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${INSTALL_DATA} ${WRKSRC}/README.html ${STAGEDIR}${DOCSDIR}/
.endif

.include <bsd.port.post.mk>
