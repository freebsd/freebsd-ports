# Ports collection makefile for:  horde2
# Date created:			  Sun Oct 07, 2001
# Whom:				  Thierry Thomas (<thierry@thomas.as>)
#
# $FreeBSD$
#

PORTNAME=	horde
PORTVERSION=	3.0.4
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.horde.org/pub/horde/				\
		ftp://ftp.planetmirror.com/pub/horde/horde/		\
		ftp://ftp.au.horde.org/pub/horde/horde/			\
		ftp://ftp.be.horde.org/horde/				\
		ftp://ftp.es.horde.org/pub/horde/			\
		ftp://ftp.it.horde.org/pub/mirror/horde.org/horde/	\
		ftp://ftp.nl.horde.org/mirror/horde-ftp/pub/horde/	\
		ftp://ftp.uk.horde.org/mirrors/ftp.horde.org/pub/horde/	\
		http://ftp.horde.org/pub/horde/
.if defined(WITH_PHP5)
PKGNAMESUFFIX=	-php5
.endif

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	A common code-base used by Horde applications, written in PHP

#----------------------------------------------------------------------------
# You may define these options:
#
# - WITH_APACHE2:	if you run Apache2.
#
# - WITH_PHP5: 		if you run PHP5 (you could use www/horde-php5).
#
# - WITHOUT_SUPPORTED_DB: if you run a database not in the ports tree.
#
# - WITHOUT_MYSQL:	this port is built with MySQL by default
#			but you might choose any other database
#			supported by PHP (e.g. WITH_POSTGRESQL).
#
# - WITHOUT_IMAP:	this port uses IMAP as a default authentication
#			backend; use this knob if for
#			example you only need Chora.
#
# - WITHOUT_LDAP:	if you do not need OpenLDAP.
#
# - WITHOUT_FTP:	if you do not need the VFS FTP driver.
#
# - WITHOUT_MCAL:	if you don't plan to install Kronolith.
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
#----------------------------------------------------------------------------

