# New ports collection makefile for:    apache-ssl HTTPSD
# Version required:     apache 1.3.3 and ssl 1.28
# Date created:     	8th November, 1998
# Whom:			Adam Laurie <adam@algroup.co.uk>
#			based on apache port by ache@nagual.pp.ru
#			and apache-ssl port by Mark Murray <mark@grondar.za>.
#			Oh, and with a little bit of help from Ben :)
#
# $Id: Makefile,v 1.49 1998/12/11 22:46:14 billf Exp $

APACHE= 	1.3.3
APACHE-SSL=	1.28

DISTNAME=       apache_${APACHE}
PKGNAME=        apache-${APACHE}+ssl_${APACHE-SSL}
CATEGORIES=	www security
MASTER_SITES=   ftp://www.apache.org/apache/dist/ \
		ftp://ftp.ox.ac.uk/pub/crypto/SSL/Apache-SSL/ \
		ftp://ftp.MASTER.pgp.net/pub/crypto/SSL/Apache-SSL/ \
		ftp://ftp.replay.com/pub/crypto/apache/Apache-SSL/ \
		ftp://ftp.win.or.jp/pub/network/security/apache-ssl/Apache-SSL/ \
		ftp://ftp.sage-au.org.au/pub/network/security/apache-ssl/Apache-SSL/ \
		ftp://ftp.vwv.com/pub/crypto/SSL/Apache-SSL/ \
		ftp://mirror.aarnet.edu.au/www/servers/apache-ssl/ \
		ftp://ftp.it.net.au/mirrors/crypto/SSL/Apache-SSL/ \
		ftp://ftp.infoscience.co.jp/pub/Crypto/SSL/Apache-SSL/Apache-SSL/ \
		ftp://ftp.funet.fi/pub/crypt/mirrors/ftp.ox.ac.uk/SSL/Apache-SSL/ \
		ftp://apache-ssl.raver.net/pub/ftp.apache-ssl.org/Apache-SSL/ \
		http://mirror.aarnet.edu.au/www/servers/apache-ssl/ \
		http://ftp.it.net.au/mirrors/crypto/SSL/Apache-SSL/ \
		http://www.asap.cs.nott.ac.uk/SSL

DISTFILES=      ${DISTNAME}${EXTRACT_SUFX} \
		apache_${APACHE}+ssl_${APACHE-SSL}${EXTRACT_SUFX}

MAINTAINER=     Adam Laurie \<adam@algroup.co.uk\>


RUN_DEPENDS=	ssleay:${PORTSDIR}/security/SSLeay

EXTRACT_ONLY=   ${DISTNAME}${EXTRACT_SUFX}

RESTRICTED=     "Contains cryptography"

#
# Set APACHE_PERF_TUNING env. variable to YES to get maximum performance
#

GNU_CONFIGURE=  yes
CONFIGURE_ARGS= \
		--sysconfdir=${PREFIX}/etc/apache \
		--includedir=${PREFIX}/include/apache \
		--logfiledir=/var/log \
		--runtimedir=/var/run \
		--datadir=${PREFIX}/www \
		--proxycachedir=${PREFIX}/www/proxy \
		--libexecdir=${PREFIX}/libexec/apache \
		--without-confadjust \
		--enable-shared=remain \
		--enable-module=most \
		--enable-module=auth_db \
		--disable-module=auth_dbm \

OPTIM=-DHARD_SERVER_LIMIT=512 \
-DDOCUMENT_LOCATION=\\"${PREFIX}/www/data/\\" \
-DDEFAULT_PATH=\\"/bin:/usr/bin:${PREFIX}/bin\\"

.if defined(APACHE_PERF_TUNING) && ${APACHE_PERF_TUNING} == YES
OPTIM+= -DBUFFERED_LOGS
CFLAGS+= -O6 -fomit-frame-pointer
.endif

CONFIGURE_ENV+= OPTIM='${OPTIM}'

MAN1=   ab.1 apachectl.1 dbmmanage.1 htdigest.1 htpasswd.1

.if !defined(USA_RESIDENT) || ${USA_RESIDENT} != YES
pre-fetch:
	@${ECHO}
	@${ECHO} "*** Warning!"
	@${ECHO} You must set variable USA_RESIDENT to YES if you are USA
	@${ECHO} resident and are using RSAREF otherwise package will not link
	@${ECHO} correctly.
	@${ECHO} 
	@${ECHO} 
.endif
.if defined(USA_RESIDENT) && ${USA_RESIDENT} == YES
CONFIGURE_ENV=LDFLAGS="${LDFLAGS} -L/usr/local/lib -lRSAglue -lrsaref"
.endif

post-extract:
	@cd ${WRKSRC} && tar xzf ${DISTDIR}/apache_${APACHE}+ssl_${APACHE-SSL}${EXTRACT_SUFX}

post-patch:
	@cd ${WRKSRC} && ./FixPatch

certificate:
	@if [ -f ${PREFIX}/etc/ssleay.cnf ]; then \
		cd ${WRKSRC}; ${MAKE} ${MAKE_ENV} $@; \
		${CP} ${WRKSRC}/SSLconf/conf/httpsd.pem ${PREFIX}/certs/cert.pem; \
	else \
		${ECHO} "You must create the file ${PREFIX}/etc/ssleay.cnf first."; \
	fi

.include <bsd.port.mk>
