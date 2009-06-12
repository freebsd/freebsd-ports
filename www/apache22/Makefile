# New ports collection makefile for:	apache22
# Date created:				Dec 11 2004
# Whom:					Clement Laforet <clement@FreeBSD.org>
#
# $FreeBSD$
#
# For more information, please read Makefile.doc
#

PORTNAME=	apache
PORTVERSION=	2.2.11
PORTREVISION?=	7
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_APACHE_HTTPD}
DISTNAME=	httpd-${PORTVERSION}
DISTFILES=	${DISTNAME}.tar.bz2
DIST_SUBDIR=	apache22

MAINTAINER?=	apache@FreeBSD.org
COMMENT?=	Version 2.2.x of Apache web server with ${WITH_MPM:L} MPM.

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2 \
		pcre.0:${PORTSDIR}/devel/pcre

MAKE_JOBS_SAFE=  yes

LATEST_LINK?=	apache22

CONFLICTS=	apache+mod_ssl-1.* apache+mod_ssl+ipv6-1.* apache+mod_ssl+modsnmp-1.* \
		apache+mod_ssl+mod_snmp+ipv6-1.* apache+mod_ssl+mod_accel-1.* \
		apache+mod_ssl+mod_snmp+mod_accel-1.* \
		apache+ipv6-1.* apache+ssl-1.* apache-1.* apache_fp-1.* \
		caudium-devel-1.* caudium10-1.* caudium12-* \
		ru-apache+mod_ssl-1.* ru-apache-1.* \
		apache-2.0.* apache-*-2.0.* apache-2.1.* apache-*-2.1.*

SCRIPTS_ENV+=		LIBTOOL=${LIBTOOL} LIBTOOLIZE=${LIBTOOLIZE} \
			LIBTOOL_VERSION=${LIBTOOL_VERSION} AUTOCONF=${AUTOCONF} \
			LIBTOOL_M4=${LOCALBASE}/share/aclocal/libtool${LIBTOOL_VERSION}.m4 \
			AUTOHEADER=${AUTOHEADER}

USE_APACHE=		common22
USE_BZIP2=		yes
USE_ICONV=		yes
USE_AUTOTOOLS=		autoconf:262 libtool:15
USE_PERL5=		yes
USE_RC_SUBR=		apache22 htcacheclean
LIBTOOLFILES=		configure

MPM_ITK_VERSION?=	20080727-00

# for slave ports
.if !defined(MASTERDIR)
APACHEDIR=	${.CURDIR}
.else
APACHEDIR=	${MASTERDIR}
.endif

.if !defined(WITHOUT_APACHE_OPTIONS)
OPTIONS= \
	APR_FROM_PORTS "Use devel/apr as APR (beware!)" Off \
	THREADS "Enable threads support in APR" Off \
	MYSQL "Enable MySQL support for apr-dbd" Off \
	PGSQL "Enable PostgreSQL support for apr-dbd" Off \
	SQLITE "Enable SQLite support for apr-dbd" Off \
	IPV6 "Enable IPv6 support" On \
	BDB "Enable BerkeleyDB dbm" Off
.include "${APACHEDIR}/Makefile.options"
.endif

CONFIGURE_ARGS=	--prefix=${PREFIX_RELDEST} \
		--enable-layout=FreeBSD \
		--with-perl=${PERL5} \
		--with-port=${WITH_HTTP_PORT} \
		--with-expat=${LOCALBASE} \
		--with-iconv=${LOCALBASE} \
		--enable-http \
		--with-pcre=${LOCALBASE}

CONFIGURE_ENV=	CC="${CC}" CPPFLAGS="${CPPFLAGS}" \
		CFLAGS="${CFLAGS}" \
		LDFLAGS="${LDFLAGS}" CONFIG_SHELL="${SH}" \
		LOCALBASE="${LOCALBASE}"

PREFIX_RELDEST=	${PREFIX:S,^${DESTDIR},,}

MAKE_ENV+=	EXPR_COMPAT=yes

WITH_MPM?=	prefork # or worker, event, itk

WITH_HTTP_PORT?=	80

.if defined(WITH_STATIC_SUPPORT)
CONFIGURE_ARGS+=	--enable-static-support
.endif

# debug overrides CFLAGS
.if defined(WITH_DEBUG)
DEBUG_FLAGS?=	-O0 -g -ggdb3
CFLAGS=		${DEBUG_FLAGS}
CONFIGURE_ARGS+=	--enable-maintainer-mode
WITH_EXCEPTION_HOOK=	YES
.endif

.if defined(WITH_EXCEPTION_HOOK)
CONFIGURE_ARGS+=	--enable-exception-hook
.endif

.include "${APACHEDIR}/Makefile.doc"
.include "${APACHEDIR}/Makefile.modules"
.include <bsd.port.pre.mk>

# OPTIONS fixups
.if defined (WITH_AUTHNZ_LDAP)
WITH_LDAP=	yes
.endif

.include "${APACHEDIR}/Makefile.modules"

.if (defined(WITH_SSL)|| !defined(WITHOUT_SSL_MODULES))
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

