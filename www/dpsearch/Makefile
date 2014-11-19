# Created by: Maxim Zakharov <maxime@maxime.net.ru>
# $FreeBSD$

PORTNAME=	dpsearch
PORTVERSION=	4.53
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	http://dataparksearch.googlecode.com/files/ \
		http://www.dataparksearch.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open source search engine for Internet and Intranet sites

BROKEN=		Does not link
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2014-11-26

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

OPTIONS_DEFINE=	THREADS SSL CHINESE JAPANESE MECAB APACHE IDN ASPELL \
		EXTRACT DOCS
OPTIONS_DEFAULT=	THREADS SSL PGSQL
OPTIONS_SINGLE=	DB
OPTIONS_SINGLE_DB=	PGSQL MYSQL SQLITE
CHINESE_DESC=	Enable chinese charsets
JAPANESE_DESC=	Enable japanese charsets
MECAB_DESC=	Enable MeCab japanese analyzer
EXTRACT_DESC=	Enable libextractor support

.include <bsd.port.options.mk>

CONFIGURE_ENV+=	PORTNAME="${PORTNAME}"

THREADS_CONFIGURE_ENABLE=	pthreads
THREADS_LIBS=	-pthread

ASPELL_LIB_DEPENDS=	libaspell.so:${PORTSDIR}/textproc/aspell
#ASPELL_CONFIGURE_WITH=	aspell
.if ! ${PORT_OPTIONS:MASPELL}
CONFIGURE_ARGS+=--without-aspell
.endif

EXTRACT_LIB_DEPENDS=	libextractor.so:${PORTSDIR}/textproc/libextractor

SSL_CONFIGURE_WITH=	openssl=${OPENSSLBASE}

CHARSETS_CONFIGURE_WITH=	extra-charsets=all

CHINESE_CONFIGURE_WITH=	extra-charsets=chinese

JAPANESE_CONFIGURE_WITH=	extra-charsets=japanese

MECAB_LIB_DEPENDS=	libmecab.so:${PORTSDIR}/japanese/mecab
MECAB_CONFIGURE_ENABLE=	mecab

IDN_LIB_DEPENDS=	libidn.so:${PORTSDIR}/dns/libidn
IDN_CONFIGURE_ENABLE=	idn

OPTIONS_SUB=	yes

APACHE_USE=	APACHE=22+
APACHE_CONFIGURE_ENABLE=	apache-module

PGSQL_USE=	PGSQL=yes
PGSQL_CONFIGURE_WITH=	pgsql=${LOCALBASE}

MYSQL_USE=	MYSQL=yes
MYSQL_CONFIGURE_WITH=	mysql=${LOCALBASE}

SQLITE_LIB_DEPENDS=	libsqlite.so:${PORTSDIR}/databases/sqlite2
SQLITE_CONFIGURE_WITH=	sqlite=${LOCALBASE}

post-extract:
.if ! ${PORT_OPTIONS:MDOCS}
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-doc_Makefile.in
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|g' ${WRKSRC}/configure

pre-install:
	@${INSTALL} -d ${STAGEDIR}${DATADIR}

post-install:
	@${ECHO_CMD} '@exec ${CHMOD} 700 /var/dpsearch/cache' >> ${TMPPLIST}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} /var/dpsearch/
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} /var/dpsearch/' >> ${TMPPLIST}

.include <bsd.port.mk>
