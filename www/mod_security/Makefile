# New ports collection makefile for:	mod_security
# Date created:				4 June 2003
# Whom:					Marcelo Araujo <araujo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_security
PORTVERSION=	2.6.6
PORTREVISION=	1
CATEGORIES=	www security
MASTER_SITES=	SF/mod-security/modsecurity-apache/${PORTVERSION}
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/_//:S/2//}-apache_${PORTVERSION}

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	An intrusion detection and prevention engine

LICENSE=	AL2
MAKE_JOBS_SAFE=	yes

LIB_DEPENDS+=	pcre.3:${PORTSDIR}/devel/pcre \
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
OPTIONS=	LUA "Embedded Lua language support" off \
		MLOGC "Build ModSecurity Log Collector" off

.include <bsd.port.pre.mk>

.if defined(WITH_MLOGC)
PLIST_FILES+=	bin/mlogc
.endif

.if defined(WITH_LUA)
USE_LUA=	5.1+
CONFIGURE_ARGS+=	--with-lua=${LOCALBASE}
LIB_DEPENDS+=	lua-5.1.1:${PORTSDIR}/lang/lua
.else
CONFIGURE_ARGS+=	--without-lua
.endif

.if defined(WITH_MLOGC)
LIB_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=	--with-curl=${LOCALBASE} --disable-errors
.else
CONFIGURE_ARGS+=	--disable-mlogc
.endif

REINPLACE_ARGS=	-i ""
AP_EXTRAS+=	-DWITH_LIBXML2
CONFIGURE_ARGS+=	--with-apxs=${APXS} --with-pcre=${LOCALBASE}

post-build:
.if defined(WITH_MLOGC)
	# XXX there is "mlogc-static" target in the Makefile, too
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} mlogc
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/modsecurity.conf-recommended ${PREFIX}/etc/modsecurity.conf-example
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "doc" ${DOCSDIR}/)
.endif
.if defined(WITH_MLOGC)
	${INSTALL_PROGRAM} ${WRKSRC}/mlogc/mlogc ${PREFIX}/bin/
.endif

.include <bsd.port.post.mk>
