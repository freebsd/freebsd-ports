# New ports collection makefile for:	mod_php4
# Date created:		Sun May 28 11:31:54 CEST 2000
# Whom:			Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME?=	mod_php4
PORTVERSION=	4.1.1
PORTREVISION?=	0
CATEGORIES?=	www
MASTER_SITES=	http://us.php.net/${PHP_DISTDIR}/ \
		http://php.he.net/${PHP_DISTDIR}/ \
		http://www.php3.de/${PHP_DISTDIR}/ \
		http://au.php.net/${PHP_DISTDIR}/ \
		http://at.php.net/${PHP_DISTDIR}/ \
		http://br.php.net/${PHP_DISTDIR}/ \
		http://php.easydns.com/${PHP_DISTDIR}/ \
		http://www.php.cz/${PHP_DISTDIR}/ \
		http://php3.globe.de/${PHP_DISTDIR}/
DISTNAME=	php-${PORTVERSION}

MAINTAINER=	dirk@FreeBSD.org

.if !defined(STANDALONE)
BUILD_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache13
RUN_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache13
.endif

PHP_DISTDIR=	distributions

SLAVEDIRS=	lang/php4

USE_AUTOCONF=	yes
GNU_CONFIGURE=	yes

.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
IS_INTERACTIVE=	yes
.endif

.if defined(STANDALONE)
CONFIGURE_ARGS=	--with-config-file-path=${PREFIX}/etc/php.standalone \
		--disable-pear \
		--enable-discard-path \
		--with-readline=/usr

MAKE_ENV=	STANDALONE="${STANDALONE}"
.else
CONFIGURE_ARGS=	--with-apxs=${PREFIX}/sbin/apxs \
		--with-config-file-path=${PREFIX}/etc
.endif

CONFIGURE_ARGS+=--enable-versioning \
		--with-system-regex \
		--disable-debug \
		--enable-track-vars \
		--without-gd \
		--without-mysql

CFLAGS+=	-I${PREFIX}/include

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
	@${INSTALL_DATA} ${WRKSRC}/php.ini-dist ${PREFIX}/etc
.else
	@${MKDIR} ${PREFIX}/etc/php.standalone
	@${INSTALL_DATA} ${WRKSRC}/php.ini-dist ${PREFIX}/etc/php.standalone
.endif

.if !defined(STANDALONE)
	@${ECHO} "*****************************************************************************"
	@${ECHO} "Make sure the mime.types are connected to the php module properly and"
	@${ECHO} "index.php is part of your DirectoryIndex."
	@${ECHO} ""
	@${ECHO} "The following should be in your Apache configuration file:"
	@${ECHO} "[...]"
	@${ECHO} "DirectoryIndex index.php index.html"
	@${ECHO} "[...]"
	@${ECHO} "AddType application/x-httpd-php .php"
	@${ECHO} "AddType application/x-httpd-php-source .phps"
	@${ECHO} "[...]"
	@${ECHO} "*****************************************************************************"
.endif

post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.endif

post-extract: ${POSTEXTRACT}

.include <bsd.port.mk>
