# $FreeBSD$

PORTNAME=	mod_security
PORTVERSION=	2.9.3
PORTREVISION=	0
CATEGORIES=	www security
MASTER_SITES=	http://www.modsecurity.org/tarball/${PORTVERSION}/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/_//:S/2//}-${PORTVERSION}

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Intrusion detection and prevention engine

LICENSE=	APACHE20

LIB_DEPENDS+=	libpcre.so:devel/pcre \
		libapr-1.so:devel/apr1 \
		libyajl.so:devel/yajl \
		libcurl.so:ftp/curl \
		libgdbm.so:databases/gdbm \
		libexpat.so:textproc/expat2

USES=		apache:2.4+ bdb gnome perl5 pkgconfig shebangfix
USE_GNOME=	libxml2
GNU_CONFIGURE=	yes
SHEBANG_FILES=	tools/rules-updater.pl.in mlogc/mlogc-batch-load.pl.in
perl_OLD_CMD=	@PERL@

AP_INC=		${LOCALBASE}/include/libxml2
AP_LIB=		${LOCALBASE}/lib
MODULENAME=	mod_security2
SRC_FILE=	*.c

PORTDOCS=	*
DOCSDIR=	${PREFIX}/share/doc/${MODULENAME}

SUB_FILES+=	pkg-message
SUB_FILES+=	README
SUB_FILES+=	${APMOD_FILE}.sample
APMOD_FILE=	280_${PORTNAME}.conf
SUB_LIST+=	APMOD_FILE=${APMOD_FILE}

OPTIONS_DEFINE=	DOCS FUZZYHASH LUA MLOGC
OPTIONS_SUB=	yes

LUA_CONFIGURE_ON=	--with-lua=${LOCALBASE}
LUA_CONFIGURE_OFF+=	--without-lua
LUA_USES=		lua:51+

MLOGC_DESC=		Build ModSecurity Log Collector
MLOGC_CONFIGURE_ON=	--disable-errors
MLOGC_CONFIGURE_OFF=	--disable-mlogc

FUZZYHASH_DESC=		Allow matching contents using fuzzy hashes with ssdeep
FUZZYHASH_CONFIGURE_ON=	--with-ssdeep=${LOCALBASE}
FUZZYHASH_CONFIGURE_OFF=--without-ssdeep
FUZZYHASH_LIB_DEPENDS=	libfuzzy.so:security/ssdeep

ETCDIR=		${PREFIX}/etc/modsecurity

REINPLACE_ARGS=	-i ""
AP_EXTRAS+=	-DWITH_LIBXML2
CONFIGURE_ARGS+=--with-apxs=${APXS} --with-pcre=${LOCALBASE} --with-yajl=${LOCALBASE} --with-curl=${LOCALBASE}

post-patch:
	@${REINPLACE_CMD} -e "s/lua5.1/lua-${LUA_VER}/g" ${WRKSRC}/configure

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/modsecurity.conf-recommended \
		${STAGEDIR}${ETCDIR}/modsecurity.conf.sample
	${INSTALL_DATA} ${WRKSRC}/unicode.mapping \
		${STAGEDIR}${ETCDIR}/unicode.mapping

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} doc ${STAGEDIR}${DOCSDIR})
	${INSTALL_DATA} ${WRKDIR}/README ${STAGEDIR}${DOCSDIR}

	@${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEETCDIR}/modules.d
	${INSTALL_DATA} ${WRKDIR}/${APMOD_FILE}.sample ${STAGEDIR}${PREFIX}/${APACHEETCDIR}/modules.d

.include <bsd.port.mk>
