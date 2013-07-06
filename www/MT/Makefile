# Created by: Foxfair Hu <foxfair@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MT
PORTVERSION=	5.2.7
PORTEPOCH=	1
CATEGORIES?=	www
MASTER_SITES?=	http://www.movabletype.org/downloads/stable/\
		http://www.movabletype.org/downloads/archives/5.x/
DISTNAME?=	MTOS-${PORTVERSION}

MAINTAINER?=	takefu@airport.fm
COMMENT?=	Web-based personal publishing system for weblogs

CONFLICTS?=	de-MT-[2-5].* fr-MT-[2-5].* ja-MT-[2-5].* ru-MT-[2-5].*

RUN_DEPENDS+=	p5-DBI>=1.21:${PORTSDIR}/databases/p5-DBI \
		p5-Image-Size>=0:${PORTSDIR}/graphics/p5-Image-Size

NO_OPTIONS_SORT=	yes
OPTIONS_DEFINE=		APACHE MYSQL SSL TLS\
			OPTIONAL_MODULES ADDITIONAL_MODULES\
			PGSQL ORACLE ODBC SQLITE2 SQLITE PSGI
OPTIONS_DEFAULT=	MYSQL OPTIONAL_MODULES
OPTIONAL_MODULES_DESC=	Optional Perl Modules
ADDITIONAL_MODULES_DESC=Additional Perl modules
PSGI_DESC=		Perl Web Server Gateway Interface

PGSQL_DESC=		PostgreSQL database support[obsolete]
SQLITE_DESC=		SQLite3 database support[obsolete]
SQLITE2_DESC=		SQLite2 database support[obsolete]

.include <bsd.port.options.mk>

DATADIR=	www/data
CGIDIR=		www/cgi-bin/mt
PLIST_SUB+=	DATADIR=${DATADIR}\
		CGIDIR=${CGIDIR}\
		DB_DIR=${DB_DIR}
SUB_FILES+=	pkg-install
SUB_LIST+=	DATADIR=${DATADIR}\
		CGIDIR=${CGIDIR}\
		PACKAGENAME=${PKGNAMEPREFIX}${PORTNAME}\
		DB_DIR=${DB_DIR}\
		WWWOWN=${WWWOWN}\
		WWWGRP=${WWWGRP}

USE_PERL5_RUN=	yes
NO_BUILD=	yes
MT_DOCS_URL?=	http://www.movabletype.org/documentation/
MT_UPGRADE_URL?=http://www.movabletype.org/documentation/installation/upgrade-movable-type.html

MT_LANG?=	EN
.if ${MT_LANG} == RU
PLIST_SUB+=	LANG_RU=""
.else
PLIST_SUB+=	LANG_RU="@comment "
.endif

.if ${PORT_OPTIONS:MOPTIONAL_MODULES}
RUN_DEPENDS+=	p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser\
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww\
		p5-SOAP-Lite>=0.5:${PORTSDIR}/net/p5-SOAP-Lite\
		convert:${PORTSDIR}/graphics/ImageMagick\
		p5-GD>=0:${PORTSDIR}/graphics/p5-GD \
		p5-Imager>=0:${PORTSDIR}/graphics/p5-Imager \
		p5-Crypt-DSA>=0:${PORTSDIR}/security/p5-Crypt-DSA\
		p5-MIME-Base64>=0:${PORTSDIR}/converters/p5-MIME-Base64\
		p5-XML-Atom>=0:${PORTSDIR}/textproc/p5-XML-Atom\
		p5-Archive-Zip>=0:${PORTSDIR}/archivers/p5-Archive-Zip\
		p5-Text-Balanced>=0:${PORTSDIR}/textproc/p5-Text-Balanced\
		p5-XML-LibXML>=1.7:${PORTSDIR}/textproc/p5-XML-LibXML
.endif
.if ${PORT_OPTIONS:MADDITIONAL_MODULES}
RUN_DEPENDS+=	p5-Digest-MD5>=0:${PORTSDIR}/security/p5-Digest-MD5\
		p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1\
		p5-IPC-Run>=0:${PORTSDIR}/devel/p5-IPC-Run\
		p5-Mail-Sendmail>=0:${PORTSDIR}/mail/p5-Mail-Sendmail\
		p5-perl-ldap>=0:${PORTSDIR}/net/p5-perl-ldap\
		p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser\
		p5-XML-SAX>=0:${PORTSDIR}/textproc/p5-XML-SAX\
		p5-Cache-Memcached>=0:${PORTSDIR}/databases/p5-Cache-Memcached\
		p5-Cache>=0:${PORTSDIR}/devel/p5-Cache
.endif
.if ${PORT_OPTIONS:MSSL} || ${PORT_OPTIONS:MTLS}
RUN_DEPENDS+=	p5-Net-SMTP-SSL>=0:${PORTSDIR}/mail/p5-Net-SMTP-SSL
. if ${PORT_OPTIONS:MSSL}
RUN_DEPENDS+=	p5-Crypt-SSLeay>=0:${PORTSDIR}/security/p5-Crypt-SSLeay\
		p5-IO-Socket-SSL>=0:${PORTSDIR}/security/p5-IO-Socket-SSL\
		p5-Net-SSLeay>=0:${PORTSDIR}/security/p5-Net-SSLeay
