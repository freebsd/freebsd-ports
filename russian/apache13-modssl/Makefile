# New ports collection makefile for:	Russian Apache + mod_ssl
# Date created:		7 July 2000 1:05 MSD
# Whom:			Dmitry Sivachenko <dima@Chg.RU>
#
# $FreeBSD$
#

PORTNAME=	apache+mod_ssl
PORTVERSION=	${VERSION_APACHE}+${VERSION_RA}+${VERSION_MODSSL}
CATEGORIES=	russian www security
MASTER_SITES=	${MASTER_SITE_APACHE_HTTPD} \
		${MASTER_SITES_MODSSL:S/$/:modssl/} \
		${MASTER_SITES_RA:S/$/:rapatches/}
DISTNAME=	apache_${VERSION_APACHE}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		mod_ssl-${VERSION_MODSSL}-${VERSION_APACHE}${EXTRACT_SUFX}:modssl \
		patches_${VERSION_APACHE}rusPL${VERSION_RA}.tar.gz:rapatches

MAINTAINER=	lev@FreeBSD.org
COMMENT=	The Russian Apache webserver with SSL/TLS functionality

LIB_DEPENDS=	mm.13:${PORTSDIR}/devel/mm

MASTER_SITES_MODSSL=	http://www.modssl.org/source/ \
			ftp://ftp.modssl.org/source/ \
			ftp://ftp.pca.dfn.de/pub/tools/net/mod_ssl/ \
			ftp://ftp.ecrc.net/pub/security/mod_ssl/ \
			ftp://ftp.nvg.ntnu.no/pub/unix/mod_ssl/ \
			ftp://ftp.ulpgc.es/pub/mod_ssl/ \
			ftp://glock.missouri.edu/pub/mod_ssl/ \
			ftp://ftp.fu-berlin.de/unix/security/mod_ssl/ \
			ftp://ftp.ntrl.net/pub/mirror/ralfsw/mod_ssl/

MASTER_SITES_RA=	ftp://ftp.lexa.ru/pub/apache-rus/ \
			ftp://ftp.lexa.ru/pub/apache-rus/old-versions/

# New feature: conflicts
CONFLICTS=	apache+ipv6-* \
		apache+mod_ssl-* \
		apache+mod_ssl+ipv6-* \
		apache+mod_ssl+modsnmp-* \
		apache+mod_ssl+mod_snmp+ipv6-* \
		apache+mod_ssl+mod_accel-* \
		apache+mod_ssl+mod_snmp+mod_accel-* \
		apache-worker-* \
		apache-perchild-* \
		apache-[0-9]* \
		apache_fp-* \
		publicfile-* \
		ru-apache-*

USE_OPENSSL=	yes
USE_PERL5=	yes

DOCSDIR=	${PREFIX}/share/doc/apache

.include <bsd.port.pre.mk>

VERSION_APACHE=	1.3.33
VERSION_MODSSL=	2.8.22
VERSION_RA=	30.21

#
# some defaults
#

DATADIR?=${PREFIX}/www
DOCUMENT_ROOT?=${DATADIR}/data
DEFAULT_PATH?=/bin:/usr/bin:${PREFIX}/bin

#
# suexec support
#
.if defined(WITH_APACHE_SUEXEC)

APACHE_SUEXEC_DOCROOT?=${DOCUMENT_ROOT}
APACHE_SUEXEC_LOG?=/var/log/httpd-suexec.log
APACHE_SUEXEC_USERDIR?=public_html

SUEXEC_CONF=\
	 --enable-suexec \
	 --suexec-docroot=${APACHE_SUEXEC_DOCROOT} \
	 --suexec-caller=www \
	 --suexec-uidmin=1000 \
	 --suexec-gidmin=1000 \
	 --suexec-logfile=${APACHE_SUEXEC_LOG} \
	 --suexec-userdir=${APACHE_SUEXEC_USERDIR} \
	 --suexec-safepath=${DEFAULT_PATH}

.if defined(APACHE_SUEXEC_UMASK)
SUEXEC_CONF+=	--suexec-umask=${APACHE_SUEXEC_UMASK}
.endif

PLIST_SUB+=	SUEXEC=""
SUEXEC_MAN=	suexec.8

.else # WITH_APACHE_SUEXEC

SUEXEC_CONF=
PLIST_SUB+=	SUEXEC="@comment "
SUEXEC_MAN=

.endif # WITH_APACHE_SUEXEC

#
# Configutre parameters
#

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	\
		 --prefix=${PREFIX} \
		 --server-uid=www \
		 --server-gid=www \
		 --with-perl=${PERL} \
		 --with-layout=${FILESDIR}/FreeBSD.layout:FreeBSD \
		 --without-confadjust

OPTIM=		-DHARD_SERVER_LIMIT=512 \
		-DDOCUMENT_LOCATION=\\"${PREFIX}/www/data/\\" \
		-DDEFAULT_PATH=\\"${PREFIX}/bin:/bin:/usr/bin\\" \
		-DACCEPT_FILTER_NAME=\\"httpready\\"

.if defined(WITH_DSO_MODULES)
CONFIGURE_ARGS+=\
		 --enable-shared=max \
		 --disable-shared=so \
		 --disable-shared=charset \
		 --enable-module=most \
		 --enable-module=auth_db \
		 --enable-module=mmap_static \
		 --enable-module=define \
		 --disable-module=auth_dbm \
		 ${SUEXEC_CONF}

