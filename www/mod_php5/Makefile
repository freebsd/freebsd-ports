# New ports collection makefile for:	apache HTTPD / php
# Version required:	1.2.6 / 3.0
# Date created:		Wed Sep  3 18:28:20 CEST 1997
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.45 1998/06/14 09:57:32 andreas Exp $
#

DISTNAME=	apache_1.2.6
PKGNAME=	apache-1.2.6-php3.0
CATEGORIES=	www
MASTER_SITES=	ftp://www.apache.org/apache/dist/ \
		http://ca.php.net/distributions/
DISTFILES=	apache_1.2.6.tar.gz php-3.0.tar.gz

MAINTAINER=	andreas@FreeBSD.ORG

BUILD_DEPENDS=	${PREFIX}/lib/libgd.a:${PORTSDIR}/graphics/gd \
		gmake:${PORTSDIR}/devel/gmake

NO_PACKAGE=	"Support for different databases via make-variable"

MAN1=		htpasswd.1
MAN8=		httpd.8
DOCDIR=		${PREFIX}/share/doc/apache

.if defined(PATCH_DEBUG)
PATCH_DIST_ARGS= -d ${WRKSRC}/src -E ${PATCH_DIST_STRIP}
.else
PATCH_DIST_ARGS= -d ${WRKSRC}/src --forward --quiet -E ${PATCH_DIST_STRIP}
.endif

# Set it for local-supplied patch, f.e.
VERS_ID = PHP-3.0

PHP3_CONF_ARGS=	--prefix=${PREFIX} \
		--with-system-regex --with-apache=${WRKSRC} \
		--with-config-file-path=${PREFIX}/lib --disable-debug

.if !defined(PHP3_DBTYPE) || ${PHP3_DBTYPE} != msql && ${PHP3_DBTYPE} != mysql && ${PHP3_DBTYPE} != pgsql && ${PHP3_DBTYPE} != dbase
pre-fetch:
	@ ${ECHO}
	@ ${ECHO} "You must set variable PHP3_DBTYPE to msql, mysql or pgsql by typing"
	@ ${ECHO} "make PHP3_DBTYPE=[ dbase | msql | mysql | pgsql ]"
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
.elif ${PHP3_DBTYPE} == dbase
PHP3_CONF_ARGS+=	--with-dbase
.endif
.endif

.if defined(VERS_ID)
post-patch:
	@cd ${WRKSRC}/src && \
	${MV} Configuration Configuration.old && \
	${SED} 's;^#*OPTIM=.*;OPTIM= -DSERVER_SUBVERSION=\\"${VERS_ID}\\";' \
	< Configuration.old > Configuration
.endif

pre-configure:
	( cd ${WRKDIR}/php-3.0 \
	&& CC="${CC}" CFLAGS="${CFLAGS}" ./configure ${PHP3_CONF_ARGS} \
	&& ${GMAKE} install )
	${ECHO} "Module php3_module mod_php3.o" >> ${WRKSRC}/src/Configuration
.if defined(PHP3_DBTYPE) && ${PHP3_DBTYPE} == msql
	${ECHO} "EXTRA_LIBS=-lmd libphp3.a -L${PREFIX}/lib -lmsql -lgd -lm" >> ${WRKSRC}/src/Configuration
.elif defined(PHP3_DBTYPE) && ${PHP3_DBTYPE} == mysql
	${ECHO} "EXTRA_LIBS=-lmd libphp3.a -L${PREFIX}/lib/mysql -lmysqlclient -L${PREFIX}/lib -lgd -lm"  >> ${WRKSRC}/src/Configuration
.elif defined(PHP3_DBTYPE) && ${PHP3_DBTYPE} == pgsql
	${ECHO} "EXTRA_LIBS=-lmd libphp3.a -L${PREFIX}/pgsql/lib -lpq -L${PREFIX}/lib -lgd -lm" >> ${WRKSRC}/src/Configuration
.elif defined(PHP3_DBTYPE) && ${PHP3_DBTYPE} == dbase
	${ECHO} "EXTRA_LIBS=-lmd libphp3.a libdbf.a -L${PREFIX}/lib -lgd -lm" >> ${WRKSRC}/src/Configuration
.endif

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/apache.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/apache.sh startup file."; \
		${SED} 's;PREFIX;${PREFIX};' < ${FILESDIR}/apache.sh.tmpl > \
		${PREFIX}/etc/rc.d/apache.sh; \
		chmod 751 ${PREFIX}/etc/rc.d/apache.sh; \
	fi
.for i in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/support/$i ${PREFIX}/man/man1
.endfor
.for i in ${MAN8}
	${INSTALL_MAN} ${WRKSRC}/support/$i ${PREFIX}/man/man8
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCDIR}
.for i in README LICENSE ABOUT_APACHE
	${INSTALL_DATA} ${WRKSRC}/$i ${DOCDIR}
.endfor
	@cd ${WRKSRC}/htdocs; tar cf - . | (cd ${DOCDIR}; tar xf -)
.endif

.include <bsd.port.mk>
