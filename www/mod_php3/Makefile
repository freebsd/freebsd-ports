# New ports collection makefile for:	mod_php3
# Date created:		Wed Feb 23 11:28:12 CEST 2000
# Whom:			Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME?=	mod_php3
PORTVERSION=	3.0.18
PORTREVISION?=	3
CATEGORIES?=	www
MASTER_SITES=	ftp://ftp.php.net/pub/${PHP_DISTDIR}/ \
		http://us.php.net/${PHP_DISTDIR}/ \
		http://php.he.net/${PHP_DISTDIR}/ \
		http://www.php3.de/${PHP_DISTDIR}/ \
		http://au.php.net/${PHP_DISTDIR}/ \
		http://at.php.net/${PHP_DISTDIR}/ \
		http://br.php.net/${PHP_DISTDIR}/ \
		http://php.easydns.com/${PHP_DISTDIR}/ \
		http://www.php.cz/${PHP_DISTDIR}/ \
		http://php3.globe.de/${PHP_DISTDIR}/
DISTNAME=	php-${PORTVERSION}

PATCH_SITES=	http://www.php.net/distributions/
PATCHFILES=	mime.c.diff-3.0.gz

MAINTAINER=	dirk@FreeBSD.org

.if !defined(STANDALONE)
BUILD_DEPENDS=	${APXS}:${APACHE_PORT}
RUN_DEPENDS=	${APXS}:${APACHE_PORT}
.endif

PATCH_DIST_ARGS=	-d ${WRKSRC}/functions

PHP_DISTDIR=	distributions

SLAVEDIRS=	lang/php3
APACHE_PORT?=	${PORTSDIR}/www/apache13
APXS?=		${LOCALBASE}/sbin/apxs

USE_SUBMAKE=	yes
GNU_CONFIGURE=	yes

.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
IS_INTERACTIVE=	yes
.endif

.if defined(STANDALONE)
CONFIGURE_ARGS=	--with-config-file-path=${PREFIX}/etc/php.standalone \
		--enable-discard-path
.else
CONFIGURE_ARGS=	--with-apxs=${PREFIX}/sbin/apxs \
		--with-config-file-path=${PREFIX}/etc
.endif

CONFIGURE_ARGS+=--enable-versioning \
		--with-system-regex \
		--disable-debug \
		--enable-track-vars \
		--without-gd

SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		TOUCH="${TOUCH}" \
		MKDIR="${MKDIR}" \
		CAT="${CAT}" \
		REALCURDIR="${.CURDIR}"

AP_LIBEXEC=	${PREFIX}/libexec/apache

PLIST_SUB=	AP_LIBEXEC=${AP_LIBEXEC:S/^${PREFIX}\///}

pre-fetch:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure.php

post-install:
.if !defined(STANDALONE)
	@${INSTALL_DATA} ${WRKSRC}/php3.ini-dist ${PREFIX}/etc
.else
	@${MKDIR} ${PREFIX}/etc/php.standalone
	@${INSTALL_DATA} ${WRKSRC}/php3.ini-dist ${PREFIX}/etc/php.standalone
.endif

.if !defined(STANDALONE)
	@${ECHO} "*****************************************************************************"
	@${ECHO} "Make sure the mime.types are connected to the php module properly and"
	@${ECHO} "index.php3 is part of your DirectoryIndex."
	@${ECHO} ""
	@${ECHO} "The following should be in your Apache configuration file:"
	@${ECHO} "[...]"
	@${ECHO} "DirectoryIndex index.php3 index.html"
	@${ECHO} "[...]"
	@${ECHO} "AddType application/x-httpd-php3 .php3"
	@${ECHO} "AddType application/x-httpd-php3-source .php3s"
	@${ECHO} "[...]"
	@${ECHO} "*****************************************************************************"
.endif

post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.endif

.include <bsd.port.mk>
