# New ports collection makefile for:	apache + mod_ssl
# Version required:	1.3.1
# Date created:		Sat Aug 22 12:00:00 CDT 1998
# Whom:			rse@engelschall.com
#
# $Id: Makefile,v 1.3 1998/09/09 15:17:45 rse Exp $
#

DISTNAME=	apache_${VERSION_APACHE}
PKGNAME=	apache-${VERSION_APACHE}+mod_ssl-${VERSION_MODSSL}
CATEGORIES=	www security
MASTER_SITES=	ftp://www.apache.org/apache/dist/ \
		http://www.engelschall.com/sw/mod_ssl/distrib/ \
		ftp://ftp.engelschall.com/sw/mod_ssl/ \
		ftp://ftp.ulpgc.es/pub/mod_ssl/ \
		ftp://glock.missouri.edu/pub/mod_ssl/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		mod_ssl-${VERSION_MODSSL}-${VERSION_APACHE}${EXTRACT_SUFX}

MAINTAINER=	rse@engelschall.com

BUILD_DEPENDS=	ssleay:${PORTSDIR}/security/SSLeay \
		${PREFIX}/lib/libssl.a:${PORTSDIR}/security/SSLeay \
		${PREFIX}/lib/libcrypto.a:${PORTSDIR}/security/SSLeay
RUN_DEPENDS=	ssleay:${PORTSDIR}/security/SSLeay

VERSION_APACHE=	1.3.1
VERSION_MODSSL=	2.0.8

RESTRICTED=	"Contains cryptography"

GNU_CONFIGURE=	yes
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
		 --enable-module=ssl

OPTIM=\
-DHARD_SERVER_LIMIT=512 \
-DDOCUMENT_LOCATION=\\"${PREFIX}/www/data/\\" \
-DDEFAULT_PATH=\\"/bin:/usr/bin:${PREFIX}/bin\\"

.if defined(APACHE_PERF_TUNING) && ${APACHE_PERF_TUNING} == YES
CONFIGURE_ARGS+= --disable-rule=STATUS
OPTIM+= -DBUFFERED_LOGS
CFLAGS+= -O6 -fomit-frame-pointer -fexpensive-optimizations
.endif

CONFIGURE_ENV=	OPTIM='${OPTIM}' SSL_BASE='SYSTEM'

INSTALL_TARGET=	install-quiet

MAN1=	ab.1 apachectl.1 dbmmanage.1 htdigest.1 htpasswd.1
MAN8=	apxs.8 httpd.8 logresolve.8 rotatelogs.8

TYPE=	test
CRT=
KEY=

pre-patch:
	@cd ${WRKDIR}/mod_ssl-${VERSION_MODSSL}-${VERSION_APACHE} \
	&& ${ECHO_MSG} "===>  Applying mod_ssl-${VERSION_MODSSL} extension" \
	&& ./configure --with-apache=../${DISTNAME}

certificate:
	@cd ${WRKSRC} \
	&& ${ECHO_MSG} "===>  Creating Test Certificate for Server" \
	&& ${MAKE} certificate TYPE=$(TYPE) CRT=$(CRT) KEY=$(KEY)

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/apache.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/apache.sh startup file."; \
		${ECHO} "#!/bin/sh" > ${PREFIX}/etc/rc.d/apache.sh; \
		${ECHO} "[ -x ${PREFIX}/sbin/apachectl ] && ${PREFIX}/sbin/apachectl start >/dev/null && ${ECHO} -n ' apache'" >> ${PREFIX}/etc/rc.d/apache.sh; \
		chmod 751 ${PREFIX}/etc/rc.d/apache.sh; \
	fi

.include <bsd.port.mk>
