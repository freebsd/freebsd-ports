# New ports collection makefile for:	apache HTTPD / php3
# Version required:	1.3.1 / 3.0.3
# Date created:		So  21 Jun 1998 16:09:39 CEST
# Whom:			Stefan Herrmann <stefan@asterix.webaffairs.net>
#
# $Id: Makefile,v 1.52 1998/09/01 18:38:05 andreas Exp $
#

DISTNAME=	apache_${APACHE_VER}
PKGNAME=	apache-php${PHP3_VER}-${APACHE_VER}
CATEGORIES=	www
MASTER_SITES=	ftp://www.apache.org/apache/dist/ \
		http://www.php.net/distributions/
DISTFILES=	apache_${APACHE_VER}.tar.gz php-${PHP3_VER}.tar.gz

MAINTAINER=	ibex@physik.TU-Berlin.DE

APACHE_VER=	1.3.1
PHP3_VER=	3.0.3

USE_PERL5=	yes

IS_INTERACTIVE=	yes
NO_PACKAGE=	Support for different databases

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
		 --enable-shared=remain \
		 --enable-module=most \
		 --enable-module=auth_db \
		 --disable-module=auth_dbm \
		 --with-perl=${PREFIX}/bin/perl5 \
		 --activate-module=src/modules/php3/libphp3.a

OPTIM=-DHARD_SERVER_LIMIT=512 \
-DDOCUMENT_LOCATION=\\"${PREFIX}/www/data/\\" \
-DDEFAULT_PATH=\\"/bin:/usr/bin:${PREFIX}/bin\\"

.if defined(APACHE_PERF_TUNING) && ${APACHE_PERF_TUNING} == YES
CONFIGURE_ARGS+= --disable-rule=STATUS
OPTIM+= -DBUFFERED_LOGS
CFLAGS+= -O6 -fomit-frame-pointer -fexpensive-optimizations
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
		--disable-debug

post-fetch:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure.php

#post-patch:
#	@${PATCH} -s -d ${WRKDIR}/php-${PHP3_VER} < ${FILESDIR}/configure.patch

pre-configure:
	@( cd ${WRKSRC} \
	&& ./configure > /dev/null \
	&& cd ${WRKDIR}/php-${PHP3_VER} \
	&& ${ECHO_MSG} "===>  Configuring for PHP-${PHP3_VER}" \
	&& CFLAGS= CPPFLAGS="-I${PREFIX}/include -I${PREFIX}/include/gd" LDFLAGS=-L${PREFIX}/lib ./configure ${PHP3_CONF_ARGS} \
	&& ${ECHO_MSG} "===>  Building for PHP-${PHP3_VER}" \
	&& ${MAKE} install \
	&& ${ECHO_MSG} "===>  Configuring for Apache-${APACHE_VER}" )

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/apache.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/apache.sh startup file."; \
		${ECHO} "#!/bin/sh" > ${PREFIX}/etc/rc.d/apache.sh; \
		${ECHO} "[ -d ${PREFIX}/pgsql/lib ] && ${LDCONFIG} -m ${PREFIX}/pgsql/lib" >> ${PREFIX}/etc/rc.d/apache.sh; \
		${ECHO} "[ -x ${PREFIX}/sbin/apachectl ] && ${PREFIX}/sbin/apachectl start > /dev/null && ${ECHO} -n ' apache'" >> ${PREFIX}/etc/rc.d/apache.sh; \
		chmod 751 ${PREFIX}/etc/rc.d/apache.sh; \
	fi

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
	${LN} -s ${PREFIX}/share/doc/apache/$i ${PREFIX}/www/data/$i
.endfor
.for i in CODING_STANDARDS EXTENSION_STATUS LICENSE
	${INSTALL_DATA} ${WRKDIR}/php-${PHP3_VER}/$i ${PHP3DOCDIR}
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
.if !defined(NO_WRKDIR)
	@if [ -d ${WRKDIR} ]; then \
		if [ -w ${WRKDIR} ]; then \
			${RM} -rf ${WRKDIR}; \
		else \
			${ECHO_MSG} "===>   ${WRKDIR} not writable, skipping"; \
		fi; \
	fi
.else
	@${RM} -f ${WRKDIR}/.*_done ${TMPPLIST}
.endif
	@${RM} -f Makefile.inc

.if exists(Makefile.inc)
.include "Makefile.inc"
.endif
.include <bsd.port.mk>
