# New ports collection makefile for:	apache2
# Date created:				7 April 2001
# Whom:					Hye-Shik Chang <perky@fallin.lv>
#
# $FreeBSD$
#
# For more information, please read Makefile.doc
#

PORTNAME=	apache
PORTVERSION=	2.0.63
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_APACHE_HTTPD} \
		${MASTER_SITE_LOCAL:S/$/:powerlogo/}
MASTER_SITE_SUBDIR=	clement/:powerlogo
DISTNAME=	httpd-${PORTVERSION}
DISTFILES=	${DISTNAME}.tar.bz2 powerlogo.gif:powerlogo
DIST_SUBDIR=	apache2
EXTRACT_ONLY=	${DISTNAME}.tar.bz2

MAINTAINER?=	apache@FreeBSD.org
COMMENT?=	Version 2.0.x of Apache web server with ${WITH_MPM:L} MPM.

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

MAKE_JOBS_SAFE=  yes

LATEST_LINK=	apache20

CONFLICTS=	apache+mod_ssl-1.* apache+mod_ssl+ipv6-1.* apache+mod_ssl+modsnmp-1.* \
		apache+mod_ssl+mod_snmp+ipv6-1.* apache+mod_ssl+mod_accel-1.* \
		apache+mod_ssl+mod_snmp+mod_accel-1.* \
		apache+ipv6-1.* apache+ssl-1.* apache-1.* apache_fp-1.* \
		caudium-devel-1.* caudium10-1.* caudium12-* \
		ru-apache+mod_ssl-1.* ru-apache-1.*

# patch files
EXTRA_PATCHES+=		${FILESDIR}/build-fix-openssl_beta

.if defined(WITH_EXPERIMENTAL_PATCHES)
IGNORE=		: Please define WITH_KQUEUE_SUPPORT instead
.endif

.if defined(WITH_KQUEUE_SUPPORT)
EXTRA_PATCHES+=		${FILESDIR}/exp-apr-kqueue.patch
.endif

SCRIPTS_ENV+=		LIBTOOL=${LIBTOOL} LIBTOOLIZE=${LIBTOOLIZE} \
			LIBTOOL_VERSION=${LIBTOOL_VERSION} AUTOCONF=${AUTOCONF} \
			LIBTOOL_M4=${LIBTOOL_M4} \
			AUTOHEADER=${AUTOHEADER}
USE_ICONV=		yes
USE_AUTOTOOLS=		autoconf:262 libtool:22
USE_PERL5=		yes
USE_RC_SUBR=		apache2.sh
SUB_LIST+=		RC_SUBR_SUFFIX=${RC_SUBR_SUFFIX}
USE_APACHE=		common20
LIBTOOLFILES=		configure
USE_LDCONFIG=		${PREFIX}/lib/apache2
USE_BZIP2=		yes

CONFIGURE_ARGS=	--prefix=${PREFIX_RELDEST} \
		--enable-layout=FreeBSD \
		--with-perl=${PERL5} \
		--with-port=${WITH_HTTP_PORT} \
		--with-expat=${LOCALBASE} \
		--with-iconv=${LOCALBASE} \
		--libdir=${PREFIX_RELDEST}/lib/apache2 \
		--includedir=${PREFIX_RELDEST}/include/apache2

CONFIGURE_ENV=	CC="${CC}" CPPFLAGS="${CPPFLAGS}" \
		CFLAGS="${CFLAGS}" \
		LDFLAGS="${LDFLAGS}" CONFIG_SHELL="${SH}" \
		LOCALBASE="${LOCALBASE}"

PREFIX_RELDEST=	${PREFIX:S,^${DESTDIR},,}
RC_SCRIPTS_SUB=	PREFIX=${PREFIX} RC_SUBR=${RC_SUBR}

MAKE_ENV+=	EXPR_COMPAT=yes

WITH_MPM?=	prefork # or worker, perchild, threadpool

WITH_HTTP_PORT?=	80

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

#backward compatibility
.if defined(WITHOUT_SSL)
WITHOUT_SSL_MODULES=	YES
.endif

.if !defined(WITHOUT_SSL_MODULES)
USE_OPENSSL=	yes
.endif

.if defined(WITH_STATIC_SUPPORT)
CONFIGURE_ARGS+=	--enable-static-support
.endif

