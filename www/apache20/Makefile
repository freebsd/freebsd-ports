# New ports collection makefile for:	apache2
# Date created:				7 April 2001
# Whom:					Hye-Shik Chang <perky@fallin.lv>
#
# $FreeBSD$
#
# For more information, please read Makefile.doc
#

PORTNAME=	apache
PORTVERSION=	2.0.50
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_APACHE_HTTPD} \
		http://sheepkiller.nerim.net/ports/${PORTNAME}/:powerlogo
DISTNAME=	httpd-${PORTVERSION}
DISTFILES=	${DISTNAME}.tar.gz powerlogo.gif:powerlogo
DIST_SUBDIR=	apache2
EXTRACT_ONLY=	${DISTNAME}.tar.gz

MAINTAINER?=	clement@FreeBSD.org
COMMENT?=	Version 2 of Apache web server with ${WITH_MPM:L} MPM.

LIB_DEPENDS=	expat.5:${PORTSDIR}/textproc/expat2

LATEST_LINK=	apache2

CONFLICTS=	apache+mod_ssl-1.* apache+mod_ssl+ipv6-1.* apache+mod_ssl+modsnmp-1.* \
		apache+mod_ssl+mod_snmp+ipv6-1.* apache+mod_ssl+mod_accel-1.* \
		apache+mod_ssl+mod_snmp+mod_accel-1.* \
		apache+ipv6-1.* apache+ssl-1.* apache-1.* apache_fp-1.* \
		caudium-devel-1.* caudium10-1.* caudium12-* \
		ru-apache+mod_ssl-1.* ru-apache-1.* thttpd-2.*

# patch files
.if defined (WITH_WINDOWSUPDATEFIX)
EXTRA_PATCHES+=		${FILESDIR}/exp-windowsupdate.patch
.endif
.if defined(WITH_EXPERIMENTAL_PATCHES)
EXTRA_PATCHES+=		${FILESDIR}/exp-apr-kqueue.patch \
			${FILESDIR}/exp-http-ready.patch
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

.if !defined(WITHOUT_SSL)
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

.if defined (WITH_LDAP)
USE_OPENLDAP=		YES
CONFIGURE_ARGS+=	--with-ldap \
			--with-ldap-lib="${LOCALBASE}/lib" \
			--with-ldap-include="${LOCALBASE}/include"
.endif

.include <bsd.port.pre.mk>

# Untested and may fail !
.if defined(WITH_APR_FROM_PORTS)
.    if defined (WITH_BDB) || defined(WITH_BERKELEYDB)
IGNORE=			"You can't set WITH_BDB or WITH_BERKELEYDB when WITH_APR_FROM_PORTS is defined"
.    endif
LIB_DEPENDS+=		apr-0.9:${PORTSDIR}/devel/apr
CONFIGURE_ARGS+=	--with-apr=${LOCALBASE}/bin/apr-config \
			--with-apr-util=${LOCALBASE}/bin/apu-config
CONFIGURE_ENV+=		LTFLAGS="--tag=CXX"
PLIST_SUB+=	PORTS_APR="@comment "
.else
.   if exists(${LOCALBASE}/lib/libapr-0.so)
IGNORE=			apr is installed and may conflict with apache one\
				(if you want to use apr port define WITH_APR_FROM_PORTS,\
				at your own risk)
.   endif
PLIST_SUB+=	PORTS_APR=""
INSTALLS_SHLIB=		yes
LDCONFIG_DIRS=		%%PREFIX%%/lib/apache2
.endif

WITH_PTHREAD_LIBS?=	${PTHREAD_LIBS:S/-l//}
WITH_PTHREAD_CFLAGS?=	${PTHREAD_CFLAGS}

.include "${APACHEDIR}/Makefile.doc"
.include "${APACHEDIR}/Makefile.modules"
WANT_APACHE=	common2
.include "${APACHEDIR}/Makefile.modules.3rd"

CONFIGURE_ARGS+=	--with-mpm=${WITH_MPM:L} ${CONFIGURE_TARGET}

show-options:
	@${SED} -ne 's/^##//p' ${APACHEDIR}/Makefile.doc

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
	@${ECHO_MSG}	"  To see all available knobs, type make show-options"
	@${ECHO_MSG}    "  You can check your modules configuration by using show-modules"
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
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/apache.sh > ${WRKDIR}/apache2.sh
.if !defined(WITH_APR_FROM_PORTS)
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/apache2libs.sh > ${WRKDIR}/apache2libs.sh
.endif
	@${RM} -f ${WRKSRC}/docs/manual/index.html.ko.euc-kr
	@${REINPLACE_CMD} -e 's," PLATFORM ",FreeBSD,' \
			${WRKSRC}/server/core.c
	@${INSTALL_DATA} ${WRKSRC}/NOTICE ${WRKSRC}/docs/manual

pre-configure:
	@cd ${WRKSRC}; ${SETENV} ${SCRIPTS_ENV} ./buildconf

post-configure:
	@FTPUSERS=`${EGREP} -v '^#' /etc/ftpusers| ${TR} -s "\n" " "` ;\
	${REINPLACE_CMD} -e "s,%%FTPUSERS%%,$$FTPUSERS," \
			${WRKSRC}/docs/conf/httpd-std.conf

pre-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@${MKDIR} ${PREFIX}/etc/apache2/Includes
.if !defined(WITH_APR_FROM_PORTS)
	@${ECHO_CMD} "Installing ${PREFIX}/etc/rc.d/000.apache2libs.sh startup file."
	@${INSTALL_SCRIPT} -m 751 ${WRKDIR}/apache2libs.sh ${PREFIX}/etc/rc.d/000.apache2libs.sh
.endif
	@${ECHO_CMD} "Installing ${PREFIX}/etc/rc.d/apache2.sh startup file."
	@${INSTALL_SCRIPT} -m 751 ${WRKDIR}/apache2.sh ${PREFIX}/etc/rc.d/apache2.sh
	@@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
