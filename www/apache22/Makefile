# New ports collection makefile for:    apache HTTPD
# Version required:     1.3*
# Date created:         Fri Aug 25 16:42:36 CDT 1995
# Whom:                 ache@nagual.pp.ru
#
# $Id: Makefile,v 1.64 1999/01/13 02:47:32 scrappy Exp $
#

DISTNAME=       apache_1.3.4
PKGNAME=        apache-1.3.4
CATEGORIES=	www
MASTER_SITES=   ftp://www.apache.org/apache/dist/

MAINTAINER=     ache@freebsd.org

Y2K=		http://www.apache.org/docs/misc/FAQ.html#year2000

#
# Set APACHE_PERF_TUNING env. variable to YES to get maximum performance
#

GNU_CONFIGURE=  yes
CONFIGURE_ARGS= \
		 --with-layout=GNU \
		 --sysconfdir=${PREFIX}/etc/apache \
		 --includedir=${PREFIX}/include/apache \
		 --localstatedir=/var \
		 --datadir=${PREFIX}/www \
		 --suexec-docroot=${PREFIX}/www/data \
		 --proxycachedir=${PREFIX}/www/proxy \
		 --libexecdir=${PREFIX}/libexec/apache \
		 --without-confadjust \
		 --enable-shared=remain \
		 --enable-module=most \
		 --enable-module=auth_db \
		 --disable-module=auth_dbm

# Currently perl version don't matter
#                 --with-perl=${PERL5}

OPTIM=-DHARD_SERVER_LIMIT=512 \
-DDOCUMENT_LOCATION=\\"${PREFIX}/www/data/\\" \
-DDEFAULT_PATH=\\"/bin:/usr/bin:${PREFIX}/bin\\"

.if defined(APACHE_PERF_TUNING) && ${APACHE_PERF_TUNING} == YES
OPTIM+= -DBUFFERED_LOGS
CFLAGS+= -O6 -fomit-frame-pointer
.endif

CONFIGURE_ENV= OPTIM='${OPTIM}'

MAN1=   ab.1 apachectl.1 dbmmanage.1 htdigest.1 htpasswd.1
MAN8=   apxs.8 httpd.8 logresolve.8 rotatelogs.8

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/apache.sh ]; then \
		echo "Installing ${PREFIX}/etc/rc.d/apache.sh startup file."; \
		echo "#!/bin/sh" > ${PREFIX}/etc/rc.d/apache.sh; \
		echo "[ -x /usr/local/sbin/apachectl ] && /usr/local/sbin/apachectl start > /dev/null && echo -n ' apache'" >> ${PREFIX}/etc/rc.d/apache.sh; \
		chmod 751 ${PREFIX}/etc/rc.d/apache.sh; \
	fi

.include <bsd.port.mk>
