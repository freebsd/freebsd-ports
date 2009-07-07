# New ports collection makefile for:	Apache + mod_ssl
# Date created:		Sat Aug 22 12:00:00 CDT 1998
# Whom:			rse@engelschall.com
#
# $FreeBSD$
#

PORTNAME=	apache+mod_ssl
PORTVERSION=	${VERSION_APACHE}+${VERSION_MODSSL}
PORTREVISION?=	0
CATEGORIES?=	www security
MASTER_SITES=	${MASTER_SITE_APACHE_HTTPD} \
		${MASTER_SITES_MODSSL:S/$/:mod_ssl/} \
		http://www.mod-snmp.com/distr/:mod_snmp \
		http://sysoev.ru/mod_accel/:mod_accel \
		http://sysoev.ru/mod_deflate/:mod_deflate
PKGNAMESUFFIX?=	${MODSNMP_SUFFIX}${MODACCEL_SUFFIX}${MODDEFLATE_SUFFIX}${IPV6_SUFFIX}${PKGNAMESUFFIX2}
DISTNAME=	apache_${VERSION_APACHE}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${MODSSL_FILE}:mod_ssl \
		${MODSNMP_DISTFILE} ${MODACCEL_DISTFILE} ${MODDEFLATE_DISTFILE}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} ${MODSSL_FILE} \
		${MODACCEL_FILE} ${MODDEFLATE_FILE}

.if defined(WITH_APACHE_IPV6) || defined(APACHE_WITH_IPV6) || make(makesum) || defined(FETCH_ALL)
PATCH_SITES+=	ftp://ftp.42.org/pub/orphan/ ${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	dinoex
PATCHFILES+=	apache-1.3.34modssl-v6-20051019.diff.gz
.endif

MAINTAINER=	dinoex@FreeBSD.org
COMMENT?=	The Apache 1.3 webserver with SSL/TLS functionality

LIB_DEPENDS=	mm.14:${PORTSDIR}/devel/mm
PATCH_DEPENDS=	${BUILD_DEPENDS}

CONFLICTS?=	apache+ipv6-1.* apache+ssl-1.* apache-1.* apache-2.* \
		apache_fp-1.* caudium-devel-1.* caudium10-1.* caudium12-* \
		ru-apache+mod_ssl-1.* ru-apache-1.* w3c-httpd-3.*
VERSION_APACHE=	1.3.41
VERSION_MODSSL=	2.8.31
VERSION_MODSNMP=	1.3.14.13
VERSION_MODACCEL=	1.0.34
VERSION_MODDEFLATE=	1.0.21
USE_OPENSSL=	yes
HAS_CONFIGURE=	yes
.if defined(WITH_PERL)
USE_PERL5_RUN=	yes
.else
USE_PERL5_BUILD=	yes
.endif
MASTER_SITES_MODSSL=	http://www.modssl.org/source/ \
		ftp://ftp.modssl.org/source/ \
		ftp://ftp.blatzheim.com/pub/mod_ssl/ \
		ftp://ftp.fu-berlin.de/unix/security/mod_ssl/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/www/mod_ssl/source,}
MODSSL_FILE=	mod_ssl-${VERSION_MODSSL}-${VERSION_APACHE}${EXTRACT_SUFX}
MODSNMP_FILE=	mod_snmp_${VERSION_MODSNMP}${EXTRACT_SUFX}
RC_SCRIPTS_SUB=	PREFIX=${PREFIX} RC_SUBR=${RC_SUBR}

USE_RC_SUBR=	yes

.include <bsd.port.pre.mk>

DOCSDIR=	${PREFIX}/share/doc/apache
.if defined(APACHE_DATADIR)
DATADIR=	${APACHE_DATADIR}
.else
DATADIR=	${PREFIX}/www
.endif
.if defined(APACHE_DOCUMENT_ROOT)
DOCUMENT_ROOT=	${APACHE_DOCUMENT_ROOT}
.else
DOCUMENT_ROOT=	${DATADIR}/data
.endif
.if defined(APACHE_CGIBIN_ROOT)
CGIBIN_ROOT=	${APACHE_CGIBIN_ROOT}
.else
CGIBIN_ROOT=${DATADIR}/cgi-bin
.endif
DEFAULT_PATH?=	${PREFIX}/bin:/bin:/usr/bin
APACHE_LOCALSTATE_DIR?=	/var
APACHE_LOGFILE_DIR?=	${APACHE_LOCALSTATE_DIR}/log

