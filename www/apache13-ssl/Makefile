# New ports collection makefile for:    apache-ssl HTTPSD
# Date created:     	8th November, 1998
# Whom:			Adam Laurie <adam@algroup.co.uk>
#			based on apache port by ache@nagual.pp.ru
#			and apache-ssl port by Mark Murray <mark@grondar.za>.
#			Oh, and with a little bit of help from Ben :)
#
# $FreeBSD$

PORTNAME=	apache+ssl
PORTVERSION=	${APACHE_VERSION}.${APACHE_SSL_VERSION}
CATEGORIES=	www security
MASTER_SITES=	${MASTER_SITE_APACHE_HTTPD} \
		${MASTER_SITES_APACHE_SSL:S/$/:ssl/}
DISTNAME=	apache_${APACHE_VERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		apache_${APACHE_VERSION}+ssl_${APACHE_SSL_VERSION}${EXTRACT_SUFX}:ssl
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

#PATCH_SITES=		${MASTER_SITE_APACHE_HTTPD}
#PATCH_SITE_SUBDIR=	patches/apply_to_${APACHE_VERSION}
#PATCHFILES=

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache secure webserver integrating OpenSSL

CONFLICTS=	apache+mod_ssl-1.* apache+mod_ssl+ipv6-1.* apache+mod_ssl+modsnmp-1.* \
		apache+mod_ssl+mod_snmp+ipv6-1.* apache+mod_ssl+mod_accel-1.* \
		apache+mod_ssl+mod_snmp+mod_accel-1.* \
		apache+ipv6-1.* apache-1.* apache-2.* apache_fp-1.* \
		caudium-devel-1.* caudium10-1.* caudium12-* \
		ru-apache+mod_ssl-1.* ru-apache-1.* thttpd-2.*

APACHE_VERSION=		1.3.33
APACHE_SSL_VERSION=	1.55
USE_OPENSSL=		yes
USE_PERL5=		yes
HAS_CONFIGURE=		yes
USE_RC_SUBR=		yes
RC_SCRIPTS_SUB=		PREFIX=${PREFIX} RC_SUBR=${RC_SUBR} WWWOWN=${WWWOWN}
MAKE_ENV+=		EXAMPLESDIR=${EXAMPLESDIR}

MASTER_SITES_APACHE_SSL= \
		ftp://ftp.ox.ac.uk/pub/crypto/SSL/Apache-SSL/ \
		ftp://ftp.it.net.au/mirrors/crypto/SSL/Apache-SSL/ \
		ftp://ftp.sekure.net/pub/apache-ssl/ \
		ftp://opensores.thebunker.net/pub/mirrors/apache-ssl/

APACHE_HARD_SERVER_LIMIT?=	512

.if defined(WITH_APACHE_SUEXEC)

APACHE_SUEXEC_DOCROOT?=	${DOCUMENT_ROOT}
APACHE_SUEXEC_LOG?=	/var/log/httpsd-suexec.log
APACHE_SUEXEC_USERDIR?=	public_html
APACHE_SUEXEC_UIDMIN?=	1000
APACHE_SUEXEC_GIDMIN?=	1000
APACHE_SUEXEC_CALLER?=	www

SUEXEC_CONF=\
	--enable-suexec \
	--suexec-docroot=${APACHE_SUEXEC_DOCROOT} \
	--suexec-caller=${APACHE_SUEXEC_CALLER} \
	--suexec-uidmin=${APACHE_SUEXEC_UIDMIN} \
	--suexec-gidmin=${APACHE_SUEXEC_GIDMIN} \
	--suexec-logfile=${APACHE_SUEXEC_LOG} \
	--suexec-userdir=${APACHE_SUEXEC_USERDIR} \
	--suexec-safepath=${DEFAULT_PATH}

.if defined(APACHE_SUEXEC_UMASK)
SUEXEC_CONF+=	--suexec-umask=${APACHE_SUEXEC_UMASK}
.endif

PLIST_SUB+=	SUB_SUEXEC=""
SUEXEC_MAN=	suexec.8

.else	# !SUEXEC

SUEXEC_CONF=
PLIST_SUB+=	SUB_SUEXEC="@comment "
SUEXEC_MAN=

.endif  # !SUEXEC

#
# Set APACHE_PERF_TUNING env. variable to YES to get maximum performance
#
CFLAGS+=	-I${OPENSSLINC}/openssl
CONFIGURE_ARGS=	\
		--prefix=${PREFIX} \
		--server-uid=www \
		--server-gid=www \
		--with-perl=${PERL} \
		--with-layout=FreeBSD \
		--without-confadjust \
		--enable-shared=remain \
		--enable-module=most \
		--enable-module=auth_db \
		--disable-module=auth_dbm \
		--sysconfdir=${PREFIX}/etc/apache \
		--includedir=${PREFIX}/include/apache \
		--localstatedir=/var \
		--datadir=${PREFIX}/www \
		--proxycachedir=${PREFIX}/www/proxy \
		--libexecdir=${PREFIX}/libexec/apache \
		--target=httpsd \
		${SUEXEC_CONF}

OPTIM=		-DHARD_SERVER_LIMIT=${APACHE_HARD_SERVER_LIMIT} \
		-DDOCUMENT_LOCATION=\\"${PREFIX}/www/data/\\" \
		-DDEFAULT_PATH=\\"/bin:/usr/bin:${PREFIX}/bin\\"

DOCSDIR=	${PREFIX}/share/doc/apache

.if defined(APACHE_PERF_TUNING)
OPTIM+=		-DBUFFERED_LOGS
CFLAGS+=	-O6 -fomit-frame-pointer
.endif

CONFIGURE_ENV+=	OPTIM='${OPTIM}'
CONFIGURE_ENV+=	EXTRA_SSL_LIBS="-L${OPENSSLLIB} -L${LOCALBASE}/lib"

MAN1=		dbmmanage.1 htdigest.1 htpasswd.1
MAN8=		ab.8 httpsdctl.8 apxs.8 httpsd.8 logresolve.8 rotatelogs.8 \
		${SUEXEC_MAN}

.include <bsd.port.pre.mk>

post-extract:
	@cd ${WRKSRC} && ${TAR} xzf ${DISTDIR}/${DIST_SUBDIR}/apache_${APACHE_VERSION}+ssl_${APACHE_SSL_VERSION}${EXTRACT_SUFX}

post-patch:
	@cd ${WRKSRC} && ${SETENV} PREFIX=${PREFIX} ./FixPatch ${OPENSSLBASE}
	@${PATCH} ${PATCH_ARGS} < ${FILESDIR}/post-patch-conf:httpd.conf-dist
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/apache.sh > ${WRKDIR}/apache.sh
post-install:
	@${ECHO_CMD} ""
	@${ECHO_CMD} "SSL is disabled by default"
	@${ECHO_CMD} "Please read:"
	@${ECHO_CMD} "  http://www.apache-ssl.org/docs.html"
	@${ECHO_CMD} " to know how to configure correctly apache-ssl"
	@${ECHO_CMD} ""
	@${INSTALL_SCRIPT} ${WRKDIR}/apache.sh ${PREFIX}/etc/rc.d

certificate:
	-${MKDIR} ${PREFIX}/etc/apache/certs
	@if [ -f ${OPENSSLDIR}/openssl.cnf ]; then \
		cd ${WRKSRC}/src; ${MAKE} ${MAKE_ENV} $@; \
		${CP} ${WRKSRC}/SSLconf/conf/httpsd.pem \
		${PREFIX}/etc/apache/certs/cert.pem; \
	else \
		${ECHO_CMD} "You must create the file ${OPENSSLDIR}/openssl.cnf first."; \
	fi

.include <bsd.port.post.mk>
