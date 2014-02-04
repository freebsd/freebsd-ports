# $FreeBSD$

PORTNAME=	mod_security
PORTVERSION=	2.7.4
PORTREVISION=	2
CATEGORIES=	www security
MASTER_SITES=	http://www.modsecurity.org/tarball/${PORTVERSION}/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/_//:S/2//}-apache_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Intrusion detection and prevention engine

LICENSE=	APACHE20

LIB_DEPENDS+=	libpcre.so:${PORTSDIR}/devel/pcre \
		libapr-1.so:${PORTSDIR}/devel/apr1

USE_APACHE=	22+
GNU_CONFIGURE=	yes
AP_GENPLIST=	yes
AP_INC=	${LOCALBASE}/include/libxml2
AP_LIB=	${LOCALBASE}/lib
USE_GNOME=	libxml2
MODULENAME=	mod_security2
SRC_FILE=	*.c
PORTDOCS=	*
DOCS=		CHANGES LICENSE README.TXT modsecurity.conf-minimal
DOCSDIR=	${PREFIX}/share/doc/${MODULENAME}
SUB_FILES+=	mod_security2.conf
SUB_LIST+=	APACHEETCDIR="${APACHEETCDIR}"
PLIST_FILES=	etc/modsecurity.conf-example \
		${APACHEMODDIR}/mod_security2.so \
		bin/rules-updater.pl \
		lib/mod_security2.so

OPTIONS_DEFINE=	LUA MLOGC

LUA_CONFIGURE_ON=	--with-lua=${LOCALBASE}
LUA_CONFIGURE_OFF+=	--without-lua
LUA_USE=		LUA=5.1+

MLOGC_DESC=		Build ModSecurity Log Collector
MLOGC_CONFIGURE_ON=	--with-curl=${LOCALBASE} --disable-errors
MLOGC_CONFIGURE_OFF=	--disable-mlogc
MLOGC_LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl
MLOGC_PLIST_FILES=	bin/mlogc bin/mlogc-batch-load.pl

.include <bsd.port.options.mk>

REINPLACE_ARGS=	-i ""
AP_EXTRAS+=	-DWITH_LIBXML2
CONFIGURE_ARGS+=	--with-apxs=${APXS} --with-pcre=${LOCALBASE}

post-build:
.if ${PORT_OPTIONS:MMLOGC}
	# XXX there is "mlogc-static" target in the Makefile, too
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} mlogc
.endif

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/modsecurity.conf-recommended \
		${STAGEDIR}${PREFIX}/etc/modsecurity.conf-example
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "doc" ${STAGEDIR}${DOCSDIR})
.if ${PORT_OPTIONS:MMLOGC}
	${INSTALL_PROGRAM} ${WRKSRC}/mlogc/mlogc ${STAGEDIR}${PREFIX}/bin
.endif

.include <bsd.port.mk>
