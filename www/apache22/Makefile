# New ports collection makefile for:	apache21
# Date created:				Dec 11 2004
# Whom:					Clement Laforet <clement@FreeBSD.org>
#
# $FreeBSD$
#
# For more information, please read Makefile.doc
#

PORTNAME=	apache
PORTVERSION=	2.1.2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_LOCAL:S/%SUBDIR%/clement/}
DISTNAME=	httpd-${PORTVERSION}-alpha
DISTFILES=	${DISTNAME}.tar.gz powerlogo.gif
DIST_SUBDIR=	apache21
EXTRACT_ONLY=	${DISTNAME}.tar.gz

MAINTAINER?=	clement@FreeBSD.org
COMMENT?=	Version 2.1 of Apache web server with ${WITH_MPM:L} MPM.

LIB_DEPENDS=	expat.5:${PORTSDIR}/textproc/expat2

LATEST_LINK=	apache21

CONFLICTS=	apache+mod_ssl-1.* apache+mod_ssl+ipv6-1.* apache+mod_ssl+modsnmp-1.* \
		apache+mod_ssl+mod_snmp+ipv6-1.* apache+mod_ssl+mod_accel-1.* \
		apache+mod_ssl+mod_snmp+mod_accel-1.* \
		apache+ipv6-1.* apache+ssl-1.* apache-1.* apache_fp-1.* \
		caudium-devel-1.* caudium10-1.* caudium12-* \
		ru-apache+mod_ssl-1.* ru-apache-1.* thttpd-2.* \
		apache-2.0.* apache-*-2.0.*

# patch files
.if defined (WITH_WINDOWSUPDATEFIX)
EXTRA_PATCHES+=		${FILESDIR}/exp-windowsupdate.patch
.endif
.if defined(WITH_EXPERIMENTAL_PATCHES)
EXTRA_PATCHES+=		${FILESDIR}/exp-apr-kqueue.patch
.endif

SCRIPTS_ENV+=		LIBTOOL=${LIBTOOL} LIBTOOLIZE=${LIBTOOLIZE} \
			LIBTOOL_VERSION=${LIBTOOL_VERSION} AUTOCONF=${AUTOCONF} \
			LIBTOOL_M4=${LOCALBASE}/share/aclocal/libtool${LIBTOOL_VERSION}.m4 \
			AUTOHEADER=${AUTOHEADER}
USE_ICONV=		yes
USE_AUTOCONF_VER=	259
USE_LIBTOOL_VER=	15
USE_PERL5=		yes
USE_RC_SUBR=		yes
USE_REINPLACE=		yes
LIBTOOLFILES=		configure
INSTALLS_SHILB=		yes
LDCONFIG_DIRS=		${PREFIX}/lib/apache21

CONFIGURE_ARGS=	--prefix=${PREFIX_RELDEST} \
		--enable-layout=FreeBSD \
		--with-perl=${PERL5} \
		--with-port=${WITH_HTTP_PORT} \
		--with-expat=${LOCALBASE} \
		--with-iconv=${LOCALBASE} \
		--libdir=${PREFIX_RELDEST}/lib/apache21 \
		--includedir=${PREFIX_RELDEST}/include/apache21 \
		--enable-http

CONFIGURE_ENV=	CC="${CC}" CPPFLAGS="${CPPFLAGS}" \
		CFLAGS="${CFLAGS}" \
		LDFLAGS="${LDFLAGS}" CONFIG_SHELL="${SH}" \
		LOCALBASE="${LOCALBASE}"

PREFIX_RELDEST=	${PREFIX:S,^${DESTDIR},,}
RC_SCRIPTS_SUB=	PREFIX=${PREFIX} RC_SUBR=${RC_SUBR}

MAKE_ENV+=	DESTDIR=${DESTDIR} EXPR_COMPAT=yes

WITH_MPM?=	prefork # or worker, perchild, threadpool

WITH_HTTP_PORT?=	80

.if defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--disable-ipv6
.else
CATEGORIES+=		ipv6
.   if defined(WITH_IPV6_V6ONLY) && defined(WITHOUT_V4MAPPED)
CONFIGURE_ARGS+=	--disable-v4-mapped
.   else
CONFIGURE_ARGS+=	--enable-v4-mapped
.   endif
.endif

.if !defined(WITHOUT_SSL) || defined(WITHOUT_SSL_MODULES)
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

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libapr-1.so) || defined(WITH_APR_FROM_PORTS)
IGNORE=	: apr from ports is not yet supported
.endif

WITH_PTHREAD_LIBS?=	${PTHREAD_LIBS:S/-l//:S/-//}
WITH_PTHREAD_CFLAGS?=	${PTHREAD_CFLAGS}

.include "${APACHEDIR}/Makefile.doc"
.include "${APACHEDIR}/Makefile.modules"
WANT_APACHE=	common2
.include "${APACHEDIR}/../apache2/Makefile.modules.3rd"

CONFIGURE_ARGS+=	--with-mpm=${WITH_MPM:L} ${CONFIGURE_TARGET}

show-options:
	@${SED} -ne 's/^##//p' ${APACHEDIR}/Makefile.doc

show-categories:
.for category in ${ALL_MODULES_CATEGORIES}
	@${ECHO_MSG} "${category} contains these modules:"
	@${ECHO_MSG} "  ${${category}_MODULES}"
.endfor

show-modules:
	@for module in ${AVAILABLE_MODULES} ; do \
	${ECHO_MSG} -n "$${module}: ";\
	if ${ECHO_CMD} ${APACHE_MODULES} | ${GREP} -wq $${module} 2> /dev/null ; then \
			${ECHO_CMD} -n "enabled "; \
				if ${ECHO_CMD} ${WITH_STATIC_MODULES} | ${GREP} -wq $${module} 2> /dev/null ; then \
					${ECHO_CMD} "(static)" ; \
				else \
					${ECHO_CMD} "(shared)" ;\
				fi;\
			else\
			${ECHO_CMD} disabled ;\
		fi;\
	done

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

post-extract:
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/powerlogo.gif ${WRKSRC}/docs/icons/freebsd.gif

post-patch:
	@${REINPLACE_CMD} -e 's,apache_pb,icons/freebsd.gif" ALT="[Powered by FreeBSD]"><IMG SRC="apache_pb2_ani,g' \
		${WRKSRC}/docs/docroot/index.html
	@${RM} -f ${WRKSRC}/docs/docroot/*.bak
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/apache.sh > ${WRKDIR}/apache21.sh
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/apache21libs.sh > ${WRKDIR}/apache21libs.sh
	@${RM} -f ${WRKSRC}/docs/manual/index.html.ko.euc-kr
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
			s,%%WWWGRP%%,${WWWGRP}, " \
			${WRKSRC}/docs/conf/httpd-std.conf

pre-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@${MKDIR} ${PREFIX}/etc/apache21/Includes
.if !defined(WITH_APR_FROM_PORTS)
	@${ECHO_CMD} "Installing ${PREFIX}/etc/rc.d/000.apache21libs.sh startup script."
	@${INSTALL_SCRIPT} -m 751 ${WRKDIR}/apache21libs.sh ${PREFIX}/etc/rc.d/000.apache21libs.sh
.endif
	@${ECHO_CMD} "Installing ${PREFIX}/etc/rc.d/apache21.sh startup script."
	@${INSTALL_SCRIPT} -m 751 ${WRKDIR}/apache21.sh ${PREFIX}/etc/rc.d/apache21.sh
	@@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
