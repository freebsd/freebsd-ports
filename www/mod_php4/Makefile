# New ports collection makefile for:	apache HTTPD / php3
# Version required:	1.3* / 3.0*
# Date created:		So  21 Jun 1998 16:09:39 CEST
# Whom:			Stefan Herrmann <stefan@asterix.webaffairs.net>
#
# $Id: Makefile,v 1.63 1999/01/03 12:26:47 dirk Exp $
#

DISTNAME=	apache_${VERSION_APACHE}
PKGNAME=	apache-php3-${VERSION_APACHE}
CATEGORIES=	www
MASTER_SITES=	ftp://www.apache.org/apache/dist/ \
		http://www.rge.com/pub/infosystems/apache/dist/ \
		http://www.apache.de/dist/ \
		http://www.php.net/distributions/ \
		ftp://www.php.net/pub/distributions/ \
		http://php.he.net/distributions/ \
		http://www.php3.de/distributions/
DISTFILES=	apache_${VERSION_APACHE}.tar.gz php-${VERSION_PHP3}.tar.gz

MAINTAINER=	dirk@FreeBSD.ORG

VERSION_APACHE=	1.3.3
VERSION_PHP3=	3.0.6

#
# Set APACHE_PERF_TUNING env. variable to YES to get maximum performance
#

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
		 --activate-module=src/modules/php3/libphp3.a

# Currently perl version don't matter
#                --with-perl=${PERL5}

OPTIM=-DHARD_SERVER_LIMIT=512 \
-DDOCUMENT_LOCATION=\\"${PREFIX}/www/data/\\" \
-DDEFAULT_PATH=\\"/bin:/usr/bin:${PREFIX}/bin\\"

.if defined(APACHE_PERF_TUNING) && ${APACHE_PERF_TUNING} == YES
OPTIM+= -DBUFFERED_LOGS
CFLAGS+= -O6 -fomit-frame-pointer
.endif

CONFIGURE_ENV= OPTIM='${OPTIM}' LIBS='-L${PREFIX}/lib'

MAN1=	ab.1 apachectl.1 dbmmanage.1 htdigest.1 htpasswd.1
MAN8=	apxs.8 httpd.8 logresolve.8 rotatelogs.8

APACHEDOCDIR=	${PREFIX}/share/doc/apache
PHP3DOCDIR=	${PREFIX}/share/doc/php3

PHP3_CONF_ARGS=	--prefix=${PREFIX} \
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
	   ac_cv_path_CC="${CC}" \
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
	${INSTALL_DATA} ${WRKDIR}/php-${VERSION_PHP3}/extra/icons/$i.gif ${PREFIX}/www/icons
.endfor

.if !defined(NOPORTDOCS)
	${MKDIR} ${APACHEDOCDIR} ${PHP3DOCDIR}
.for i in README LICENSE ABOUT_APACHE
	${INSTALL_DATA} ${WRKSRC}/$i ${APACHEDOCDIR}
.endfor
	(cd ${WRKSRC}/htdocs && tar cf - *) |\
	(cd ${APACHEDOCDIR} && tar xf -); \
	find ${APACHEDOCDIR} -type d -exec chmod a+rx {} \; ; \
	find ${APACHEDOCDIR} -type f -exec chmod a+r {} \;
.for i in apache_pb.gif index.html manual
	if [ ! -e ${PREFIX}/www/data/$i ] ; then \
		${LN} -s ${PREFIX}/share/doc/apache/$i ${PREFIX}/www/data/$i; \
	fi
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
