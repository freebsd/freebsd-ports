# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	aria2
PORTVERSION=	1.17.1
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/stable/${PORTNAME}-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Yet another download tool

LICENSE=	GPLv2

OPTIONS_DEFINE=	CA_BUNDLE DOCS NLS SQLITE
OPTIONS_DEFAULT=SQLITE
CA_BUNDLE_DESC=	Use CA bundle from Mozilla Project

CONFIGURE_ARGS=	--disable-epoll --enable-bittorrent --enable-metalink \
		--enable-shared --enable-threads=posix --with-libz \
		--with-libxml2 --with-openssl --without-gnutls \
		--without-libcares --without-libexpat --without-libgcrypt \
		--without-libgmp --without-libnettle
CONFIGURE_ENV=	OPENSSL_CFLAGS=-I${OPENSSLINC} OPENSSL_LIBS="-L${OPENSSLLIB} -lssl" \
		AZLIB_CFLAGS=-I${INCLUDEDIR} ZLIB_LIBS="-L${LIBDIR} -lz" \
		ac_cv_path_RST2HTML=no
GNU_CONFIGURE=	yes
USE_GNOME=	libxml2
USE_OPENSSL=	yes
USE_XZ=		yes
USES=		pathfix

MAN1=		aria2c.1
MANLANG=	"" pt ru
PLIST_FILES=	bin/aria2c
PLIST_DIRSTRY=	man/ru/man1 \
		man/ru \
		man/pt/man1 \
		man/pt

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCA_BUNDLE}
RUN_DEPENDS+=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss
CONFIGURE_ARGS+=--with-ca-bundle=${LOCALBASE}/share/certs/ca-root-nss.crt
.else
CONFIGURE_ARGS+=--without-ca-bundle
.endif

.if ${PORT_OPTIONS:MDOCS}
PLIST_FILES+=	%%DOCSDIR%%/README \
		%%DOCSDIR%%/README.html \
		%%DOCSDIR%%/README.rst \
		%%DOCSDIR%%/bash_completion/README.txt \
		%%DOCSDIR%%/bash_completion/aria2c \
		%%DOCSDIR%%/xmlrpc/README.txt \
		%%DOCSDIR%%/xmlrpc/aria2mon \
		%%DOCSDIR%%/xmlrpc/aria2rpc
PLIST_DIRS=	%%DOCSDIR%%/xmlrpc \
		%%DOCSDIR%%/bash_completion \
		%%DOCSDIR%%
.endif

.if ${PORT_OPTIONS:MNLS}
CONFIGURE_ARGS+=--with-libintl-prefix=${LOCALBASE}
USES+=		gettext
LANGS=		en@boldquot en@quot fil kk oc zh_HK
LANGS_MTREE=	ar bg bn ca da de el es fa fi fr he hr hu id it ja ko ms nb nl \
		nn pl pt pt_BR ro ru sk sr sv th tr uk vi zh_CN zh_TW
.for lang in ${LANGS} ${LANGS_MTREE}
PLIST_FILES+=	share/locale/${lang}/LC_MESSAGES/${PORTNAME}.mo
.endfor
.for lang in ${LANGS}
PLIST_DIRSTRY+=	share/locale/${lang}/LC_MESSAGES \
		share/locale/${lang}
.endfor
.else
CONFIGURE_ARGS+=--disable-nls
.endif

.if ${PORT_OPTIONS:MSQLITE}
CONFIGURE_ARGS+=--with-sqlite3
USE_SQLITE=	yes
.else
CONFIGURE_ARGS+=--without-sqlite3
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc" && ${OSVERSION} > 900000
BROKEN=		Does not install on powerpc-9
.endif

post-patch:
.if !${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e 's|\(install-exec-am\) install-data-am|\1|' ${WRKSRC}/Makefile.in ${WRKSRC}/doc/Makefile.in
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${INSTALL_DATA} ${WRKSRC}/README.html ${DOCSDIR}/
.endif

.include <bsd.port.post.mk>