.if exists(${LOCALBASE}/include/fnmatch.h)
check-depends::
	@${PKG_INFO} -W ${LOCALBASE}/include/fnmatch.h
	@${ECHO_CMD} "Dependency error, please do: pkg_delete " \
		`${PKG_INFO} -q -W ${LOCALBASE}/include/fnmatch.h`
	@${FALSE}
.endif

APACHE_SH?=	etc/rc.d/apache

PLIST_FILES+=	${APACHE_SH}

.if defined(WITH_APACHE_SUEXEC) && !defined(WITHOUT_APACHE_SUEXEC)

APACHE_SUEXEC_DOCROOT?=${DOCUMENT_ROOT}
APACHE_SUEXEC_LOG?=/var/log/httpd-suexec.log
APACHE_SUEXEC_USERDIR?=public_html
APACHE_SUEXEC_UIDMIN?=1000
APACHE_SUEXEC_GIDMIN?=1000
APACHE_SUEXEC_CALLER?=www
APACHE_SUEXEC_SAFE_PATH?=/bin:/usr/bin:${PREFIX}/bin

SUEXEC_CONF=	--enable-suexec \
		--suexec-docroot=${APACHE_SUEXEC_DOCROOT} \
		--suexec-caller=${APACHE_SUEXEC_CALLER} \
		--suexec-uidmin=${APACHE_SUEXEC_UIDMIN} \
		--suexec-gidmin=${APACHE_SUEXEC_GIDMIN} \
		--suexec-logfile=${APACHE_SUEXEC_LOG} \
		--suexec-userdir=${APACHE_SUEXEC_USERDIR} \
		--suexec-safepath=${APACHE_SUEXEC_SAFE_PATH}

.if defined(APACHE_SUEXEC_UMASK)
SUEXEC_CONF+=	--suexec-umask=${APACHE_SUEXEC_UMASK}
.endif

PLIST_FILES+=	sbin/suexec
SUEXEC_MAN=	suexec.8

.else   # !SUEXEC

SUEXEC_CONF=
SUEXEC_MAN=

.endif  # !SUEXEC

CONFIGURE_ARGS+=--prefix=${PREFIX} \
		--server-uid=www \
		--server-gid=www \
		--with-perl=${PERL} \
		--with-layout=FreeBSD \
		--datadir=${DATADIR} \
		--htdocsdir=${DOCUMENT_ROOT} \
		--cgidir=${CGIBIN_ROOT} \
		--localstatedir=${APACHE_LOCALSTATE_DIR} \
		--logfiledir=${APACHE_LOGFILE_DIR} \
		--without-confadjust \
		--enable-module=most \
		--enable-module=auth_db \
		--enable-module=mmap_static \
		--disable-module=auth_dbm \
		--enable-shared=max \
		--enable-module=ssl \
		--enable-module=define \
		${SUEXEC_CONF}

.if defined(APACHE_RELATIVE_RUNTIMEDIR)
CONFIGURE_ARGS+=	--runtimedir=${APACHE_RELATIVE_RUNTIMEDIR}
.endif

.if defined(WITHOUT_APACHE_EXPAT) || defined(APACHE_WITHOUT_EXPAT)
CONFIGURE_ARGS+=	--disable-rule=EXPAT
.else
.if !defined(WITH_APACHE_INTERNAL_EXPAT)
LIB_DEPENDS+=	expat.6:${PORTSDIR}/textproc/expat2
LDFLAGS+=	-L${LOCALBASE}/lib
.endif
CONFIGURE_ARGS+=	--enable-rule=EXPAT
.endif

