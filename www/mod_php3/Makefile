# New ports collection makefile for:	mod_php3
# Date created:		Wed Feb 23 11:28:12 CEST 2000
# Whom:			Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME?=	mod_php3
PORTVERSION=	3.0.18
PORTREVISION?=	4
CATEGORIES?=	www
MASTER_SITES=	${MASTER_SITE_PHP}
MASTER_SITE_SUBDIR=	distributions
DISTNAME=	php-${PORTVERSION}

PATCH_SITES=	${MASTER_SITE_PHP}
PATCH_SITE_SUBDIR=	distributions
PATCHFILES=	mime.c.diff-3.0.gz

MAINTAINER=	apache@FreeBSD.org
COMMENT?=	PHP3 module for Apache

.if !defined(STANDALONE)
USE_APACHE=	yes
.endif

PATCH_DIST_ARGS=	-d ${WRKSRC}/functions

SLAVEDIRS=	lang/php3

USE_SUBMAKE=	yes
GNU_CONFIGURE=	yes

.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
IS_INTERACTIVE=	yes
.endif

.if defined(STANDALONE)
CONFIGURE_ARGS=	--with-config-file-path=${PREFIX}/etc/php.standalone \
		--enable-discard-path
.else
CONFIGURE_ARGS=	--with-apxs=${APXS} \
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

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386" && ${ARCH} != "alpha"
BROKEN=		"Does not compile on !i386 and !alpha"
.endif

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

# XXX:
# Has to be kept in sync with the defaults in configure.php
.ifndef(WITHOUT_MYSQL)
.ifmake describe
USE_MYSQL=	yes
.endif
.endif

.include <bsd.port.post.mk>
