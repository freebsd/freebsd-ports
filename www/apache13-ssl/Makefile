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
PORTREVISION=	3
CATEGORIES=	www security
MASTER_SITES=	${MASTER_SITE_APACHE_HTTPD} \
		${MASTER_SITES_APACHE_SSL:S/$/:ssl/}
DISTNAME=	apache_${APACHE_VERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		apache_${APACHE_VERSION}+ssl_${APACHE_SSL_VERSION}${EXTRACT_SUFX}:ssl
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Apache-SSL: Apache secure webserver integrating OpenSSL

APACHE_VERSION=		1.3.27
APACHE_SSL_VERSION=	1.48
USE_OPENSSL=	yes
USE_PERL5=	yes
HAS_CONFIGURE=	yes
MAN1=		dbmmanage.1 htdigest.1 htpasswd.1
MAN8=		ab.8 httpsdctl.8 apxs.8 httpsd.8 logresolve.8 rotatelogs.8

#
# Set APACHE_PERF_TUNING env. variable to YES to get maximum performance
#
CFLAGS+=	-I${OPENSSLINC}/openssl
CONFIGURE_ARGS=	\
		--prefix=${PREFIX} \
		--server-uid=www \
		--server-gid=www \
		--with-perl=${PERL} \
		--with-layout=GNU \
		--suexec-docroot=${PREFIX}/www/data \
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
		--libexecdir=${PREFIX}/libexec/apache

OPTIM=		-DHARD_SERVER_LIMIT=512 \
		-DDOCUMENT_LOCATION=\\"${PREFIX}/www/data/\\" \
		-DDEFAULT_PATH=\\"/bin:/usr/bin:${PREFIX}/bin\\"

.if defined(APACHE_PERF_TUNING) && ${APACHE_PERF_TUNING} == YES
OPTIM+=		-DBUFFERED_LOGS
CFLAGS+=	-O6 -fomit-frame-pointer
.endif

CONFIGURE_ENV+=	OPTIM='${OPTIM}'
CONFIGURE_ENV+=	EXTRA_SSL_LIBS="-L${OPENSSLLIB} -L${LOCALBASE}/lib"

MASTER_SITES_APACHE_SSL= \
		ftp://ftp.ox.ac.uk/pub/crypto/SSL/Apache-SSL/ \
		ftp://ftp.it.net.au/mirrors/crypto/SSL/Apache-SSL/ \
		ftp://ftp.sekure.net/pub/apache-ssl/ \
		ftp://opensores.thebunker.net/pub/mirrors/apache-ssl/ 

.include <bsd.port.pre.mk>

post-extract:
	@cd ${WRKSRC} && tar xzf ${DISTDIR}/apache_${APACHE_VERSION}+ssl_${APACHE_SSL_VERSION}${EXTRACT_SUFX}

post-patch:
	@cd ${WRKSRC} && ${SETENV} PREFIX=${PREFIX} ./FixPatch ${OPENSSLBASE}

certificate:
	-${MKDIR} ${PREFIX}/etc/apache/certs
	@if [ -f ${OPENSSLDIR}/openssl.cnf ]; then \
		cd ${WRKSRC}/src; ${MAKE} ${MAKE_ENV} $@; \
		${CP} ${WRKSRC}/SSLconf/conf/httpsd.pem \
		${PREFIX}/etc/apache/certs/cert.pem; \
	else \
		${ECHO} "You must create the file ${OPENSSLDIR}/openssl.cnf first."; \
	fi

.include <bsd.port.post.mk>