.if defined(APACHE_HARD_SERVER_LIMIT)
HARD_SERVER_LIMIT=-DHARD_SERVER_LIMIT=${APACHE_HARD_SERVER_LIMIT}
.else
HARD_SERVER_LIMIT=-DHARD_SERVER_LIMIT=512
.endif

OPTIM=		${HARD_SERVER_LIMIT} \
		-DDOCUMENT_LOCATION=\\"${DOCUMENT_ROOT}\\" \
		-DDEFAULT_PATH=\\"${DEFAULT_PATH}\\" \
		-DACCEPT_FILTER_NAME=\\"httpready\\"

.if defined(APACHE_FD_SETSIZE)
OPTIM+=		-DFD_SETSIZE=${APACHE_FD_SETSIZE}
.else
OPTIM+=		-DFD_SETSIZE=1024
.endif

.if defined(APACHE_BUFFERED_LOGS)
OPTIM+=		-DBUFFERED_LOGS
.endif

.if defined(APACHE_PERF_TUNING)
CFLAGS+=	-O3
.endif
.if defined(WITH_APACHE_PERF_TUNING) && !defined(WITHOUT_APACHE_PERF_TUNING)
CFLAGS+=	-O3
.endif

.if defined(WITH_APACHE_MODSNMP) || defined(APACHE_WITH_MODSNMP) || make(makesum) || defined(FETCH_ALL)
MODSNMP_DISTFILE=	${MODSNMP_FILE}:mod_snmp
.endif
.if defined(WITH_APACHE_MODSNMP) || defined(APACHE_WITH_MODSNMP)
CONFLICTS+=	apache+mod_ssl-1.* \
		apache+mod_ssl+ipv6-1.* \
		apache+mod_ssl+mod_accel-1.* \
		apache+mod_ssl+mod_accel+ipv6-1.* \
		apache+mod_ssl+mod_accel+mod_deflate-1.* \
		apache+mod_ssl+mod_accel+mod_deflate+ipv6-1.* \
		apache+mod_ssl+mod_deflate-1.* \
		apache+mod_ssl+mod_deflate+ipv6-1.*
MODSNMP_SUFFIX=	+mod_snmp
CONFIGURE_ARGS+=	--activate-module=src/modules/snmp_agt/libsnmp_agt.a
CFLAGS+=	-DSNMP -DUSE_DB -DSNMP_CONFIG_H -DHARD_VIRTUAL_HOST_MAX=1000 \
		-DSNMPLOCALONLY
EXTRA_PATCHES+=	${WRKSRC}/src/modules/snmp_agt/mod_snmp.patch
PLIST_FILES+=	%%DOCSDIR%%/mod/mod_snmp.html \
		%%DOCSDIR%%/snmp_agt/index.html \
		%%DOCSDIR%%/snmp_agt/www-mib.txt \
		%%DOCSDIR%%/snmp_agt/snmpv2-mib.txt \
		%%DOCSDIR%%/snmp_agt/rfc2594.txt \
		%%DOCSDIR%%/snmp_agt/apache-scoreboard-mib.txt \
		%%DOCSDIR%%/snmp_agt/apache-config-mib.txt
PLIST_DIRS+=	%%DOCSDIR%%/snmp_agt %%DOCSDIR%% www/buckets www
.else
CONFLICTS+=	apache+*mod_snmp*-1.*
.endif

.if defined(WITH_APACHE_MODACCEL) || defined(APACHE_WITH_MODACCEL) || make(makesum) || defined(FETCH_ALL)
MODACCEL_FILE=	mod_accel-${VERSION_MODACCEL}${EXTRACT_SUFX}
MODACCEL_DISTFILE=	${MODACCEL_FILE}:mod_accel
.endif
.if defined(WITH_APACHE_MODACCEL) || defined(APACHE_WITH_MODACCEL)
CONFLICTS+=	apache+mod_ssl-1.* \
		apache+mod_ssl+ipv6-1.* \
		apache+mod_ssl+mod_snmp-1.* \
		apache+mod_ssl+mod_snmp+ipv6-1.* \
		apache+mod_ssl+mod_snmp+mod_deflate-1.* \
		apache+mod_ssl+mod_snmp+mod_deflate+ipv6-1.* \
		apache+mod_ssl+mod_deflate-1.* \
		apache+mod_ssl+mod_deflate+ipv6-1.*
