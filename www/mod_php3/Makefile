# New ports collection makefile for:	mod_php3
# Date created:		Wed Feb 23 11:28:12 CEST 2000
# Whom:			Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_php
PORTVERSION= 	3.0.16
CATEGORIES=	www
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

BUILD_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache13
RUN_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache13

Y2K=		http://www.php.net/y2k.php3

PHP_DISTDIR=	distributions

APXS=		${PREFIX}/sbin/apxs

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-apxs=${APXS} \
		--with-system-regex \
		--with-config-file-path=${PREFIX}/etc \
		--disable-debug \
		--enable-track-vars \
		--without-gd

SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		TOUCH="${TOUCH}" \
		MKDIR="${MKDIR}"

.if exists(${APXS})
AP_LIBEXEC!=	${APXS} -q LIBEXEC
.else
AP_LIBEXEC=	${PREFIX}/libexec/apache
.endif

PHPDOCDIR=	${PREFIX}/share/doc/php3
PLIST_SUB=	PHPDOCDIR=${PHPDOCDIR:S/^${PREFIX}\///} \
		AP_LIBEXEC=${AP_LIBEXEC:S/^${PREFIX}\///}

pre-fetch:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure.php

post-install:
	@${ECHO} "Restarting Apache..."
	@${PREFIX}/sbin/apachectl restart
	@${INSTALL_DATA} ${WRKSRC}/php3.ini-dist ${PREFIX}/etc

.if !defined(NOPORTDOCS)
	@${MKDIR} ${PHPDOCDIR}
.for i in CODING_STANDARDS LICENSE
	@${INSTALL_DATA} ${WRKSRC}/$i ${PHPDOCDIR}
.endfor
.endif
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

post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.endif

.include <bsd.port.mk>
