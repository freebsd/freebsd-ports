# New ports collection makefile for:	apache HTTPD / php3
# Version required:	1.3.0 / 3.0.2
# Date created:		So  21 Jun 1998 16:09:39 CEST
# Whom:			Stefan Herrmann <stefan@asterix.webaffairs.net>
#
# $Id$
#

DISTNAME=	apache_1.3.0
PKGNAME=	apache-php3.0.2-1.3.0
CATEGORIES=	www
MASTER_SITES=	ftp://www.apache.org/apache/dist/ \
		http://www.php.net/distributions/
DISTFILES=	apache_1.3.0.tar.gz php-3.0.2.tar.gz

MAINTAINER=	stefan@asterix.webaffairs.net

BUILD_DEPENDS=	${PREFIX}/lib/libgd.a:${PORTSDIR}/graphics/gd \
		perl5:${PORTSDIR}/lang/perl5

NO_PACKAGE=	"Support for different databases via make-variable"

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

CONFIGURE_ENV= OPTIM='${OPTIM}'

MAN1=	ab.1 apachectl.1 dbmmanage.1 htdigest.1 htpasswd.1
MAN8=	apxs.8 httpd.8 logresolve.8 rotatelogs.8

APACHEDOCDIR=	${PREFIX}/share/doc/apache
PHP3DOCDIR=	${PREFIX}/share/doc/php3

PHP3_CONF_ARGS=	--prefix=${PREFIX} \
		--with-system-regex \
		--with-gd \
		--with-apache=${WRKSRC} \
		--with-config-file-path=${PREFIX}/lib \
		--disable-debug

.if !defined(PHP3_DBTYPE) || ${PHP3_DBTYPE} != msql && ${PHP3_DBTYPE} != mysql && ${PHP3_DBTYPE} != pgsql
pre-fetch:
	@ ${ECHO}
	@ ${ECHO} "You must set variable PHP3_DBTYPE to msql, mysql or pgsql by typing"
	@ ${ECHO} "make PHP3_DBTYPE=[ msql | mysql | pgsql ]"
	@ ${FALSE}
.elif defined(PHP3_DBTYPE)
.if ${PHP3_DBTYPE} == msql
BUILD_DEPENDS+=		msql:${PORTSDIR}/databases/msql
PHP3_CONF_ARGS+=	--with-msql=${PREFIX}
.elif ${PHP3_DBTYPE} == mysql
BUILD_DEPENDS+=		mysql:${PORTSDIR}/databases/mysql
PHP3_CONF_ARGS+=	--with-mysql=${PREFIX}
.elif ${PHP3_DBTYPE} == pgsql
BUILD_DEPENDS+=		${PREFIX}/pgsql/bin/psql:${PORTSDIR}/databases/postgresql
PHP3_CONF_ARGS+=	--with-pgsql=${PREFIX}/pgsql
.endif
.endif

post-patch:
	@ ${PATCH} -s -d ${WRKDIR}/php-3.0.2 < ${FILESDIR}/configure.patch

pre-configure:
	@( cd ${WRKDIR}/php-3.0.2 \
	&& ${ECHO_MSG} "===>  Configuring for PHP-3.0.2" \
	&& CFLAGS= CPPFLAGS="-I${PREFIX}/include -I${PREFIX}/include/gd" LDFLAGS=-L${PREFIX}/lib ./configure ${PHP3_CONF_ARGS} \
	&& ${ECHO_MSG} "===>  Building for PHP-3.0.2" \
	&& ${MAKE} install \
	&& ${ECHO_MSG} "===>  Configuring for Apache-1.3.0" )
.if defined(PHP3_DBTYPE) && ${PHP3_DBTYPE} == msql
CONFIGURE_ENV+= LIBS='-lmd -L${PREFIX}/lib -lmsql -lgd -lm'
.elif defined(PHP3_DBTYPE) && ${PHP3_DBTYPE} == mysql
CONFIGURE_ENV+= LIBS='-L${PREFIX}/lib/mysql -L${PREFIX}/lib -lmysqlclient -lm -lgd'
.elif defined(PHP3_DBTYPE) && ${PHP3_DBTYPE} == pgsql
CONFIGURE_ENV+= LIBS='-lmd -L${PREFIX}/pgsql/lib -lpq -L${PREFIX}/lib -lgd -lm'
.endif

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/apache.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/apache.sh startup file."; \
		${ECHO} "#!/bin/sh" > ${PREFIX}/etc/rc.d/apache.sh; \
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
	/bin/ln -s ${PREFIX}/share/doc/apache/$i ${PREFIX}/www/data/$i
.endfor
.for i in CODING_STANDARDS EXTENSION_STATUS LICENSE
	${INSTALL_DATA} ${WRKDIR}/php-3.0.2/$i ${PHP3DOCDIR}
.endfor
	@ ${ECHO} "Docs reside in ${APACHEDOCDIR}"
	@ ${ECHO} "and in ${PHP3DOCDIR}"
.endif

.include <bsd.port.mk>