RUN_DEPENDS+=	${PEARDIR}/Date.php:${PORTSDIR}/devel/pear-Date			\
		${PEARDIR}/Log.php:${PORTSDIR}/sysutils/pear-Log		\
		${PEARDIR}/Mail/mime.php:${PORTSDIR}/mail/pear-Mail_Mime	\
		${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB			\
		${PEARDIR}/File.php:${PORTSDIR}/sysutils/pear-File		\
		${PEARDIR}/Net/SMTP.php:${PORTSDIR}/net/pear-Net_SMTP

CONFLICTS=	horde-2.*

NO_BUILD=	yes
USE_PHP=	ctype gettext session
WANT_PHP_MOD=	yes
USE_REINPLACE=	yes
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

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
. if defined(WITH_POSTGRESQL)
USE_PHP+=	pgsql
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

REINPLACE_ARGS=	-i.beforeHorde
DOCS=		COPYING README docs/CHANGES docs/CODING_STANDARDS \
		docs/CONTRIBUTING docs/CREDITS docs/HACKING docs/INSTALL \
		docs/PERFORMANCE docs/RELEASE_NOTES docs/SECURITY docs/TODO \
		docs/TRANSLATIONS docs/UPGRADING
CONFFILE=	conf.php mime_drivers.php motd.php nls.php prefs.php registry.php
SUB_DIRS=	admin config js lib locale po scripts services templates themes util

LHORDEDIR?=	www/horde
LHORDESBIN?=	sbin

PLIST_SUB=	HORDEDIR=${LHORDEDIR} HORDESBIN=${LHORDESBIN}
SUB_LIST=	HORDEDIR=${HORDEDIR} APACHE_CONF=${APACHE_CONF} HORDESBIN=${HORDESBIN}

HORDEDIR=	${PREFIX}/${LHORDEDIR}
HORDESBIN=	${PREFIX}/${LHORDESBIN}
CONFDIR=	${HORDEDIR}/config

APACHE_CONF=	${APACHE_CNFDIR}/httpd.conf
PEARDIR?=	${LOCALBASE}/share/pear
.if defined(WITH_APACHE2)
APACHE_CNFDIR=	${LOCALBASE}/etc/apache2
.else
APACHE_CNFDIR=	${LOCALBASE}/etc/apache
.endif
HORDE_INC=	${PREFIX}/etc/horde
LOG_FILE?=	/var/log/horde.log

.if defined(WITH_PHP5)
USE_PHP+=	dom
.else
USE_PHP+=	domxml
. if !defined(WITHOUT_MCAL)
USE_PHP+=	mcal
. endif
.endif

.include <bsd.port.pre.mk>	# Required to test PHP_VER

pre-configure:
	@${RM} ${WRKSRC}/po/translation.php.orig	\
		${WRKSRC}/config/conf.xml.orig		\
		${WRKSRC}/scripts/sql/README.orig	\
		${WRKSRC}/config/mime_drivers.php.dist.orig
	@${SED} -e "s:/home/httpd/html/horde:${HORDEDIR}:"				\
		-e "s:php_value auto_prepend_file:# php_value auto_prepend_file:"	\
		-e "s:/home/httpd/phplib:${PEARDIR}:"					\
		${FILESDIR}/httpd.conf.horde > ${WRKDIR}/httpd.conf.horde
.if ${PHP_VER} == 5
	@${REINPLACE_CMD} -e "s:mod_php4.c:mod_php5.c:" ${WRKDIR}/httpd.conf.horde
.endif
	@${REINPLACE_CMD} -e "s:%%LOCALBASE%%:${LOCALBASE}:" ${WRKSRC}/config/mime_drivers.php.dist
.if !defined(WITHOUT_X11)
. if !defined(WITHOUT_WV)
	@${REINPLACE_CMD} -e "s://UNCOMMENTIFWV::" ${WRKSRC}/config/mime_drivers.php.dist
. endif
. if !defined(WITHOUT_XL)
	@${REINPLACE_CMD} -e "s://UNCOMMENTIFXL::" ${WRKSRC}/config/mime_drivers.php.dist
. endif
.endif
.if !defined(WITHOUT_WEBCPP)
	@${REINPLACE_CMD} -e "s://UNCOMMENTIFWCPP::" ${WRKSRC}/config/mime_drivers.php.dist
.endif
.if defined(WITH_SRCHIGH)
	@${REINPLACE_CMD} -e "s://UNCOMMENTIFSRCHIGH::" ${WRKSRC}/config/mime_drivers.php.dist
.endif
.if defined(WITH_ENSCRIPT)
	@${REINPLACE_CMD} -e "s://UNCOMMENTIFES::" ${WRKSRC}/config/mime_drivers.php.dist
.endif
.if defined(WITH_RPM)
	@${REINPLACE_CMD} -e "s://UNCOMMENTIFRPM::" ${WRKSRC}/config/mime_drivers.php.dist
.endif
.if defined(WITH_DEB)
	@${REINPLACE_CMD} -e "s://UNCOMMENTIFDEB::" ${WRKSRC}/config/mime_drivers.php.dist
.endif
.if !defined(WITHOUT_GEOIP)
	@${REINPLACE_CMD} -e "s:GeoIP lookup will not be performed.\"/>:GeoIP lookup will not be performed.\">${LOCALBASE}/share/GeoIP/GeoIP.dat</configstring>:" \
		${WRKSRC}/config/conf.xml
.endif
	@${REINPLACE_CMD} -e "s:/tmp/horde.log:${LOG_FILE}:" ${WRKSRC}/config/conf.xml
	@${REINPLACE_CMD} -e "s:/etc/mpasswd:${LOCALBASE}/etc/mpasswd:g"	\
		${WRKSRC}/lib/Horde/Auth/mcal.php
	@${REINPLACE_CMD} -e "s:/usr/local/apache/htdocs:${PREFIX}/www:g"	\
		${WRKSRC}/docs/INSTALL
	@${RM} ${WRKSRC}/lib/Horde/Auth/mcal.php.beforeHorde	\
		${WRKSRC}/config/conf.xml.beforeHorde		\
		${WRKSRC}/config/mime_drivers.php.dist.beforeHorde	\
		${WRKSRC}/docs/INSTALL.beforeHorde

pre-install:
.if !defined(WITHOUT_SUPPORTED_DB)
	@if ! php -m | ${GREP} -q -e "mysql" ; then \
	 if ! php -m | ${GREP} -q -e "pgsql" ; then \
	  if ! php -m | ${GREP} -q -e "sybase" ; then \
	    ${ECHO_MSG} "" ; \
	    ${ECHO_MSG} "Please configure PHP with a database support." ; \
	    ${ECHO_MSG} "MySQL, PostgreSQL and Sybase (CTLIB or DBLIB)" ; \
	    ${ECHO_MSG} "can be used with PHP AND Horde." ; \
	    ${ECHO_MSG} "" ; \
	    ${ECHO_MSG} "(If everything will run on this machine, do not" ; \
	    ${ECHO_MSG} " forget to install the database server-side!)" ; \
	    ${ECHO_MSG} "" ; \
	    ${FALSE} ; \
	  fi ; \
	 fi ; \
	fi
.endif

do-install:
	@${MKDIR}  ${HORDEDIR}
.for REP in ${SUB_DIRS}
	@${CP} -Rp ${WRKSRC}/${REP} ${HORDEDIR}
.endfor
	@${CP} -p  ${WRKSRC}/*.php ${HORDEDIR}
.for FILE in ${CONFFILE}
	@if [ ! -f ${CONFDIR}/${FILE} ]; then \
	  ${CP} ${CONFDIR}/${FILE}.dist ${CONFDIR}/${FILE} ; \
	fi
.endfor
	@${CP} ${WRKSRC}/scripts/set_perms.sh ${HORDESBIN}/horde_set_perms.sh
	@${CHMOD} u+x ${HORDESBIN}/horde_set_perms.sh
	@${MKDIR} ${HORDE_INC}
	@${INSTALL_DATA} ${WRKDIR}/httpd.conf.horde ${HORDE_INC}
	@(if [ -f ${APACHE_CONF} ] ; then \
		${ECHO_MSG} "===> Updating ${APACHE_CONF}..." ; \
		${ECHO_CMD} "# Horde's include directory" >> ${APACHE_CONF} ; \
		${ECHO_CMD} "Include ${HORDE_INC}" >> ${APACHE_CONF} ; \
	fi)
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${HORDEDIR}
	@${CHMOD} -R o-rwx ${CONFDIR}
	@${TOUCH} ${LOG_FILE}
	@${CHOWN} ${WWWOWN}:${WWWGRP} ${LOG_FILE}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
