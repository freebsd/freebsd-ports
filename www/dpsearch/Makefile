# Created by: Maxim Zakharov <maxime@maxime.net.ru>
# $FreeBSD$

PORTNAME=	dpsearch
PORTVERSION=	4.53
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://dataparksearch.googlecode.com/files/ \
		http://www.dataparksearch.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open source search engine for Internet and Intranet sites

USE_LDCONFIG=	yes
USES=		gmake tar:bzip2
GNU_CONFIGURE=	yes
PORTDOCS=	*
DOCSDIR=	${PREFIX}/share/doc/dataparksearch
CONFIGURE_ARGS+=--sysconfdir=${PREFIX}/etc/dpsearch \
		--localstatedir=/var/dpsearch \
		--enable-mp3	\
		--with-zlib

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	THREADS SSL CHINESE JAPANESE MECAB CHASEN APACHE IDN ASPELL \
		EXTRACT DOCS
OPTIONS_DEFAULT=	THREADS SSL PGSQL
OPTIONS_SINGLE=	DB
OPTIONS_SINGLE_DB=	PGSQL MYSQL SQLITE
CHINESE_DESC=	Enable chinese charsets
JAPANESE_DESC=	Enable japanese charsets
MECAB_DESC=	Enable MeCab japanese analyzer
CHASEN_DESC=	Enable ChaSen japanese analyzer
EXTRACT_DESC=	Enable libextractor support

NO_STAGE=	yes
.include <bsd.port.options.mk>

CONFIGURE_ENV+=	PORTNAME="${PORTNAME}"

.if ${PORT_OPTIONS:MTHREADS}
CONFIGURE_ARGS+=--enable-pthreads
CONFIGURE_ENV+=	LIBS="-pthread"
.else
CONFIGURE_ARGS+=--disable-pthreads
.endif

.if ${PORT_OPTIONS:MASPELL}
LIB_DEPENDS+=	aspell:${PORTSDIR}/textproc/aspell
.else
CONFIGURE_ARGS+=--without-aspell
.endif

.if ${PORT_OPTIONS:MEXTRACT}
LIB_DEPENDS+=	extractor.3:${PORTSDIR}/textproc/libextractor
.endif

.if ${PORT_OPTIONS:MSSL}
CONFIGURE_ARGS+=--with-openssl=${OPENSSLBASE}
.endif

.if ${PORT_OPTIONS:MCHARSETS}
CONFIGURE_ARGS+=--with-extra-charsets=all
.endif

.if ${PORT_OPTIONS:MCHINESE}
CONFIGURE_ARGS+=--with-extra-charsets=chinese
.endif

.if ${PORT_OPTIONS:MJAPANESE}
CONFIGURE_ARGS+=--with-extra-charsets=japanese
.endif

.if ${PORT_OPTIONS:MMECAB}
LIB_DEPENDS+=	mecab.1:${PORTSDIR}/japanese/mecab
CONFIGURE_ARGS+=--enable-mecab
.endif

.if ${PORT_OPTIONS:MCHASEN}
LIB_DEPENDS+=	chasen.2:${PORTSDIR}/japanese/chasen
CONFIGURE_ARGS+=--enable-chasen
.endif

.if ${PORT_OPTIONS:MIDN}
LIB_DEPENDS+=	idn.17:${PORTSDIR}/dns/libidn
CONFIGURE_ARGS+=--enable-idn
.endif

.if ${PORT_OPTIONS:MAPACHE}
USE_APACHE=	22+
PLIST_SUB+=	APACHE=""
CONFIGURE_ARGS+=--enable-apache-module
.else
PLIST_SUB+=	APACHE="@comment "
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=		yes
CONFIGURE_ARGS+=	--with-pgsql=${LOCALBASE}
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}
.endif

.if ${PORT_OPTIONS:MSQLITE}
LIB_DEPENDS+=		sqlite.2:${PORTSDIR}/databases/sqlite2
CONFIGURE_ARGS+=	--with-sqlite=${LOCALBASE}
.endif

post-extract:
.if ! ${PORT_OPTIONS:MDOCS}
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-doc_Makefile.in
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|g' ${WRKSRC}/configure

pre-install:
	@${INSTALL} -d ${DATADIR}

post-install:
	@${CHMOD} 700 /var/dpsearch/cache
	@${ECHO_CMD} '@exec ${CHMOD} 700 /var/dpsearch/cache' >> ${TMPPLIST}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} /var/dpsearch/
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} /var/dpsearch/' >> ${TMPPLIST}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