MODACCEL_SUFFIX=	+mod_accel
CONFIGURE_ARGS+=	--activate-module=src/modules/extra/mod_randban.o \
		--enable-shared=randban \
		--activate-module=src/modules/extra/mod_freeze.o \
		--enable-shared=freeze \
		--activate-module=src/modules/accel/libaccel.a \
		--enable-shared=accel
EXTRA_PATCHES+=	${FILESDIR}/mod_accel-preservehost.patch ${FILESDIR}/mod_accel-Makefile.tmpl.patch
PLIST_FILES+=	libexec/apache/libaccel.so \
		libexec/apache/mod_freeze.so \
		libexec/apache/mod_randban.so \
		%%DOCSDIR%%/mod/mod_accel.html
.else
CONFLICTS+=	apache+*mod_accel*-1.*
.endif

.if defined(WITH_APACHE_MODDEFLATE) || defined(APACHE_WITH_MODDEFLATE) || make(makesum) || defined(FETCH_ALL)
MODDEFLATE_FILE=	mod_deflate-${VERSION_MODDEFLATE}${EXTRACT_SUFX}
MODDEFLATE_DISTFILE=	${MODDEFLATE_FILE}:mod_deflate
.endif
.if defined(WITH_APACHE_MODDEFLATE) || defined(APACHE_WITH_MODDEFLATE)
CONFLICTS+=	apache+mod_ssl-1.* \
		apache+mod_ssl+ipv6-1.* \
		apache+mod_ssl+mod_snmp-1.* \
		apache+mod_ssl+mod_snmp+ipv6-1.* \
		apache+mod_ssl+mod_snmp+mod_accel-1.* \
		apache+mod_ssl+mod_snmp+mod_accel+ipv6-1.* \
		apache+mod_ssl+mod_accel-1.* \
		apache+mod_ssl+mod_accel+ipv6-1.*
MODDEFLATE_SUFFIX=	+mod_deflate
CONFIGURE_ARGS+=	--activate-module=src/modules/extra/mod_deflate.o
PLIST_FILES+=	%%DOCSDIR%%/mod/mod_deflate.html
.else
CONFLICTS+=	apache+*mod_deflate*-1.*
.endif

.if defined(WITH_APACHE_IPV6) || defined(APACHE_WITH_IPV6)
.if defined(WITH_APACHE_MODACCEL) || defined(APACHE_WITH_MODACCEL)
BROKEN=		"mod_accel and ipv6 don't compile together"
.endif

CONFLICTS+=	apache+mod_ssl-1.* \
		apache+mod_ssl+mod_snmp-1.* \
		apache+mod_ssl+mod_snmp+mod_accel-1.* \
		apache+mod_ssl+mod_snmp+mod_accel+mod_deflate-1.* \
		apache+mod_ssl+mod_accel-1.* \
		apache+mod_ssl+mod_accel+mod_deflate-1.* \
		apache+mod_ssl+mod_deflate-1.*
IPV6_SUFFIX=	+ipv6
CONFIGURE_ARGS+=	--enable-rule=INET6
PLIST_SUB+=	WITHIPV6=""
PLIST_FILES+=	include/apache/sa_len.h \
		include/apache/sockaddr_storage.h
.endif

.if defined(WITH_APACHE_LATESTLOG)
EXTRA_PATCHES+=	${FILESDIR}/rotatelogs.c.patch
.endif

CONFIGURE_ENV=	CFLAGS='${CFLAGS}' \
		LDFLAGS='${LDFLAGS}' \
		OPTIM='${OPTIM}' \
		SSL_BASE='${OPENSSLBASE}' \
		EAPI_MM='SYSTEM' \
		PATH="${PREFIX}/bin:${PATH}"

INSTALL_TARGET=	install-quiet

MAN1=	dbmmanage.1 htdigest.1 htpasswd.1
MAN8=	ab.8 apachectl.8 apxs.8 httpd.8 logresolve.8 rotatelogs.8 \
	${SUEXEC_MAN}

