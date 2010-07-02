# New ports collection makefile for:	MT
# Date created:			Fri Jun 13 16:39:20 CST 2003
# Whom:				Foxfair Hu <foxfair@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MT
PORTVERSION?=	5.02
CATEGORIES?=	www
MASTER_SITES?=	http://www.movabletype.org/downloads/stable/
DISTNAME?=	MTOS-${PORTVERSION}-en

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	A web-based personal publishing system for weblogs

CONFLICTS?=	ja-MT-[2-5].* fr-MT-[2-5].* de-MT-[2-5].* es-MT-[2-5].* \
		nl-MT-[2-5].* ru-MT-[2-5].*

RUN_DEPENDS=	${SITE_PERL}/HTML/Template.pm:${PORTSDIR}/www/p5-HTML-Template \
		${SITE_PERL}/Image/Size.pm:${PORTSDIR}/graphics/p5-Image-Size \
		${SITE_PERL}/CGI.pm:${PORTSDIR}/www/p5-CGI.pm

OPTIONS=	APACHE			"USE_APACHE"		off\
		MYSQL			"USE_MYSQL"		off\
		OPTIONAL_MODULES	"OPTIONAL_MODULES"	on

.include <bsd.port.options.mk>

.if !defined(WITHOUT_OPTIONAL_MODULES)
RUN_DEPENDS+=	${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
	${SITE_PERL}/SOAP/Lite.pm:${PORTSDIR}/net/p5-SOAP-Lite \
	${SITE_PERL}/${PERL_ARCH}/Image/Magick.pm:${PORTSDIR}/graphics/ImageMagick \
	${SITE_PERL}/Crypt/DSA.pm:${PORTSDIR}/security/p5-Crypt-DSA \
	${SITE_PERL}/Mail/Sendmail.pm:${PORTSDIR}/mail/p5-Mail-Sendmail \
	${SITE_PERL}/Archive/Zip.pm:${PORTSDIR}/archivers/p5-Archive-Zip \
	${SITE_PERL}/Archive/Tar.pm:${PORTSDIR}/archivers/p5-Archive-Tar \
	${SITE_PERL}/${PERL_ARCH}/GD.pm:${PORTSDIR}/graphics/p5-GD
.endif

DATADIR=	www/data
CGIDIR=		www/cgi-bin/mt

.if defined(WITH_MYSQL)
DB_DIR?=		/var/db/mysql/blog
USE_MYSQL=		yes
.else
DB_DIR?=	${PREFIX}/${CGIDIR}/db
RUN_DEPENDS+=\
	${SITE_PERL}/${PERL_ARCH}/DBD/SQLite.pm:${PORTSDIR}/databases/p5-DBD-SQLite
WITH_DEFAULTDB=	yes
.endif

PLIST_SUB+=	DATADIR=${DATADIR} CGIDIR=${CGIDIR}

USE_PERL5_RUN=	yes
NO_BUILD=	yes

.if defined(WITH_APACHE)
USE_APACHE=	2.0+
SUB_FILES+=	MT.conf
SUB_LIST+=	DATADIR=${PREFIX}/${DATADIR} CGIDIR=${PREFIX}/${CGIDIR} \
		APACHEETCDIR=${PREFIX}/${APACHEETCDIR} \
		PACKAGENAME=${PKGNAMEPREFIX}${PORTNAME}
PLIST_FILES+=	${APACHEETCDIR}/Includes/MT.conf
.endif

MT_LANGUAGES=	en ja ru
MT_LANG?=	en

.for _L in ${MT_LANGUAGES}
.if ${MT_LANG} == ${_L}
PLIST_SUB+=	LANG_${_L:U}=""
.else
PLIST_SUB+=	LANG_${_L:U}="@comment "
.endif
.endfor

MT_DOCS_URL?=	http://movabletype.org/documentation/
MT_UPGRADE_URL?=http://movabletype.org/documentation/upgrade/

.include <bsd.port.pre.mk>

.if defined(WITH_APACHE)
PLIST_FILES+=	"@dirrmtry ${APACHEETCDIR}/Includes"
PLIST_FILES+=	"@dirrmtry ${APACHEETCDIR}"
.endif

.if !defined(WITHOUT_OPTIONAL_MODULES)
.if ${PERL_LEVEL} < 500800
RUN_DEPENDS+=	${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp
.endif
.endif

pre-everything::
	@${ECHO_CMD} "ATTENTION:"
	@${ECHO_CMD} "If you are upgrading from an older version of MT"
	@${ECHO_CMD} "please read ${MT_UPGRADE_URL}"
	@${ECHO_CMD} "BEFORE installing this port"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "Available switches:"
	@${ECHO_CMD} "-------------------"
	@${ECHO_CMD} "DB_DIR"
	@${ECHO_CMD} "		- Override the default database directory"
	@${ECHO_CMD} "		  (${DB_DIR})"
.if !defined(WITHOUT_OPTIONAL_MODULES)
	@${ECHO_CMD} "WITHOUT_OPTIONAL_MODULES"
	@${ECHO_CMD} "		- Don't install optional perl modules, needed for"
	@${ECHO_CMD} "		  Trackbacks, XML-RPC and thumbnails"
.endif
.if !defined(WITH_MYSQL)
	@${ECHO_CMD} "WITH_MYSQL"
	@${ECHO_CMD} "		- Use MySQL as database backend"
.endif

do-install:
	@cd ${WRKSRC} && ${FIND} * -name "*.orig" -delete
	@${ECHO_MSG} "Installing cgi under ${PREFIX}/${CGIDIR}/"
	@${MKDIR} ${PREFIX}/${CGIDIR}
	@cd ${WRKSRC} && ${CP} -R *.cgi mt-config.cgi-original \
	  alt-tmpl default_templates extlib import lib php plugins search_templates \
	  themes tmpl tools ${PREFIX}/${CGIDIR}
	@${ECHO_MSG} "Installing data under ${PREFIX}/${DATADIR}/"
	@${MKDIR} ${PREFIX}/${DATADIR}
	@cd ${WRKSRC} && ${CP} -R mt-static \
	  ${PREFIX}/${DATADIR}
.if defined(WITH_DEFAULTDB)
	@${MKDIR} -m 755 ${DB_DIR}
	@${CHOWN} -R www:www ${DB_DIR}
.endif
	@${CHOWN} -R www:www ${PREFIX}/${CGIDIR} ${PREFIX}/${DATADIR}

post-install:
	@${ECHO_MSG} "*****************************************************************"
.if defined(WITH_APACHE)
	@${ECHO_MSG} "Please add the following to your apache config, and restart."
	@${ECHO_CMD} ""
	@${CAT} ${WRKDIR}/MT.conf
	@${ECHO_CMD} ""
	@${MKDIR} ${PREFIX}/${APACHEETCDIR}/Includes
	@${INSTALL_DATA} ${WRKDIR}/MT.conf ${PREFIX}/${APACHEETCDIR}/Includes/MT.conf
.else
	@${ECHO_CMD} ""
.endif
	@${ECHO_MSG} "Please read the documentation: ${MT_DOCS_URL}"

.include <bsd.port.post.mk>
