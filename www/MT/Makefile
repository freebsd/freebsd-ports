# New ports collection makefile for:	MT
# Date created:			Fri Jun 13 16:39:20 CST 2003
# Whom:				Foxfair Hu <foxfair@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MT
PORTVERSION=	2.661
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	http://www.movabletype.org/downloads/
.if defined(WITH_OLD_DISTFILE)
DISTNAME=	${PORTNAME}-${PORTVERSION}-full-lib
.endif
DISTFILES=	nofollow.tar.gz ${DISTNAME}.tar.gz

MAINTAINER=	arved@FreeBSD.org
COMMENT=	A web-based personal publishing system for weblogs

RUN_DEPENDS=	${SITE_PERL}/HTML/Template.pm:${PORTSDIR}/www/p5-HTML-Template \
		${SITE_PERL}/Image/Size.pm:${PORTSDIR}/graphics/p5-Image-Size \
		${SITE_PERL}/CGI.pm:${PORTSDIR}/www/p5-CGI.pm

.if !defined(WITHOUT_OPTIONAL_MODULES)
RUN_DEPENDS+=	${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/SOAP/Lite.pm:${PORTSDIR}/net/p5-SOAP-Lite \
	${SITE_PERL}/${PERL_ARCH}/Image/Magick.pm:${PORTSDIR}/graphics/ImageMagick
.endif

DATADIR=		www/data/mt
CGIDIR=			www/cgi-bin/mt

.if defined(WITH_MYSQL)
DB_DIR?=		/var/db/mysql/blog
USE_MYSQL=		yes
.elif defined(WITH_POSTGRES)
DB_DIR?=		${PREFIX}/pgsql/data/blog
# Or somewhere defined in $PGDATA
USE_PGSQL=		yes
.elif defined(WITH_SQLITE)
DB_DIR?=	${PREFIX}/${CGIDIR}/db
RUN_DEPENDS+=\
	${SITE_PERL}/${PERL_ARCH}/DBD/SQLite.pm:${PORTSDIR}/databases/p5-DBD-SQLite
.else
DB_DIR?=	${PREFIX}/${CGIDIR}/db
WITH_DEFAULTDB=	yes
.endif

PLIST_SUB+=	DATADIR=${DATADIR} CGIDIR=${CGIDIR}

USE_PERL5_RUN=	yes
NO_BUILD=	yes
RESTRICTED=	License does not permit distribution

.if defined(WITH_OLD_DISTFILE)
PLIST_SUB+=	OLD=""
.else
WRKSRC=		${WRKDIR}/MT-${PORTVERSION}-full-lib
PLIST_SUB+=	OLD="@comment "
.endif

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=	\
: Because of licensing restrictions, you must fetch the source distribution\
manually. Goto http://www.movabletype.org/ register as if you are going\
to download 3.x, and then choosing 2.661 from the list after you log on.\
Download the file into ${DISTDIR}/, and then run make again
ECHO_MSG=${ECHO_CMD}
.endif

.if !defined(WITHOUT_OPTIONAL_MODULES)
.if ${PERL_LEVEL} < 500800
RUN_DEPENDS+=	${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp
.endif
.endif
.if ${PERL_LEVEL} < 500601
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/File/Spec.pm:${PORTSDIR}/devel/p5-PathTools
.endif

pre-everything::
	@${ECHO_CMD} "Available switches:"
	@${ECHO_CMD} "-------------------"
	@${ECHO_CMD} "DB_DIR"
	@${ECHO_CMD} "		- Override the default database directory"
	@${ECHO_CMD} "		  (${DB_DIR})"
.if !defined(WITH_OLD_DISTFILE)
	@${ECHO_CMD} "WITH_OLD_DISTFILE"
	@${ECHO_CMD} "		- Use the pre 3.x distfile, which was available under"
	@${ECHO_CMD} "		  a less restrictive license"
.endif
.if !defined(WITHOUT_OPTIONAL_MODULES)
	@${ECHO_CMD} "WITHOUT_OPTIONAL_MODULES"
	@${ECHO_CMD} "		- Don't install optional perl modules, needed for"
	@${ECHO_CMD} "		  Trackbacks, XML-RPC and thumbnails"
.endif
.if !defined(WITH_MYSQL)
	@${ECHO_CMD} "WITH_MYSQL"
	@${ECHO_CMD} "		- Use MySQL instead of Berkeley DB as database backend"
.endif
.if !defined(WITH_MYSQL)
	@${ECHO_CMD} "WITH_POSTGRES"
	@${ECHO_CMD} "		- Use PostgreSQL instead of Berkeley DB as database backend"
.endif
.if !defined(WITH_SQLITE)
	@${ECHO_CMD} "WITH_POSTGRES"
	@${ECHO_CMD} "		- Use SQLite instead of Berkeley DB as database backend"
.endif

do-install:
	@cd ${WRKSRC} && ${FIND} * -name "*.orig" -delete
	@${ECHO_MSG} "Installing cgi under ${PREFIX}/${CGIDIR}"
	@${MKDIR} ${PREFIX}/${CGIDIR}
	@cd ${WRKSRC} && ${CP} -R *.cgi lib extlib plugins search_templates \
	  tmpl ${PREFIX}/${CGIDIR}
	@${SED} -e 's#WWW.YOUR-SITE.COM/PATH/TO/MT/#${HOST}/cgi-bin/mt/#g' \
	  -e 's/# StaticWebPath/StaticWebPath/g' \
	  -e 's#path/to/static-files#mt#g' \
	  -e 's/# NoHTMLEntities 1/NoHTMLEntities 1/g' \
	  ${WRKSRC}/mt.cfg > ${PREFIX}/${CGIDIR}/mt.cfg.dist
	[ -e ${PREFIX}/${CGIDIR}/mt.cfg ] || ${CP} ${PREFIX}/${CGIDIR}/mt.cfg.dist ${PREFIX}/${CGIDIR}/mt.cfg
	${SED} -e 's#$$MT_DIR, .schemas.#"${PREFIX}/${DATADIR}/schemas"#' \
	  ${WRKSRC}/mt-load.cgi > ${PREFIX}/${CGIDIR}/mt-load.cgi
	@${ECHO_MSG} "Installing data under ${PREFIX}/${DATADIR}"
	@${MKDIR} ${PREFIX}/${DATADIR}
	@cd ${WRKSRC} && ${CP} -R docs images \
	  index.html schemas styles.css \
	  ${PREFIX}/${DATADIR}
.if defined(WITH_OLD_DISTFILE)
	@cd ${WRKSRC}; ${INSTALL_DATA} LICENSE LICENSE-COMMERCIAL \
		${PREFIX}/${DATADIR}
.endif
	${MKDIR} ${PREFIX}/${CGIDIR}/plugins
	${INSTALL_DATA} ${WRKDIR}/nofollow/plugins/nofollow.pl ${PREFIX}/${CGIDIR}/plugins
.if defined(WITH_DEFAULTDB)
	@${MKDIR} -m 755 ${DB_DIR}
	@${CHOWN} -R www:www ${DB_DIR}
.endif
	@${CHOWN} -R www:www ${PREFIX}/${CGIDIR} ${PREFIX}/${DATADIR}

post-install:
	@${ECHO_MSG} "Please read the documentation about initializing a blog DB in ${DB_DIR}"

.include <bsd.port.post.mk>
