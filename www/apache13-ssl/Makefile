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
MASTER_SITES=	http://www.apache.org/dist/ \
		ftp://ftp.ox.ac.uk/pub/crypto/SSL/Apache-SSL/ \
		ftp://src.doc.ic.ac.uk/packages/apache/dist/ \
		ftp://ftp.gbnet.net/pub/apache/dist/ \
		ftp://ftp.MASTER.pgp.net/pub/crypto/SSL/Apache-SSL/ \
		ftp://ftp.flirble.org/pub/web/apache/dist/ \
		ftp://ftp.replay.com/pub/crypto/apache/Apache-SSL/ \
		ftp://ukug.uk.freebsd.org/pub/mirrors/apache/dist/ \
		ftp://ftp.win.or.jp/pub/network/security/apache-ssl/Apache-SSL/ \
		ftp://ftp.sage-au.org.au/pub/network/security/apache-ssl/Apache-SSL/ \
		ftp://ftp.vwv.com/pub/crypto/SSL/Apache-SSL/ \
		ftp://mirror.aarnet.edu.au/www/servers/apache-ssl/ \
		ftp://ftp.it.net.au/mirrors/crypto/SSL/Apache-SSL/ \
		ftp://ftp.infoscience.co.jp/pub/Crypto/SSL/Apache-SSL/Apache-SSL/ \
		ftp://ftp.funet.fi/pub/crypt/mirrors/ftp.ox.ac.uk/SSL/Apache-SSL/ \
		ftp://apache-ssl.raver.net/pub/ftp.apache-ssl.org/Apache-SSL/ \
		ftp://ftp.pca.dfn.de/pub/tools/net/sslapache/Apache-SSL/ \
		ftp://ftp.sekure.net/pub/apache-ssl/ \
		ftp://ftp.clinet.fi/mirrors/ftp.apache-ssl.org/pub/ \
		ftp://opensores.thebunker.net/pub/mirrors/apache-ssl/ \
		ftp://ftp.gin.cz/pub/MIRRORS/ftp.ox.ac.uk/pub/crypto/SSL/Apache-SSL/ \
		ftp://ftp.cordef.com.pl/pub/apache-ssl/Apache-SSL/
DISTNAME=	apache_${APACHE_VERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		apache_${APACHE_VERSION}+ssl_${APACHE_SSL_VERSION}${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	adam@algroup.co.uk

APACHE_VERSION=		1.3.12
APACHE_SSL_VERSION=	1.40

USE_OPENSSL=	YES

.include <bsd.port.pre.mk>

#
# Set APACHE_PERF_TUNING env. variable to YES to get maximum performance
#

CFLAGS+=	-I${OPENSSLINC}/openssl

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	\
		--prefix=${PREFIX} \
		--server-gid=nogroup \
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

CONFIGURE_ENV=	OPTIM='${OPTIM}'
CONFIGURE_ENV+=	EXTRA_SSL_LIBS="-L${OPENSSLLIB} -L${LOCALBASE}/lib"

MAN1=		dbmmanage.1 htdigest.1 htpasswd.1
MAN8=		ab.8 httpsdctl.8 apxs.8 httpsd.8 logresolve.8 rotatelogs.8

post-extract:
	@cd ${WRKSRC} && tar xzf ${DISTDIR}/apache_${APACHE_VERSION}+ssl_${APACHE_SSL_VERSION}${EXTRACT_SUFX}

post-patch:
	@cd ${WRKSRC} && ${SETENV} PREFIX=${PREFIX} ./FixPatch ${OPENSSLBASE}

certificate:
	@if [ -f ${OPENSSLDIR}/openssl.cnf ]; then \
		cd ${WRKSRC}/src; ${MAKE} ${MAKE_ENV} $@; \
		${CP} ${WRKSRC}/SSLconf/conf/httpsd.pem ${PREFIX}/certs/cert.pem; \
	else \
		${ECHO} "You must create the file ${OPENSSLDIR}/openssl.cnf first."; \
	fi

.include <bsd.port.post.mk>