PLIST_SUB+=	 DSO_MOD=""
.else
CONFIGURE_ARGS+=\
		 --enable-shared=remain \
		 --enable-module=most \
		 --enable-module=auth_db \
		 --enable-module=mmap_static \
		 --enable-module=define \
		 --disable-shared=define \
		 --enable-module=ssl \
		 --disable-shared=ssl \
		 --disable-module=auth_dbm \
		 ${SUEXEC_CONF}

PLIST_SUB+=	 DSO_MOD="@comment "
.endif

OPTIM=		 -DDOCUMENT_LOCATION=\\"${DOCUMENT_ROOT}\\" \
		 -DDEFAULT_PATH=\\"${DEFAULT_PATH}\\"

.if defined(APACHE_HARD_SERVER_LIMIT)
OPTIM+=		 -DHARD_SERVER_LIMIT=${APACHE_HARD_SERVER_LIMIT}
.else
OPTIM+=		 -DHARD_SERVER_LIMIT=512
.endif

.if defined(APACHE_PERF_TUNING)
OPTIM+=		-DBUFFERED_LOGS
CFLAGS+=	-O6 -fomit-frame-pointer
.endif

CONFIGURE_ENV=	CFLAGS='${CFLAGS}' \
		OPTIM='${OPTIM}' \
		SSL_BASE='SYSTEM' \
		EAPI_MM='SYSTEM' \
		PATH="${PREFIX}/bin:${PATH}"

INSTALL_TARGET=	install-quiet

MAN1=		dbmmanage.1 htdigest.1 htpasswd.1
MAN8=		ab.8 apachectl.8 apxs.8 httpd.8 logresolve.8 rotatelogs.8 \
		${SUEXEC_MAN}

TYPE=	test
CRT=
KEY=

pre-fetch:
	@${ECHO_MSG} ""
.if defined(WITH_DSO_MODULES)
	@${ECHO_MSG} "Build all modules (except mod_so and mod_charset) as DSO."
.else
	@${ECHO_MSG} "You could define WITH_DSO_MODULES to build all modules as DSO."
.endif
.if defined(APACHE_PERF_TUNING)
	@${ECHO_MSG} "Build Apache for maximum performance."
.else
	@${ECHO_MSG} "You could define APACHE_PERF_TUNING to build Apache for maximum performace."
.endif
.if defined(APACHE_HARD_SERVER_LIMIT)
	@${ECHO_MSG} "Build Apache with HARD_SERVER_LIMIT=${APACHE_HARD_SERVER_LIMIT}"
.else
	@${ECHO_MSG} "You could define APACHE_HARD_SERVER_LIMIT, default one is 512"
.endif
.if defined(WITH_APACHE_SUEXEC)
	@${ECHO_MSG} "Build apache with suexec support"
	@${ECHO_MSG} "   suexec docroot:  ${APACHE_SUEXEC_DOCROOT}"
	@${ECHO_MSG} "   suexec userdir:  ${APACHE_SUEXEC_USERDIR}"
	@${ECHO_MSG} "   suexec safepath: ${DEFAULT_PATH}"
	@${ECHO_MSG} "   suexec log:      ${APACHE_SUEXEC_LOG}"
	@${ECHO_MSG} "   These values could be defined as APACHE_SUEXEC_DOCROOT, APACHE_SUEXEC_USERDIR, DEFAULT_PATH and APACHE_SUEXEC_LOG."
.else
	@${ECHO_MSG} "You could define WITH_APACHE_SUEXEC to build suexec support."
.endif
	@${ECHO_MSG} ""

pre-patch:
	@cd ${WRKDIR}/apache_${VERSION_APACHE} \
	&& ${ECHO_MSG} "===>  Applying Russian Apache extension" \
	&& ${PATCH} ${PATCH_DIST_ARGS} < ${WRKDIR}/RA-1.3rusPL${VERSION_RA}.patch
	@cd ${WRKDIR} \
	&& tar cf - src conf htdocs | tar xf - -C ${WRKDIR}/apache_${VERSION_APACHE}
	@cd ${WRKDIR}/mod_ssl-${VERSION_MODSSL}-${VERSION_APACHE} \
	&& ${ECHO_MSG} "===>  Fix mod_ssl-${VERSION_MODSSL} extension for compatibility with Russian Apache" \
	&& ${PATCH} --quiet < ${FILESDIR}/mod_ssl-fix
	@cd ${WRKDIR}/mod_ssl-${VERSION_MODSSL}-${VERSION_APACHE} \
	&& ${ECHO_MSG} "===>  Applying mod_ssl-${VERSION_MODSSL} extension" \
	&& ./configure --with-apache=../${DISTNAME} --expert

post-patch:
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
	PKG_PREFIX=${PREFIX} ${SH} pkg-install ${PKGNAME} PRE-INSTALL

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/apache.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/apache.sh startup file."; \
		${INSTALL_SCRIPT} -m 751 ${FILESDIR}/apache.sh ${PREFIX}/etc/rc.d/apache.sh; \
	fi

.include <bsd.port.post.mk>
