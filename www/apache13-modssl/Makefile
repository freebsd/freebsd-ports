# New ports collection makefile for:	Apache + mod_ssl
# Version required:	1.3.3 + 2.1.6
# Date created:		Sat Aug 22 12:00:00 CDT 1998
# Whom:			rse@engelschall.com
#
# $Id: Makefile,v 1.14 1999/01/06 16:48:34 rse Exp $
#

DISTNAME=	apache_${VERSION_APACHE}
PKGNAME=	apache-${VERSION_APACHE}+mod_ssl-${VERSION_MODSSL}
CATEGORIES=	www security
MASTER_SITES=	ftp://www.apache.org/apache/dist/ \
		http://www.engelschall.com/sw/mod_ssl/distrib/ \
		ftp://ftp.engelschall.com/sw/mod_ssl/ \
		ftp://ftp.nvg.ntnu.no/pub/unix/mod_ssl/ \
		ftp://ftp.ulpgc.es/pub/mod_ssl/ \
		ftp://glock.missouri.edu/pub/mod_ssl/ \
		ftp://ftp.infoscience.co.jp/pub/Crypto/SSL/mod_ssl/ \
		ftp://ftp.uni-trier.de/pub/unix/security/mod_ssl/ \
		ftp://ftp.blatzheim.com/pub/mod_ssl/ \
		ftp://ftp.fu-berlin.de/unix/security/mod_ssl/ \
		ftp://ftp.ntrl.net/pub/mirror/ralfsw/mod_ssl/

DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		mod_ssl-${VERSION_MODSSL}-${VERSION_APACHE}${EXTRACT_SUFX}

MAINTAINER=	rse@engelschall.com

BUILD_DEPENDS=	ssleay:${PORTSDIR}/security/openssl \
		${PREFIX}/lib/libssl.a:${PORTSDIR}/security/openssl \
		${PREFIX}/lib/libcrypto.a:${PORTSDIR}/security/openssl
RUN_DEPENDS=	ssleay:${PORTSDIR}/security/openssl

VERSION_APACHE=	1.3.3
VERSION_MODSSL=	2.1.6

RESTRICTED=	"Contains cryptography"

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc/apache \
		--includedir=${PREFIX}/include/apache \
		--logfiledir=/var/log \
		--runtimedir=/var/run \
		--datadir=${PREFIX}/www \
		--proxycachedir=${PREFIX}/www/proxy \
		--libexecdir=${PREFIX}/libexec/apache \
		--without-confadjust \
		--enable-module=most \
		--enable-module=auth_db \
		--disable-module=auth_dbm \
		--enable-module=ssl \
		--enable-shared=max

OPTIM=\
-DHARD_SERVER_LIMIT=512 \
-DDOCUMENT_LOCATION=\\"${PREFIX}/www/data/\\" \
-DDEFAULT_PATH=\\"/bin:/usr/bin:${PREFIX}/bin\\"

.if defined(APACHE_PERF_TUNING) && ${APACHE_PERF_TUNING} == YES
OPTIM+= -DBUFFERED_LOGS -DFD_SETSIZE=1024
CFLAGS+= -O6 -funroll-loops -fstrength-reduce -fomit-frame-pointer -fexpensive-optimizations -ffast-math
.endif

CONFIGURE_ENV=	OPTIM='${OPTIM}' SSL_BASE='SYSTEM' PATH="${PREFIX}/bin:${PATH}"

INSTALL_TARGET=	install-quiet

MAN1=	ab.1 apachectl.1 dbmmanage.1 htdigest.1 htpasswd.1
MAN8=	apxs.8 httpd.8 logresolve.8 rotatelogs.8

TYPE=	test
CRT=
KEY=

pre-patch:
	@cd ${WRKDIR}/mod_ssl-${VERSION_MODSSL}-${VERSION_APACHE} \
	&& ${ECHO_MSG} "===>  Applying mod_ssl-${VERSION_MODSSL} extension" \
	&& ./configure --with-apache=../${DISTNAME} --expert

post-patch:
	@cd ${WRKSRC} \
	&& find . -type f -name "*.orig" -print | xargs ${RM} -f

post-build:
	@cd ${WRKSRC} \
	&& ${ECHO_MSG} "===>  Creating Dummy Certificate for Server (SnakeOil)" \
	&& ${ECHO_MSG} "      [use 'make certificate' to create a real one]" \
	&& ${MAKE} certificate TYPE=dummy >/dev/null 2>&1

certificate:
	@cd ${WRKSRC} \
	&& ${ECHO_MSG} "===>  Creating Test Certificate for Server" \
	&& ${MAKE} certificate TYPE=$(TYPE) CRT=$(CRT) KEY=$(KEY)

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/apache.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/apache.sh startup file."; \
		${ECHO} "#!/bin/sh" > ${PREFIX}/etc/rc.d/apache.sh; \
		${ECHO} "[ -x ${PREFIX}/sbin/apachectl ] && ${PREFIX}/sbin/apachectl startssl >/dev/null && ${ECHO} -n ' apache'" >> ${PREFIX}/etc/rc.d/apache.sh; \
		chmod 751 ${PREFIX}/etc/rc.d/apache.sh; \
	fi

.include <bsd.port.mk>
