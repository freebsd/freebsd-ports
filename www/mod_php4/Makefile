# New ports collection makefile for:	mod_php4
# Date created:		Sun May 28 11:31:54 CEST 2000
# Whom:			Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_php
PORTVERSION= 	4.0.0
CATEGORIES=	www
MASTER_SITES=	http://us.php.net/${PHP_DISTDIR}/ \
		http://php.he.net/${PHP_DISTDIR}/ \
		http://www.php3.de/${PHP_DISTDIR}/ \
		http://au.php.net:81/${PHP_DISTDIR}/ \
		http://at.php.net/${PHP_DISTDIR}/ \
		http://br.php.net/${PHP_DISTDIR}/ \
		http://php.easydns.com/${PHP_DISTDIR}/ \
		http://www.php.cz/${PHP_DISTDIR}/ \
		http://php3.globe.de/${PHP_DISTDIR}/
DISTNAME=	php-${PORTVERSION}

MAINTAINER=	dirk@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache13
RUN_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache13

Y2K=		http://www.php.net/y2k.php3

PHP_DISTDIR=	version4/downloads

APXS=		${PREFIX}/sbin/apxs

USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--with-apxs=${APXS} \
		--enable-versioning \
		--with-system-regex \
		--with-config-file-path=${PREFIX}/etc \
		--disable-debug \
		--enable-track-vars \
		--without-gd \
		--disable-pear

SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		TOUCH="${TOUCH}" \
		MKDIR="${MKDIR}"

.if exists(${APXS})
AP_LIBEXEC!=	${APXS} -q LIBEXEC
.else
AP_LIBEXEC=	${PREFIX}/libexec/apache
.endif

PHPDOCDIR=	${PREFIX}/share/doc/php
PLIST_SUB=	PHPDOCDIR=${PHPDOCDIR:S/^${PREFIX}\///} \
		AP_LIBEXEC=${AP_LIBEXEC:S/^${PREFIX}\///}

pre-fetch:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure.php

post-install:
	@${ECHO} "Restarting Apache..."
	@${PREFIX}/sbin/apachectl restart
	@${INSTALL_DATA} ${WRKSRC}/php.ini-dist ${PREFIX}/etc

.if !defined(NOPORTDOCS)
	@${MKDIR} ${PHPDOCDIR}
.for i in CODING_STANDARDS LICENSE
	@${INSTALL_DATA} ${WRKSRC}/$i ${PHPDOCDIR}
.endfor
.endif
	@${ECHO} "*****************************************************************************"
	@${ECHO} "Make sure the mime.types are connected to the php module properly and"
	@${ECHO} "index.php is part of your DirectoryIndex."
	@${ECHO} ""
	@${ECHO} "The following should be in your Apache configuration file:"
	@${ECHO} "[...]"
	@${ECHO} "DirectoryIndex index.php index.html"
	@${ECHO} "[...]"
	@${ECHO} "AddType application/x-httpd-php .php"
	@${ECHO} "AddType application/x-httpd-php-source .php3"
	@${ECHO} "[...]"
	@${ECHO} "*****************************************************************************"

post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.endif

.include <bsd.port.mk>
