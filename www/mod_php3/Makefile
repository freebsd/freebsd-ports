# New ports collection makefile for:	Apache / PHP
# Version required:	1.3* / 3.0*
# Date created:		So  21 Jun 1998 16:09:39 CEST
# Whom:			Stefan Herrmann <stefan@asterix.webaffairs.net>
#
# $FreeBSD$
#

DISTNAME=	apache_${VERSION_APACHE}
PKGNAME=	apache+php-${VERSION_APACHE}+${VERSION_PHP}
CATEGORIES=	www
MASTER_SITES=	http://www.apache.org/dist/ \
		http://www.rge.com/pub/infosystems/apache/dist/ \
		ftp://ftp.php.net/pub/${PHP_DISTDIR}/ \
		http://us.php.net/${PHP_DISTDIR}/ \
		http://www.modssl.org/source/ \
		ftp://ftp.modssl.org/source/ \
		http://www.apache.de/dist/ \
		ftp://ftp.ccs.neu.edu/net/mirrors/ftp.apache.org/apache/dist/ \
		http://php.he.net/${PHP_DISTDIR}/ \
		http://www.php3.de/${PHP_DISTDIR}/ \
		ftp://ftp.ecrc.net/pub/security/mod_ssl/ \
		ftp://ftp.nvg.ntnu.no/pub/unix/mod_ssl/ \
		ftp://apache.compuex.com/pub/apache/dist/ \
		ftp://apache.arctic.org/pub/apache/dist/ \
		http://au.php.net:81/${PHP_DISTDIR}/ \
		http://at.php.net/${PHP_DISTDIR}/ \
		ftp://ftp.ulpgc.es/pub/mod_ssl/ \
		ftp://glock.missouri.edu/pub/mod_ssl/ \
		ftp://ftp.epix.net/pub/apache/dist/ \
		ftp://ftp.ameth.org/pub/mirrors/ftp.apache.org/apache/dist/ \
		http://br.php.net/${PHP_DISTDIR}/ \
		http://php.easydns.com/${PHP_DISTDIR}/ \
		ftp://ftp.infoscience.co.jp/pub/Crypto/SSL/mod_ssl/ \
		ftp://ftp.uni-trier.de/pub/unix/security/mod_ssl/ \
		ftp://ftp.connectnet.com/pub/www/apache/ \
		ftp://apache.technomancer.com/mirrors/apache/dist/ \
		http://www.php.cz/${PHP_DISTDIR}/ \
		http://php3.globe.de/${PHP_DISTDIR}/ \
		ftp://ftp.blatzheim.com/pub/mod_ssl/ \
		ftp://ftp.fu-berlin.de/unix/security/mod_ssl/
DISTFILES=	apache_${VERSION_APACHE}.tar.gz php-${VERSION_PHP}.tar.gz

MAINTAINER=	dirk@FreeBSD.org

Y2K=		http://www.php.net/y2k.php3

PHP_DISTDIR=	distributions

VERSION_APACHE=	1.3.12
VERSION_PHP=	3.0.14

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

CONFIGURE_ENV=	OPTIM='${OPTIM}' LIBS='-L${PREFIX}/lib'
SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		TOUCH="${TOUCH}" \
		MKDIR="${MKDIR}"

INSTALL_TARGET=	install-quiet

MAN1=		dbmmanage.1 htdigest.1 htpasswd.1
MAN8=		ab.8 apache.8 apachectl.8 apxs.8 logresolve.8 rotatelogs.8

APACHEDOCDIR=	${PREFIX}/share/doc/apache
PHPDOCDIR=	${PREFIX}/share/doc/php

PHP_CONF_ARGS=	--prefix=${PREFIX} \
		${CONFIGURE_TARGET} \
		--with-system-regex \
		--with-apache=${WRKSRC} \
		--with-config-file-path=${PREFIX}/etc \
		--disable-debug \
		--enable-track-vars \
		--without-gd

pre-fetch:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure.php

post-extract:
	@${LN} -s php-${VERSION_PHP} ${WRKDIR}/php

pre-configure:
	@cd ${WRKSRC} \
	&& CC="${CC}" CFLAGS="${CFLAGS}" ./configure > /dev/null \
	&& cd ${WRKDIR}/php-${VERSION_PHP} \
	&& ${ECHO_MSG} "===>  Configuring for PHP-${VERSION_PHP}" \
	&& CC="${CC}" \
	   CFLAGS="${CFLAGS}" \
	   CPPFLAGS="-I${PREFIX}/include -I${PREFIX}/include/gd" \
	   LDFLAGS=-L${PREFIX}/lib \
	   ./configure ${PHP_CONF_ARGS} \
	&& ${ECHO_MSG} "===>  Building for PHP-${VERSION_PHP}" \
	&& ${MAKE} install \
	&& ${ECHO_MSG} "===>  Configuring for Apache-${VERSION_APACHE}"

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/apache.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/apache.sh startup file."; \
		${ECHO} "#!/bin/sh" > ${PREFIX}/etc/rc.d/apache.sh; \
		${ECHO} "[ -d ${PREFIX}/pgsql/lib ] && ${LDCONFIG} -m ${PREFIX}/pgsql/lib" >> ${PREFIX}/etc/rc.d/apache.sh; \
		${ECHO} "[ -x ${PREFIX}/sbin/apachectl ] && ${PREFIX}/sbin/apachectl start${SSL} > /dev/null && ${ECHO} -n ' apache'" >> ${PREFIX}/etc/rc.d/apache.sh; \
		${CHMOD} 751 ${PREFIX}/etc/rc.d/apache.sh; \
	fi
	${INSTALL_DATA} ${WRKDIR}/php-${VERSION_PHP}/php3.ini-dist ${PREFIX}/etc
.for i in php2 php3 phpi phps
	${INSTALL_DATA} ${WRKDIR}/php-${VERSION_PHP}/extra/icons/$i.gif ${PREFIX}/share/apache/icons
.endfor

.if !defined(NOPORTDOCS)
	${MKDIR} ${APACHEDOCDIR} ${PHPDOCDIR}
.for i in README LICENSE ABOUT_APACHE
	${INSTALL_DATA} ${WRKSRC}/$i ${APACHEDOCDIR}
.endfor
.for i in CODING_STANDARDS LICENSE
	${INSTALL_DATA} ${WRKDIR}/php-${VERSION_PHP}/$i ${PHPDOCDIR}
.endfor
	@${ECHO} "Docs reside in ${APACHEDOCDIR}"
	@${ECHO} "and in ${PHPDOCDIR}"
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

# Modssl needs to include bsd.port.pre.mk, so correct for this situation.
.if defined(_PREMKINCLUDED)
.include <bsd.port.post.mk>
.else
.include <bsd.port.mk>
.endif
