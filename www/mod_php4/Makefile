# New ports collection makefile for:	apache HTTPD / php3
# Version required:	1.3* / 3.0*
# Date created:		So  21 Jun 1998 16:09:39 CEST
# Whom:			Stefan Herrmann <stefan@asterix.webaffairs.net>
#
# $Id: Makefile,v 1.72 1999/04/11 22:23:30 dirk Exp $
#

DISTNAME=	apache_${VERSION_APACHE}
PKGNAME=	apache-php3-${VERSION_APACHE}
CATEGORIES=	www
MASTER_SITES=	http://www.apache.org/dist/ \
		http://www.rge.com/pub/infosystems/apache/dist/ \
		http://www.apache.de/dist/ \
		http://www.php.net/distributions/ \
		ftp://www.php.net/pub/distributions/ \
		ftp://ftp.ccs.neu.edu/net/mirrors/ftp.apache.org/apache/dist/ \
		ftp://apache.compuex.com/pub/apache/dist/ \
		http://php.he.net/distributions/ \
		http://www.php3.de/distributions/ \
		ftp://apache.arctic.org/pub/apache/dist/ \
		ftp://ftp.epix.net/pub/apache/dist/ \
		ftp://ftp.ameth.org/pub/mirrors/ftp.apache.org/apache/dist/ \
		ftp://ftp.connectnet.com/pub/www/apache/ \
		ftp://apache.technomancer.com/mirrors/apache/dist/ \
		ftp://ftp.raver.net/pub/ftp.apache.org/ \
		ftp://www3.service.digital.com/apache/dist/ \
		ftp://galileo.galilei.com/pub/apache/ \
		ftp://ftp.mtnranch.net/pub/apache/dist/ \
		ftp://ftp.iodynamics.com/pub/mirror/apache/dist/ \
		ftp://apache.nextpath.com/pub/apache/dist/
DISTFILES=	apache_${VERSION_APACHE}.tar.gz php-${VERSION_PHP3}.tar.gz

MAINTAINER=	dirk@FreeBSD.ORG

Y2K=		http://www.php.net/y2k.php3

VERSION_APACHE=	1.3.6
VERSION_PHP3=	3.0.7

USE_PERL5=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--target=apache \
		--with-layout=GNU \
		--with-perl=${PERL} \
		--bindir=${PREFIX}/bin \
		--sbindir=${PREFIX}/sbin \
		--libexecdir=${PREFIX}/libexec/apache \
		--mandir=${PREFIX}/man \
		--sysconfdir=${PREFIX}/etc/apache \
		--datadir=${PREFIX}/share/apache \
		--includedir=${PREFIX}/include/apache \
		--localstatedir=/var \
		--runtimedir=/var/run \
		--logfiledir=/var/log \
		--proxycachedir=/var/spool/apache \
		--without-confadjust \
		--enable-module=most \
		--enable-module=auth_db \
		--disable-module=auth_dbm \
		--enable-shared=max \
		--activate-module=src/modules/php3/libphp3.a

OPTIM=		-DHARD_SERVER_LIMIT=512 \
		-DDEFAULT_PATH=\\"${PREFIX}/bin:/bin:/usr/bin\\"

.if defined(APACHE_PERF_TUNING) && ${APACHE_PERF_TUNING} == YES
OPTIM+=		-DBUFFERED_LOGS -DFD_SETSIZE=1024
CFLAGS+=	-O6 -funroll-loops -fstrength-reduce -fomit-frame-pointer \
		-fexpensive-optimizations -ffast-math
.endif

CONFIGURE_ENV=	OPTIM='${OPTIM}' LIBS='-L${PREFIX}/lib'

INSTALL_TARGET=	install-quiet

MAN1=		dbmmanage.1 htdigest.1 htpasswd.1
MAN8=		ab.8 apache.8 apachectl.8 apxs.8 logresolve.8 rotatelogs.8

APACHEDOCDIR=	${PREFIX}/share/doc/apache
PHP3DOCDIR=	${PREFIX}/share/doc/php3

PHP3_CONF_ARGS=	--prefix=${PREFIX} \
		${CONFIGURE_TARGET} \
		--with-system-regex \
		--with-apache=${WRKSRC} \
		--with-config-file-path=${PREFIX}/lib \
		--disable-debug \
		--enable-track-vars

pre-fetch:
.if !defined(BATCH)
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure.php
.endif

pre-configure:
	@cd ${WRKSRC} \
	&& ./configure > /dev/null \
	&& cd ${WRKDIR}/php-${VERSION_PHP3} \
	&& ${ECHO_MSG} "===>  Configuring for PHP-${VERSION_PHP3}" \
	&& CC="${CC}" \
	   CFLAGS="${CFLAGS}" \
	   CPPFLAGS="-I${PREFIX}/include -I${PREFIX}/include/gd" \
	   LDFLAGS=-L${PREFIX}/lib \
	   ./configure ${PHP3_CONF_ARGS} \
	&& ${ECHO_MSG} "===>  Building for PHP-${VERSION_PHP3}" \
	&& ${MAKE} install \
	&& ${ECHO_MSG} "===>  Configuring for Apache-${VERSION_APACHE}"

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/apache.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/apache.sh startup file."; \
		${ECHO} "#!/bin/sh" > ${PREFIX}/etc/rc.d/apache.sh; \
		${ECHO} "[ -d ${PREFIX}/pgsql/lib ] && ${LDCONFIG} -m ${PREFIX}/pgsql/lib" >> ${PREFIX}/etc/rc.d/apache.sh; \
		${ECHO} "[ -x ${PREFIX}/sbin/apachectl ] && ${PREFIX}/sbin/apachectl start${SSL} > /dev/null && ${ECHO} -n ' apache'" >> ${PREFIX}/etc/rc.d/apache.sh; \
		chmod 751 ${PREFIX}/etc/rc.d/apache.sh; \
	fi
	${INSTALL_DATA} ${WRKDIR}/php-${VERSION_PHP3}/php3.ini-dist ${PREFIX}/lib
.for i in php2 php3 phpi phps
	${INSTALL_DATA} ${WRKDIR}/php-${VERSION_PHP3}/extra/icons/$i.gif ${PREFIX}/share/apache/icons
.endfor

.if !defined(NOPORTDOCS)
	${MKDIR} ${APACHEDOCDIR} ${PHP3DOCDIR}
.for i in README LICENSE ABOUT_APACHE
	${INSTALL_DATA} ${WRKSRC}/$i ${APACHEDOCDIR}
.endfor
.for i in CODING_STANDARDS EXTENSION_STATUS LICENSE
	${INSTALL_DATA} ${WRKDIR}/php-${VERSION_PHP3}/$i ${PHP3DOCDIR}
.endfor
	@${ECHO} "Docs reside in ${APACHEDOCDIR}"
	@${ECHO} "and in ${PHP3DOCDIR}"
.endif

# This was copied from bsd.port.mk because a missing post-clean target
# is needed
clean:
.if !defined(NOCLEANDEPENDS)
	@${MAKE} clean-depends
.endif
	@${ECHO_MSG} "===>  Cleaning for ${PKGNAME}"
	@if [ -d ${WRKDIR} ]; then \
		if [ -w ${WRKDIR} ]; then \
			${RM} -rf ${WRKDIR}; \
		else \
			${ECHO_MSG} "===>   ${WRKDIR} not writable, skipping"; \
		fi; \
	fi
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.endif
.include <bsd.port.mk>
