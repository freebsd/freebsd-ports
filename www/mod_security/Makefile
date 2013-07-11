# $FreeBSD$

PORTNAME=	mod_security
PORTVERSION=	2.7.4
PORTREVISION=	2
CATEGORIES=	www security
MASTER_SITES=	http://www.modsecurity.org/tarball/${PORTVERSION}/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/_//:S/2//}-apache_${PORTVERSION}

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	An intrusion detection and prevention engine

LICENSE=	AL2
MAKE_JOBS_SAFE=	yes

LIB_DEPENDS+=	pcre:${PORTSDIR}/devel/pcre \
		apr-1:${PORTSDIR}/devel/apr1

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
MLOGC_DESC=	Build ModSecurity Log Collector

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MMLOGC}
LIB_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=	--with-curl=${LOCALBASE} --disable-errors
PLIST_FILES+=	bin/mlogc bin/mlogc-batch-load.pl
.else
CONFIGURE_ARGS+=	--disable-mlogc
.endif

.if ${PORT_OPTIONS:MLUA}
USE_LUA=	5.1+
CONFIGURE_ARGS+=	--with-lua=${LOCALBASE}
LIB_DEPENDS+=	lua-5.1.5:${PORTSDIR}/lang/lua
.else
CONFIGURE_ARGS+=	--without-lua
.endif

REINPLACE_ARGS=	-i ""
AP_EXTRAS+=	-DWITH_LIBXML2
CONFIGURE_ARGS+=	--with-apxs=${APXS} --with-pcre=${LOCALBASE}

post-build:
.if ${PORT_OPTIONS:MMLOGC}
	# XXX there is "mlogc-static" target in the Makefile, too
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} mlogc
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/modsecurity.conf-recommended ${PREFIX}/etc/modsecurity.conf-example
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "doc" ${DOCSDIR}/)
.endif
.if ${PORT_OPTIONS:MMLOGC}
	${INSTALL_PROGRAM} ${WRKSRC}/mlogc/mlogc ${PREFIX}/bin/
.endif

.include <bsd.port.post.mk>