.endif

.if defined(WITH_APR_FROM_PORTS)
PLIST_SUB+=	APR_PORTS="@comment "
APR_PORT?=	devel/apr	
LIB_DEPENDS+=	apr-1:${PORTSDIR}/${APR_PORT}
CONFIGURE_ARGS+=	--with-apr=${LOCALBASE}/bin/apr-1-config \
			--with-apr-util=${LOCALBASE}/bin/apu-1-config
CONFIGURE_ENV+=		LTFLAGS="--tag=CXX"
.else
USE_LDCONFIG=	yes
PLIST_SUB+=	APR_PORTS=""
CONFLICTS+=	apr-1.* apr-db4[0-9]-1.*
CONFIGURE_ENV+=	USE_BUNDLED_APR=YES
.endif

# When using apr_mysql_db we _must_ rebuild makefiles
.if defined(WITH_FULLBUILD)
BUILD_DEPENDS=	python:${PORTSDIR}/lang/python
SCRIPTS_ENV+=	FULLBUILD=on
.endif

.if defined (WITH_LDAP) || defined (WITH_LDAP_MODULES)
USE_OPENLDAP=		YES
CONFIGURE_ARGS+=	--with-ldap \
			--with-ldap-lib="${LOCALBASE}/lib" \
			--with-ldap-include="${LOCALBASE}/include"
.endif

.if defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--disable-ipv6
.else
CATEGORIES+=		ipv6
.   if defined(WITH_IPV6_V6ONLY) || defined(WITHOUT_V4MAPPED)
CONFIGURE_ARGS+=	--disable-v4-mapped
.   else
CONFIGURE_ARGS+=	--enable-v4-mapped
.   endif
.endif

.if defined(WITH_THREADS)
CONFIGURE_ARGS+=	--enable-threads
.   if ${ARCH} == i386
CONFIGURE_ARGS+=	--enable-nonportable-atomics
.   endif
.endif

CONFIGURE_ARGS+=	--with-mpm=${WITH_MPM:L}

pre-everything::
	@${ECHO_MSG}	""
	@${ECHO_MSG}	" To enable a module category: WITH_<CATEGORY>_MODULES"
	@${ECHO_MSG}	" To disable a module category: WITHOUT_<CATEGORY>_MODULES"
	@${ECHO_MSG}	""
	@${ECHO_MSG}	" Per default categories are:"
	@${ECHO_MSG}	"  ${DEFAULT_MODULES_CATEGORIES}"
	@${ECHO_MSG}	" Categories available:"
	@${ECHO_MSG}	"  ${ALL_MODULES_CATEGORIES}"
	@${ECHO_MSG}	""
	@${ECHO_MSG}	"  To see all available knobs, type make show-options"
	@${ECHO_MSG}	"  To see all modules in different categories, type make show-categories"
	@${ECHO_MSG}    "  You can check your modules configuration by using make show-modules"
	@${ECHO_MSG}	""

show-options:
	@${SED} -ne 's/^##//p' ${APACHEDIR}/Makefile.doc

#optionally enable mod_proxy_connect patch
.if defined(PATCH_PROXY_CONNECT)
EXTRA_PATCHES+= ${FILESDIR}/opt-patch-modules:proxy:mod_proxy_connect.c
.endif

post-patch:
	@${RM} -f ${WRKSRC}/docs/docroot/*.bak
	@${REINPLACE_CMD} -e 's," PLATFORM ",FreeBSD,' \
			${WRKSRC}/server/core.c
	@${REINPLACE_CMD} -e "s,%%OSVERSION%%,${OSVERSION}," \
			${WRKSRC}/srclib/apr/build/apr_hints.m4
	@${INSTALL_DATA} ${WRKSRC}/NOTICE ${WRKSRC}/docs/manual

pre-configure:
	@cd ${WRKSRC}; ${SETENV} ${SCRIPTS_ENV} ./buildconf

post-configure:
	@FTPUSERS=`${EGREP} -v '^#' /etc/ftpusers| ${TR} -s "\n" " "` ;\
	${REINPLACE_CMD} -e "s,%%FTPUSERS%%,$$FTPUSERS," \
			${WRKSRC}/docs/conf/extra/httpd-userdir.conf
	@${REINPLACE_CMD} -e "s,%%WWWOWN%%,${WWWOWN}, ; \
			s,%%WWWGRP%%,${WWWGRP}," \
			${WRKSRC}/docs/conf/httpd.conf
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX}," \
			${WRKSRC}/support/envvars-std

pre-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@${MKDIR} ${PREFIX}/etc/apache22/envvars.d
	@${MKDIR} ${PREFIX}/etc/apache22/Includes
	@${INSTALL_DATA} ${FILESDIR}/no-accf.conf ${PREFIX}/etc/apache22/Includes
.if !defined(NOPORTDOCS)
.for dir in style/lang style/xsl/util style/xsl
	@[ -d ${DOCSDIR}/${dir}/ ] && ${TOUCH} ${DOCSDIR}/${dir}/.keepme
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