.if defined(WITH_SSL_EXPERIMENTAL_ENGINE)
CFLAGS+=	-DSSL_EXPERIMENTAL_ENGINE
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

# for slave ports
.if !defined(MASTERDIR)
APACHEDIR=	${.CURDIR}
.else
APACHEDIR=	${MASTERDIR}
.endif

.if defined (WITH_LDAP) || defined (WITH_LDAP_MODULES)
USE_OPENLDAP=		YES
CONFIGURE_ARGS+=	--with-ldap \
			--with-ldap-lib="${LOCALBASE}/lib" \
			--with-ldap-include="${LOCALBASE}/include"
.endif

.include "${APACHEDIR}/Makefile.doc"
.include "${APACHEDIR}/Makefile.modules"
.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700014 && ${ARCH} == i386
BUILD_DEPENDS+=	pkg-config:${PORTSDIR}/devel/pkg-config
.endif

.if exists(${LOCALBASE}/lib/libapr-0.so) || defined(WITH_APR_FROM_PORTS)
IGNORE=	: apr from ports (WITH_APR_FROM_PORTS) is no longer supported
.endif

.if defined(WITH_THREADS)
CONFIGURE_ARGS+=	--enable-threads
.   if ${ARCH} == i386
CONFIGURE_ARGS+=	--enable-nonportable-atomics
.   endif
.endif

CONFIGURE_ARGS+=	--with-mpm=${WITH_MPM:L}

show-options:
	@${SED} -ne 's/^##//p' ${APACHEDIR}/Makefile.doc

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
	@${ECHO_MSG}    "To save apache.org bandwidth, please use the closest"
	@${ECHO_MSG}    "mirror. Hit Ctrl+C now and do a "make print-closest-mirrors."
	@${ECHO_MSG}	"To automatically update /etc/make.conf do:"
	@${ECHO_MSG}	"make print-closest-mirrors >> /etc/make.conf"
	@${ECHO_MSG}	""

post-extract:
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/powerlogo.gif ${WRKSRC}/docs/icons/freebsd.gif

post-patch:
	@cd ${WRKSRC}/docs/docroot && \
	 for f in index.html.*; do (\
	  ${REINPLACE_CMD} -e 's,apache_pb,icons/freebsd.gif"\
		ALT="[Powered by FreeBSD]"><IMG SRC="apache_pb2_ani,g' $$f \
	 ); done
	@${RM} -f ${WRKSRC}/docs/docroot/*.bak
	@${RM} -f ${WRKSRC}/docs/manual/index.html.ko.euc-kr
	@${RM} -f ${WRKSRC}/docs/conf/highperformance-std.conf
	@${REINPLACE_CMD} -e 's," PLATFORM ",FreeBSD,' \
			${WRKSRC}/server/core.c
	@${REINPLACE_CMD} -e 's,freebsd\[2345\],freebsd\[23456\],' \
			${WRKSRC}/srclib/apr/build/apr_hints.m4
	@${INSTALL_DATA} ${WRKSRC}/NOTICE ${WRKSRC}/docs/manual

pre-configure:
	@cd ${WRKSRC}; ${SETENV} ${SCRIPTS_ENV} ./buildconf

post-configure:
	@FTPUSERS=`${EGREP} -v '^#' /etc/ftpusers| ${TR} -s "\n" " "` ;\
	${REINPLACE_CMD} -e "s,%%FTPUSERS%%,$$FTPUSERS, ; \
			s,%%WWWOWN%%,${WWWOWN}, ; \
			s,%%WWWGRP%%,${WWWGRP}, ; \
			s,%%WWWBASEDIR%%,${PREFIX}/www," \
			${WRKSRC}/docs/conf/httpd-std.conf
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX}," \
			${WRKSRC}/support/envvars-std

pre-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@${MKDIR} ${PREFIX}/etc/apache2/envvars.d
	@${MKDIR} ${PREFIX}/etc/apache2/Includes
	@${ECHO_CMD} ""
	@${CAT} ${PKGMESSAGE}
.if !defined(NOPORTDOCS)
	@[ -d ${DOCSDIR}/style/lang/ ] && ${TOUCH} ${DOCSDIR}/style/lang/.keepme
.endif

.include <bsd.port.post.mk>