TYPE=	test
CRT=
KEY=

pre-fetch:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may use the following build options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "  WITH_APACHE_SUEXEC=yes	enable the suEXEC feature"
	@${ECHO_MSG} "				[default is no]"
	@${ECHO_MSG} "  APACHE_SUEXEC_CALLER=user	set the suEXEC username of the allowed caller"
	@${ECHO_MSG} "				[default is www]"
	@${ECHO_MSG} "  APACHE_SUEXEC_DOCROOT=dir	set the suEXEC root directory"
	@${ECHO_MSG} "				[default is ${DOCUMENT_ROOT}]"
	@${ECHO_MSG} "  APACHE_SUEXEC_LOG=file	set the suEXEC logfile"
	@${ECHO_MSG} "				[default is /var/log/httpd-suexec.log]"
	@${ECHO_MSG} "  APACHE_SUEXEC_USERDIR=dir	set the suEXEC user subdirectory"
	@${ECHO_MSG} "				[default is public_html]"
	@${ECHO_MSG} "  APACHE_SUEXEC_UIDMIN=uid	set the suEXEC minimal allowed UID"
	@${ECHO_MSG} "				[default is 1000]"
	@${ECHO_MSG} "  APACHE_SUEXEC_GIDMIN=gid	set the suEXEC minimal allowed GID"
	@${ECHO_MSG} "				[default is 1000]"
	@${ECHO_MSG} "  APACHE_SUEXEC_SAFE_PATH=path	set the suEXEC safe PATH"
	@${ECHO_MSG} "				[default is /bin:/usr/bin:${PREFIX}/bin]"
	@${ECHO_MSG} "  APACHE_SUEXEC_UMASK=umask	set the umask for the suEXEC'd script"
	@${ECHO_MSG} "				[default is inherited from the Apache process]"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "  APACHE_DATADIR=path		set data directory PATH"
	@${ECHO_MSG} "				[default is ${PREFIX}/www]"
	@${ECHO_MSG} "  APACHE_CGIBIN_ROOT=path	set CGIBIN directory PATH"
	@${ECHO_MSG} "				the default is derived from APACHE_DATADIR"
	@${ECHO_MSG} "				[currently the default is ${DATADIR}/cgibin]"
	@${ECHO_MSG} "  APACHE_DOCUMENT_ROOT=path	set documents directory PATH"
	@${ECHO_MSG} "				the default is derived from APACHE_DATADIR"
	@${ECHO_MSG} "				[currently the default is ${DATADIR}/data]"
	@${ECHO_MSG} "  APACHE_LOCALSTATE_DIR=path	set modifiable data PATH"
	@${ECHO_MSG} "				[default is /var]"
	@${ECHO_MSG} "  APACHE_LOGFILE_DIR=path 	set logfile directory PATH"
	@${ECHO_MSG} "				the default is derived from APACHE_LOCALSTATE_DIR"
	@${ECHO_MSG} "				[currently the default is ${APACHE_LOCALSTATE_DIR}/log]"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "  APACHE_HARD_SERVER_LIMIT=nr	Maximum number of Apache processes."
	@${ECHO_MSG} "				[default is 512]"
	@${ECHO_MSG} "  APACHE_FD_SETSIZE=nr		Maximum number of descriptors."
	@${ECHO_MSG} "				[default is 1024]"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "  APACHE_BUFFERED_LOGS=yes	Log entries are buffered before writing."
	@${ECHO_MSG} "				Writes may not be atomic, entries from multiple"
	@${ECHO_MSG} "				children could become mixed together and your"
	@${ECHO_MSG} "				web stats may be inaccurate."
	@${ECHO_MSG} "				[default is no]"
	@${ECHO_MSG} "  WITH_APACHE_PERF_TUNING=yes	CFLAGS optimization."
	@${ECHO_MSG} "				This setting may produce broken code and thus"
	@${ECHO_MSG} "				is not recommended for production servers."
	@${ECHO_MSG} "				[default is no]"
	@${ECHO_MSG} "  WITH_APACHE_LATESTLOG=yes	keep a hardlink on the lastest log."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "  WITH_APACHE_IPV6=yes		IPv6 support."
	@${ECHO_MSG} "				This setting turns IPv6 support on."
	@${ECHO_MSG} "				[default is no]"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "  WITH_APACHE_MODSNMP=yes	mod_snmp support."
	@${ECHO_MSG} "				This setting turns support for SNMP on."
	@${ECHO_MSG} "				[default is no]"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "  WITH_APACHE_MODACCEL=yes	mod_accel support."
	@${ECHO_MSG} "				This setting activates build of mod_accel."
	@${ECHO_MSG} "				[default is no]"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "  WITH_APACHE_MODDEFLATE=yes	mod_deflate support."
	@${ECHO_MSG} "				This setting activates build of mod_deflate."
	@${ECHO_MSG} "				[default is no]"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "  WITHOUT_APACHE_EXPAT=yes	don't compile in expat."
	@${ECHO_MSG} "				[default is no (expat is included)]"
	@${ECHO_MSG} ""

