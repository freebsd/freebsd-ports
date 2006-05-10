# New ports collection makefile for:	apache22
# Date created:				Dec 11 2004
# Whom:					Clement Laforet <clement@FreeBSD.org>
#
# $FreeBSD$
#
# For more information, please read Makefile.doc
#

PORTNAME=	apache
PORTVERSION=	2.2.2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_APACHE_HTTPD} \
		http://apache.webthing.com/database/:aprmysql
DISTNAME=	httpd-${PORTVERSION}
DISTFILES=	${DISTNAME}.tar.bz2 \
		apr_dbd_mysql.c:aprmysql
DIST_SUBDIR=	apache22
EXTRACT_ONLY=	${DISTNAME}.tar.bz2

MAINTAINER?=	clement@FreeBSD.org
COMMENT?=	Version 2.2 of Apache web server with ${WITH_MPM:L} MPM.

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2
BUILD_DEPENDS=	python:${PORTSDIR}/lang/python

LATEST_LINK=	apache22

CONFLICTS=	apache+mod_ssl-1.* apache+mod_ssl+ipv6-1.* apache+mod_ssl+modsnmp-1.* \
		apache+mod_ssl+mod_snmp+ipv6-1.* apache+mod_ssl+mod_accel-1.* \
		apache+mod_ssl+mod_snmp+mod_accel-1.* \
		apache+ipv6-1.* apache+ssl-1.* apache-1.* apache_fp-1.* \
		caudium-devel-1.* caudium10-1.* caudium12-* \
		ru-apache+mod_ssl-1.* ru-apache-1.* thttpd-2.* \
		apache-2.0.* apache-*-2.0.* apache-2.1.* apache-*-2.1.*

SCRIPTS_ENV+=		LIBTOOL=${LIBTOOL} LIBTOOLIZE=${LIBTOOLIZE} \
			LIBTOOL_VERSION=${LIBTOOL_VERSION} AUTOCONF=${AUTOCONF} \
			LIBTOOL_M4=${LOCALBASE}/share/aclocal/libtool${LIBTOOL_VERSION}.m4 \
			AUTOHEADER=${AUTOHEADER}

USE_APACHE=		common22
USE_BZIP2=		yes
USE_ICONV=		yes
USE_AUTOTOOLS=	autoconf:259 libtool:15
USE_PERL5=		yes
USE_RC_SUBR=		yes
USE_REINPLACE=		yes
LIBTOOLFILES=		configure

.if !defined(WITH_APR_FROM_PORTS)
INSTALLS_SHLIB=		yes
.endif

CONFIGURE_ARGS=	--prefix=${PREFIX_RELDEST} \
		--enable-layout=FreeBSD \
		--with-perl=${PERL5} \
		--with-port=${WITH_HTTP_PORT} \
		--with-expat=${LOCALBASE} \
		--with-iconv=${LOCALBASE} \
		--enable-http

CONFIGURE_ENV=	CC="${CC}" CPPFLAGS="${CPPFLAGS}" \
		CFLAGS="${CFLAGS}" \
		LDFLAGS="${LDFLAGS}" CONFIG_SHELL="${SH}" \
		LOCALBASE="${LOCALBASE}"

PREFIX_RELDEST=	${PREFIX:S,^${DESTDIR},,}
RC_SCRIPTS_SUB=	PREFIX=${PREFIX} RC_SUBR=${RC_SUBR}

MAKE_ENV+=	DESTDIR=${DESTDIR} EXPR_COMPAT=yes

WITH_MPM?=	prefork # or worker, perchild, threadpool, event

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

.if !defined(WITHOUT_SSL_MODULES)
USE_OPENSSL=	yes
.endif

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

.if defined(WITH_APR_FROM_PORTS)
PLIST_SUB+=	APR_PORTS="@comment "
LIB_DEPENDS+=	apr-1:${PORTSDIR}/devel/apr
CONFIGURE_ARGS+=	--with-apr=${LOCALBASE}/bin/apr-1-config \
			--with-apr-util=${LOCALBASE}/bin/apu-1-config
CONFIGURE_ENV+=		LTFLAGS="--tag=CXX"
.else
PLIST_SUB+=	APR_PORTS=""
CONFLICTS+=	apr-1.*
CONFIGURE_ENV+=	USE_BUNDLED_APR=YES
.endif

.if defined(WITH_THREADS)
CONFIGURE_ARGS+=	--enable-threads
.   if ${OSVERSION} > 500023
.     if ${ARCH} == i386
CONFIGURE_ARGS+=	--enable-nonportable-atomics
.     endif
.   endif
.endif

CONFIGURE_ARGS+=	--with-mpm=${WITH_MPM:L} ${CONFIGURE_TARGET}

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

post-extract:
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/apr_dbd_mysql.c \
		${WRKSRC}/srclib/apr-util/dbd

post-patch:
	@${RM} -f ${WRKSRC}/docs/docroot/*.bak
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/apache.sh > ${WRKDIR}/apache22.sh
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

install-startup-script:
.if !exists(${WRKDIR}/apache22.sh)
	@${MKDIR} ${WRKDIR}
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/apache.sh > ${WRKDIR}/apache22.sh
.endif
	@${ECHO_CMD} "Installing ${PREFIX}/etc/rc.d/apache22.sh startup script."
	@${INSTALL_SCRIPT} -m 555 ${WRKDIR}/apache22.sh ${PREFIX}/etc/rc.d/apache22.sh

post-install: install-startup-script
	@${MKDIR} ${PREFIX}/etc/apache22/envvars.d
	@${MKDIR} ${PREFIX}/etc/apache22/Includes
	@${INSTALL_DATA} ${FILESDIR}/no-accf.conf ${PREFIX}/etc/apache22/Includes
.if !defined(NOPORTDOCS)
	@[ -d ${DOCSDIR}/style/lang/ ] && ${TOUCH} ${DOCSDIR}/style/lang/.keepme
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
