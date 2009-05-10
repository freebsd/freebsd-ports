# New ports collection makefile for:	MT
# Date created:			Fri Jun 13 16:39:20 CST 2003
# Whom:				Foxfair Hu <foxfair@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MT
PORTVERSION=	4.25
CATEGORIES=	www
MASTER_SITES=	http://www.movabletype.org/downloads/stable/
DISTNAME=	MTOS-${PORTVERSION}-en

MAINTAINER=	arved@FreeBSD.org
COMMENT=	A web-based personal publishing system for weblogs

RUN_DEPENDS=	${SITE_PERL}/HTML/Template.pm:${PORTSDIR}/www/p5-HTML-Template \
		${SITE_PERL}/Image/Size.pm:${PORTSDIR}/graphics/p5-Image-Size \
		${SITE_PERL}/CGI.pm:${PORTSDIR}/www/p5-CGI.pm

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
.elif defined(WITH_POSTGRES)
DB_DIR?=		${PREFIX}/pgsql/data/blog
# Or somewhere defined in $PGDATA
USE_PGSQL=		yes
.else
DB_DIR?=	${PREFIX}/${CGIDIR}/db
RUN_DEPENDS+=\
	${SITE_PERL}/${PERL_ARCH}/DBD/SQLite.pm:${PORTSDIR}/databases/p5-DBD-SQLite
WITH_DEFAULTDB=	yes
.endif

PLIST_SUB+=	DATADIR=${DATADIR} CGIDIR=${CGIDIR}

USE_PERL5_RUN=	yes
NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_OPTIONAL_MODULES)
.if ${PERL_LEVEL} < 500800
RUN_DEPENDS+=	${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp
.endif
.endif

pre-everything::
	@${ECHO_CMD} "ATTENTION:"
	@${ECHO_CMD} "If you are upgrading from an older version of MT"
	@${ECHO_CMD} "please read http://www.movabletype.org/documentation/upgrade/"
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
.if !defined(WITH_POSTGRES)
	@${ECHO_CMD} "WITH_POSTGRES"
	@${ECHO_CMD} "		- Use PostgreSQL as database backend"
.endif

do-install:
	@cd ${WRKSRC} && ${FIND} * -name "*.orig" -delete
	@${ECHO_MSG} "Installing cgi under ${PREFIX}/${CGIDIR}/"
	@${MKDIR} ${PREFIX}/${CGIDIR}
	@cd ${WRKSRC} && ${CP} -R *.cgi mt-config.cgi-original \
	  extlib default_templates  extlib import lib php plugins search_templates \
	  tmpl tools ${PREFIX}/${CGIDIR}
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
	@${ECHO_CMD} ""
	@${ECHO_MSG} "Please read the documentation: http://www.movabletype.org/documentation/"

.include <bsd.port.post.mk>