post-extract:
	@${SED}	${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/rcng.sh > ${WRKSRC}/rcng.sh
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' \
		${WRKSRC}/src/Configure
.if defined(WITH_APACHE_MODSNMP) || defined(APACHE_WITH_MODSNMP)
	(cd ${WRKSRC}; ${TAR} xfz  ${DISTDIR}/${MODSNMP_FILE})
.endif

pre-patch:
	@cd ${WRKDIR}/mod_ssl-${VERSION_MODSSL}-${VERSION_APACHE} \
	&& ${ECHO_MSG} "===>  Applying mod_ssl-${VERSION_MODSSL} extension" \
	&& ./configure --with-apache=../${DISTNAME} --expert
.if defined(WITH_APACHE_MODACCEL) || defined(APACHE_WITH_MODACCEL)
	@cd ${WRKDIR}/mod_accel-${VERSION_MODACCEL} \
	&& ${ECHO_MSG} "===>  Applying mod_accel-${VERSION_MODACCEL} extension" \
	&& ./configure --with-apache=../${DISTNAME} --with-mod_randban --with-mod_freeze \
	&& ${MAKE}
.endif
.if defined(WITH_APACHE_MODDEFLATE) || defined(APACHE_WITH_MODDEFLATE)
	@cd ${WRKDIR}/mod_deflate-${VERSION_MODDEFLATE} \
	&& ${ECHO_MSG} "===>  Applying mod_deflate-${VERSION_MODDEFLATE} extension" \
	&& ./configure --with-apache=../${DISTNAME} \
	&& ${MAKE}
.endif

post-patch:
	@${PERL} -pi -e 's|-print|-print0|;s|xargs|xargs -0|' \
		${WRKSRC}/Makefile.tmpl
	@${PERL} -pi -e "s|SSL_LDFLAGS=''|SSL_LDFLAGS='${OPENSSL_LDFLAGS}'|" \
		${WRKSRC}/src/modules/ssl/libssl.module
	@cd ${WRKSRC} \
	&& ${FIND} . -type f -name "*.orig" -print | ${XARGS} ${RM} -f

post-build:
	@cd ${WRKSRC} \
	&& ${ECHO_MSG} "===>  Creating Dummy Certificate for Server (SnakeOil)" \
	&& ${ECHO_MSG} "      [use 'make certificate' to create a real one]" \
	&& ${MAKE} certificate TYPE=dummy >/dev/null 2>&1

certificate:
	@cd ${WRKSRC} \
	&& ${ECHO_MSG} "===>  Creating Test Certificate for Server" \
	&& ${MAKE} certificate TYPE=${TYPE} CRT=${CRT} KEY=${KEY}

pre-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rcng.sh ${PREFIX}/${APACHE_SH}
.if defined(WITH_APACHE_MODSNMP) || defined(APACHE_WITH_MODSNMP)
	@${MKDIR} ${DATADIR}/buckets
	@${CHOWN} www:www ${DATADIR}/buckets
.endif

.include <bsd.port.post.mk>
