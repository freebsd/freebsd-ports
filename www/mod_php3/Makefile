# New ports collection makefile for:	mod_php3
# Date created:		Wed Feb 23 11:28:12 CEST 2000
# Whom:			Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME?=	mod_php3
PORTVERSION=	3.0.18
CATEGORIES?=	www
MASTER_SITES=	ftp://ftp.php.net/pub/${PHP_DISTDIR}/ \
		http://us.php.net/${PHP_DISTDIR}/ \
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

.if !defined(STANDALONE)
BUILD_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache13
RUN_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache13
.endif

PHP_DISTDIR=	distributions

SLAVEDIRS=	lang/php3

GNU_CONFIGURE=	yes

.if defined(STANDALONE)
CONFIGURE_ARGS=	--with-config-file-path=${PREFIX}/etc/php.standalone
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

PHPDOCDIR=	${PREFIX}/share/doc/php3
PLIST_SUB=	PHPDOCDIR=${PHPDOCDIR:S/^${PREFIX}\///} \
		AP_LIBEXEC=${AP_LIBEXEC:S/^${PREFIX}\///}

pre-fetch:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure.php

post-install:
.if !defined(STANDALONE)
	@${ECHO} "Restarting Apache..."
	@${PREFIX}/sbin/apachectl restart
	@${INSTALL_DATA} ${WRKSRC}/php3.ini-dist ${PREFIX}/etc
.else
	@${MKDIR} ${PREFIX}/etc/php.standalone
	@${INSTALL_DATA} ${WRKSRC}/php3.ini-dist ${PREFIX}/etc/php.standalone
.endif

.if !defined(NOPORTDOCS)
	@${MKDIR} ${PHPDOCDIR}
.for i in CODING_STANDARDS LICENSE
	@${INSTALL_DATA} ${WRKSRC}/$i ${PHPDOCDIR}
.endfor
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
