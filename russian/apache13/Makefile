# New ports collection makefile for:    apache HTTPD
# Date created:         Sat Apr 10 22:30:36 EEST 1999
# Whom:                 vns@delta.odessa.ua
#
# $FreeBSD$
#

PORTNAME=	apache
PORTVERSION=	${APACHE_VERSION}+${RA_VERSION}
CATEGORIES=	russian www
MASTER_SITES=	${MASTER_SITE_APACHE_HTTPD}
DISTNAME=	${PORTNAME}_${APACHE_VERSION}

PATCH_SITES=	ftp://ftp.lexa.ru/pub/apache-rus/ \
		ftp://ftp.lexa.ru/pub/apache-rus/old-versions/
PATCHFILES=	patches_${APACHE_VERSION}rusPL${RA_VERSION}.tar.gz

MAINTAINER=	lev@FreeBSD.org
COMMENT=	The extremely popular Apache http server.  Very fast, very clean

# New ports feature: conflicts
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
		ru-apache+mod_ssl-*

RA_VERSION=	30.21
APACHE_VERSION=	1.3.33

#
# Small hack for alternate processing patchfiles
#
GZCAT=sh -c 'tar -zxf $$0 -C ${WRKSRC};${CAT} ${WRKSRC}/RA-1.3rusPL${RA_VERSION}.patch'

#
# Set proper docsdir
#
DOCSDIR=	${PREFIX}/share/doc/apache

#
# Include pre-make
#
.include <bsd.port.pre.mk>

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

USE_PERL5=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=\
		 --prefix=${PREFIX} \
		 --server-uid=www \
		 --server-gid=www \
		 --with-perl=${PERL} \
		 --with-layout=${FILESDIR}/FreeBSD.layout:FreeBSD \
		 --without-confadjust

.if defined(WITH_DSO_MODULES)
CONFIGURE_ARGS+=\
		 --enable-shared=max \
		 --disable-shared=so \
		 --disable-shared=charset \
		 --enable-module=most \
		 --enable-module=auth_db \
		 --enable-module=mmap_static \
		 --disable-module=auth_dbm \
		 ${SUEXEC_CONF}

PLIST_SUB+=	 DSO_MOD=""
.else
CONFIGURE_ARGS+=\
		 --enable-shared=remain \
		 --enable-module=most \
		 --enable-module=auth_db \
		 --enable-module=mmap_static \
		 --disable-module=auth_dbm \
		 ${SUEXEC_CONF}

PLIST_SUB+=	 DSO_MOD="@comment "
.endif

OPTIM=		 -DDOCUMENT_LOCATION=\\"${DOCUMENT_ROOT}\\" \
		 -DDEFAULT_PATH=\\"${DEFAULT_PATH}\\" \
		 -DACCEPT_FILTER_NAME=\\"httpready\\"

.if defined(APACHE_HARD_SERVER_LIMIT)
OPTIM+=		 -DHARD_SERVER_LIMIT=${APACHE_HARD_SERVER_LIMIT}
.else
OPTIM+=		 -DHARD_SERVER_LIMIT=512
.endif

.if defined(APACHE_PERF_TUNING)
OPTIM+=		-DBUFFERED_LOGS
CFLAGS+=	-O6 -fomit-frame-pointer
.endif

CONFIGURE_ENV=	OPTIM='${OPTIM}' LD_SHLIB='${CC}'

MAN1=		dbmmanage.1 htdigest.1 htpasswd.1
MAN8=		ab.8 apachectl.8 apxs.8 httpd.8 logresolve.8 rotatelogs.8 \
		${SUEXEC_MAN}

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

pre-install:
	@if [ -f ${WRKSRC}/htdocs/index.html.orig ]; then \
		${RM} ${WRKSRC}/htdocs/index.html.orig; \
	fi
	PKG_PREFIX=${PREFIX} ${SH} pkg-install ${PKGNAME} PRE-INSTALL

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/apache.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/apache.sh startup file."; \
		${INSTALL_SCRIPT} -m 751 ${FILESDIR}/apache.sh ${PREFIX}/etc/rc.d/apache.sh; \
	fi

.include <bsd.port.post.mk>