. endif
. if ${PORT_OPTIONS:MTLS}
RUN_DEPENDS+=	p5-Net-SMTP-TLS>=0:${PORTSDIR}/mail/p5-Net-SMTP-TLS
. endif
.endif
.if ${PORT_OPTIONS:MMYSQL} && empty(PORT_OPTIONS:MPGSQL)
USE_MYSQL=	server
DB_DIR?=	${BASEDIR}/var/db/mysql/WEBLOG_DATABASEDIR
RUN_DEPENDS+=	p5-DBD-mysql>=2.9005:${PORTSDIR}/databases/p5-DBD-mysql
.endif
.if ${PORT_OPTIONS:MPGSQL} && empty(PORT_OPTIONS:MMYSQL)
USE_PGSQL=	server
RUN_DEPENDS+=	p5-DBD-Pg>=1.32:${PORTSDIR}/databases/p5-DBD-Pg
.endif
.if empty${PORT_OPTIONS:MPGSQL} && empty(PORT_OPTIONS:MMYSQL)
DB_DIR?=	${PREFIX}/${CGIDIR}/db
. if ${PORT_OPTIONS:MSQLITE} && empty(PORT_OPTIONS:MSQLITE2)
USE_SQLITE=	yes
RUN_DEPENDS+=	p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite
. elif ${PORT_OPTIONS:MSQLITE2} && empty(PORT_OPTIONS:MSQLITE)
USE_SQLITE=	2
RUN_DEPENDS+=	p5-DBD-SQLite2>=0:${PORTSDIR}/databases/p5-DBD-SQLite2
. endif
WITH_DEFAULTDB=	yes
.endif
.if ${PORT_OPTIONS:MORACLE}
RUN_DEPENDS+=	p5-DBD-Oracle>=0.19:${PORTSDIR}/databases/p5-DBD-Oracle
.endif
.if ${PORT_OPTIONS:MODBC}
RUN_DEPENDS+=	p5-DBD-ODBC>=1.13:${PORTSDIR}/databases/p5-DBD-ODBC
.endif
.if ${PORT_OPTIONS:MAPACHE}
USE_APACHE_RUN=	22+
SUB_FILES+=	MT.conf
SUB_LIST+=	APACHEETCDIR=${PREFIX}/${APACHEETCDIR}
PLIST_SUB+=	APACHE=""
.else
PLIST_SUB+=	APACHE="@comment "
.endif
.if ${PORT_OPTIONS:MPSGI}
RUN_DEPENDS+=	p5-CGI-PSGI>0:${PORTSDIR}/www/p5-CGI-PSGI\
		p5-CGI-Emulate-PSGI>=0.06:${PORTSDIR}/www/p5-CGI-Emulate-PSGI\
		p5-Plack>=0:${PORTSDIR}/www/p5-Plack\
		p5-SOAP-Transport-HTTP-Plack>=0:${PORTSDIR}/www/p5-SOAP-Transport-HTTP-Plack
.endif

.include <bsd.port.pre.mk>

pre-everything::
	@${ECHO_CMD} "ATTENTION:"
	@${ECHO_CMD} "If you are upgrading from an older version of MT"
	@${ECHO_CMD} "please read ${MT_UPGRADE_URL}"
	@${ECHO_CMD} "BEFORE installing this port"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "Available switches:"
	@${ECHO_CMD} "-------------------"
.if !${PORT_OPTIONS:MPGSQL}
	@${ECHO_CMD} "DB_DIR"
	@${ECHO_CMD} "		- Override the default database directory"
	@${ECHO_CMD} "		  (${DB_DIR})"
.endif
.if ${PORT_OPTIONS:MMYSQL}
	@${ECHO_CMD} "OPTIONS_FILE_SET=MYSQL"
	@${ECHO_CMD} "		- Use MySQL as database backend"
.endif

do-install:
	@cd ${WRKSRC} && ${FIND} * -name "*.orig" -delete
	@${ECHO_MSG} "Installing cgi under ${PREFIX}/${CGIDIR}/"
	@${MKDIR} ${PREFIX}/${CGIDIR}
	@cd ${WRKSRC} && ${CP} -R *.cgi mt.psgi mt-config.cgi-original \
	  alt-tmpl default_templates extlib import lib php plugins \
	  search_templates themes tmpl tools COPYING index.html readme.html \
	  ${PREFIX}/${CGIDIR}
	@${ECHO_MSG} "Installing data under ${PREFIX}/${DATADIR}/"
	@${MKDIR} ${PREFIX}/${DATADIR}
	@cd ${WRKSRC} && ${CP} -R mt-static ${PREFIX}/${DATADIR}

post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL ${WITH_DEFAULTDB}
	@${ECHO_MSG} "*****************************************************************"
	@${ECHO_CMD} ""
	@${ECHO_MSG} "You have just installed the movabletype."
	@${ECHO_CMD} ""
.if ${PORT_OPTIONS:MAPACHE}
	@${ECHO_MSG} "Note that you should restart your Apache web server to ensure that"
	@${ECHO_MSG} "the "${PKGNAMEPREFIX}"MT configuration file is loaded."
	@${ECHO_CMD} ""
	@${ECHO_MSG} "Then browse to http://localhost/MTcgi/mt.cgi"
	@${ECHO_CMD} ""
	@${ECHO_MSG} "Please add the following to your apache config, and restart."
	@${ECHO_CMD} ""
	@${CAT} ${WRKDIR}/MT.conf
	@${ECHO_CMD} ""
	@${MKDIR} ${PREFIX}/${APACHEETCDIR}/Includes
	@${INSTALL_DATA} ${WRKDIR}/MT.conf \
	  ${PREFIX}/${APACHEETCDIR}/Includes/MT.conf
.else
	@${ECHO_CMD} ""
.endif
	@${ECHO_MSG} "Please read the documentation: ${MT_DOCS_URL}"
	@${ECHO_CMD} ""

.include <bsd.port.post.mk>
