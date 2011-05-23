# Ports collection makefile for:  horde3
# Date created:			  Sun Oct 07, 2001
# Whom:				  Thierry Thomas (<thierry@thomas.as>)
#
# $FreeBSD$
#

PORTNAME=	horde
PORTVERSION=	4.0.2
DISTVERSIONPREFIX=
CATEGORIES=	www
PKGNAMEPREFIX=
PKGNAMESUFFIX=	4-base

MAINTAINER=	beech@FreeBSD.org
COMMENT=	Common code-base used by Horde applications

#----------------------------------------------------------------------------
# You may define these options:
#
# - WITHOUT_SUPPORTED_DB: if you run a database not in the ports tree.
#
# - WITHOUT_MYSQL:	this port is built with MySQL by default
#			but you might choose any other database
#			supported by PHP (e.g. WITH_POSTGRESQL / WITH_SQLITE).
#
# - WITHOUT_IMAP:	this port uses IMAP as a default authentication
#			backend; use this knob if for
#			example you only need Chora.
#
# - WITHOUT_LDAP:	if you do not need OpenLDAP.
#
# - WITHOUT_FTP:	if you do not need the VFS FTP driver.
#
# - WITH_IMSP:		use IMSP as a preferences backend.
#
# - WITHOUT_FILEINFO:	use native code to perform MIME magic lookups.
#
# - WITHOUT_GD:		don't perform manipulations on image data with gd.
#
# - WITHOUT_ZLIB:	don't compress pages and don't handle zip or gz data.
#
# - WITH_MAGICK:	use ImageMagick to perform these image manipulations.
#
# - WITHOUT_ICONV:	remove support for UTF-8 character sets.
# - WITHOUT_MBSTRING:
#
# - WITHOUT_WV		if your users never receive MS-Word docs;
#
# - WITHOUT_XL		if your users never receive MS-Excel sheets
#			  (or .ppt presentations);
#
# - WITHOUT_GEOIP	don't activate MaxMind GeoIP Hostname to Country lookup.
#
# - WITHOUT_SW		don't use the weather.com block on the portal page.
#
# - WITHOUT_WEBCPP:	don't highlight sources with webcpp.
#
# - WITH_SRCHIGH:	highlight sources with source-highlight.
#
# - WITH_ENSCRIPT:	highlight sources with enscript.
#
# - WITH_RPM:		handle RPM packages.
#
# - WITH_DEB:		handle Debian packages.
#
# - WITH_SUPHP:		Install appropriately for use with the www/suphp port.
#
#----------------------------------------------------------------------------

