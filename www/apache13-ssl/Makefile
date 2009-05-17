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
PORTREVISION=	1
CATEGORIES=	www security
MASTER_SITES=	${MASTER_SITE_APACHE_HTTPD} \
		${MASTER_SITES_APACHE_SSL:S/$/:ssl/}
DISTNAME=	apache_${APACHE_VERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		apache_${APACHE_VERSION}+ssl_${APACHE_SSL_VERSION}${EXTRACT_SUFX}:ssl
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache secure webserver integrating OpenSSL

MAKE_JOBS_SAFE=  yes

CONFLICTS=	apache+mod_ssl-1.* apache+mod_ssl+ipv6-1.* apache+mod_ssl+modsnmp-1.* \
		apache+mod_ssl+mod_snmp+ipv6-1.* apache+mod_ssl+mod_accel-1.* \
		apache+mod_ssl+mod_snmp+mod_accel-1.* \
		apache+ipv6-1.* apache-1.* apache-2.* apache_fp-1.* \
		caudium-devel-1.* caudium10-1.* caudium12-1.* \
		ru-apache+mod_ssl-1.* ru-apache-1.*

APACHE_VERSION=		1.3.41
APACHE_SSL_VERSION=	1.59
USE_OPENSSL=		yes
USE_PERL5=		yes
HAS_CONFIGURE=		yes
USE_RC_SUBR=		apache
SUB_LIST+=		WWWOWN=${WWWOWN}
MAKE_ENV+=		EXAMPLESDIR=${EXAMPLESDIR}
USE_APACHE=		common13

MASTER_SITES_APACHE_SSL=	\
		ftp://ftp.ox.ac.uk/pub/crypto/SSL/Apache-SSL/ \
		ftp://ftp.it.net.au/mirrors/crypto/SSL/Apache-SSL/ \
		ftp://opensores.thebunker.net/pub/mirrors/apache-ssl/

APACHE_HARD_SERVER_LIMIT?=	512

CFLAGS+=	-I${OPENSSLINC}/openssl
CONFIGURE_ARGS+=	\
		--prefix=${PREFIX} \
		--server-uid=www \
		--server-gid=www \
		--with-perl=${PERL} \
		--with-layout=FreeBSD \
		--without-confadjust \
		--disable-module=auth_dbm \
		--sysconfdir=${PREFIX}/etc/apache \
		--includedir=${PREFIX}/include/apache \
		--localstatedir=/var \
		--datadir=${PREFIX}/www \
		--proxycachedir=${PREFIX}/www/proxy \
		--libexecdir=${PREFIX}/libexec/apache \
		--target=httpsd

#		--enable-shared=remain \

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

.if defined(WITH_SUEXEC)
MAN8=		suexec.8
PLIST_SUB+=	SUB_SUEXEC=""
.else
PLIST_SUB+=	SUB_SUEXEC="@comment "
.endif

MAN1=		dbmmanage.1 htdigest.1 htpasswd.1
MAN8+=		ab.8 httpsdctl.8 apxs.8 httpsd.8 logresolve.8 rotatelogs.8

.include "${.CURDIR}/Makefile.modules"
.include <bsd.port.pre.mk>

post-extract:
	@cd ${WRKSRC} && ${TAR} xzf ${DISTDIR}/${DIST_SUBDIR}/apache_${APACHE_VERSION}+ssl_${APACHE_SSL_VERSION}${EXTRACT_SUFX}

post-patch:
	@cd ${WRKSRC} && ${SETENV} PREFIX=${PREFIX} ./FixPatch ${OPENSSLBASE}
	@${PATCH} ${PATCH_ARGS} < ${FILESDIR}/post-patch-conf:httpd.conf-dist
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' \
		${WRKSRC}/src/Configure
.if defined(NOPORTDOCS)
	(cd ${WRKSRC} ; ${PATCH} ${PATCH_ARGS} < ${FILESDIR}/extra-patch-noportdocs)
.endif

post-install:
	@${ECHO_CMD} ""
	@${ECHO_CMD} "SSL is disabled by default"
	@${ECHO_CMD} "Please read:"
	@${ECHO_CMD} "  http://www.apache-ssl.org/docs.html"
	@${ECHO_CMD} " to know how to configure correctly apache-ssl"
	@${ECHO_CMD} ""

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