LATEST_LINK=	horde4-base
RUN_DEPENDS+=	${PEARDIR}/Date.php:${PORTSDIR}/devel/pear-Date			\
		${PEARDIR}/Log.php:${PORTSDIR}/sysutils/pear-Log		\
		${PEARDIR}/Mail/RFC822.php:${PORTSDIR}/mail/pear-Mail		\
		${PEARDIR}/Mail/mime.php:${PORTSDIR}/mail/pear-Mail_Mime	\
		${PEARDIR}/Mail/mimeDecode.php:${PORTSDIR}/mail/pear-Mail_mimeDecode	\
		${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB			\
		${PEARDIR}/File.php:${PORTSDIR}/sysutils/pear-File		\
		${PEARDIR}/Net/SMTP.php:${PORTSDIR}/net/pear-Net_SMTP   \
		${PEARDIR}/MDB2/Schema/Validate.php:${PORTSDIR}/databases/pear-MDB2_Schema

CONFLICTS=	horde-3.*

USE_GETTEXT=	yes
USE_PHP=	ctype gettext session dom

EXTRACT_SUFX=	.tgz

.if defined(WITH_SUPHP) && !defined(WITHOUT_SUPHP)
RUN_DEPENDS+=	${LOCALBASE}/sbin/suphp:${PORTSDIR}/www/suphp
WANT_PHP_CGI=	yes
HORDEADMUSR?=	horde
SUB_LIST=	WITH_SUPHP=yes
.else
WANT_PHP_WEB=	yes
.endif

.if !defined(WITHOUT_FILEINFO)
USE_PHP+=	fileinfo
.endif
.if !defined(WITHOUT_FTP)
USE_PHP+=	ftp
.endif
.if !defined(WITHOUT_GD)
USE_PHP+=	gd
.endif
.if !defined(WITHOUT_ICONV)
USE_PHP+=	iconv
.endif
.if !defined(WITHOUT_IMAP)
USE_PHP+=	imap
.endif
.if !defined(WITHOUT_LDAP)
USE_PHP+=	ldap
.endif
.if !defined(WITHOUT_MBSTRING)
USE_PHP+=	mbstring
.endif
.if !defined(NOCRYPT)
USE_PHP+=	mcrypt
.endif
.if !defined(WITHOUT_SUPPORTED_DB)
. if !defined(WITHOUT_MYSQL)
USE_PHP+=	mysql
. endif
. if defined(WITH_POSTGRESQL) || defined(WITH_PGSQL)
USE_PHP+=	pgsql
. endif
. if defined(WITH_SQLITE)
USE_PHP+=	sqlite
. endif
.endif
.if !defined(WITHOUT_ZLIB)
USE_PHP+=	zlib
.endif
.if defined(WITH_MAGICK)
RUN_DEPENDS+=	convert:${PORTSDIR}/graphics/ImageMagick
.endif
.if defined(WITH_IMSP)
RUN_DEPENDS+=	imspd:${PORTSDIR}/databases/cyrus-imspd
.endif

.if !defined(WITHOUT_X11)
. if !defined(WITHOUT_WV)
RUN_DEPENDS+=	${LOCALBASE}/bin/wvHtml:${PORTSDIR}/textproc/wv
. endif
. if !defined(WITHOUT_XL)
RUN_DEPENDS+=	${LOCALBASE}/bin/xlhtml:${PORTSDIR}/textproc/xlhtml
. endif
.endif

.if !defined(WITHOUT_WEBCPP)
RUN_DEPENDS+=	webcpp:${PORTSDIR}/textproc/webcpp
.endif

.if exists(${LOCALBASE}/bin/source-highlight)
WITH_SRCHIGH=	yes
.endif
.if defined(WITH_SRCHIGH)
RUN_DEPENDS+=	source-highlight:${PORTSDIR}/textproc/source-highlight
.endif

.if exists(${LOCALBASE}/bin/enscript)
WITH_ENSCRIPT=	yes
.endif
.if defined(WITH_ENSCRIPT)
. if defined(A4)
RUN_DEPENDS+=	enscript:${PORTSDIR}/print/enscript-a4
. elif defined(DJ)
RUN_DEPENDS+=	enscript:${PORTSDIR}/print/enscript-letterdj
. else
RUN_DEPENDS+=	enscript:${PORTSDIR}/print/enscript-letter
. endif
.endif

.if exists(${LOCALBASE}/bin/rpm)
WITH_RPM=	yes
.endif
.if defined(WITH_RPM)
RUN_DEPENDS+=	rpm:${PORTSDIR}/archivers/rpm4
.endif

.if exists(${LOCALBASE}/bin/dpkg)
WITH_DEB=	yes
.endif
.if defined(WITH_DEB)
RUN_DEPENDS+=	dpkg:${PORTSDIR}/archivers/dpkg
.endif

.if !defined(WITHOUT_SW)
RUN_DEPENDS+=	${PEARDIR}/Services/Weather.php:${PORTSDIR}/misc/pear-Services_Weather
.endif

.if !defined(WITHOUT_GEOIP)
RUN_DEPENDS+=	${LOCALBASE}/share/GeoIP/GeoIP.dat:${PORTSDIR}/net/GeoIP
.endif

PORTDOCS=	README CHANGES CODING_STANDARDS CONTRIBUTING CREDITS INSTALL \
		PERFORMANCE RELEASE_NOTES SECURITY TRANSLATIONS UPGRADING

.include <bsd.port.pre.mk>

pre-install:
.if !defined(WITHOUT_SUPPORTED_DB) && exists(${LOCALBASE}/bin/php)
	@if ! php -m 2>&1 | ${GREP} -q -e "mysql" ; then \
	 if ! php -m 2>&1 | ${GREP} -q -e "pgsql" ; then \
	  if ! php -m 2>&1 | ${GREP} -q -e "sybase" ; then \
	   if ! php -m 2>&1 | ${GREP} -q -e "SQLite" ; then \
	    ${ECHO_MSG} "" ; \
	    ${ECHO_MSG} "Please configure PHP with a database support." ; \
	    ${ECHO_MSG} "MySQL, PostgreSQL, SQLite and Sybase (CTLIB or DBLIB)" ; \
	    ${ECHO_MSG} "can be used with PHP AND Horde." ; \
	    ${ECHO_MSG} "" ; \
	    ${ECHO_MSG} "(If everything will run on this machine, do not" ; \
	    ${ECHO_MSG} " forget to install the database server-side!)" ; \
	    ${ECHO_MSG} "" ; \
	    ${FALSE} ; \
	   fi ; \
	  fi ; \
	 fi ; \
	fi
.endif
.if defined(WITH_SUPHP)
	${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
.endif

.include "${.CURDIR}/../../www/horde4-base/bsd.horde4.mk"
.include <bsd.port.post.mk>
