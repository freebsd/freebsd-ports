# New ports collection makefile for:	MT
# Date created:			Fri Jun 13 16:39:20 CST 2003
# Whom:				Foxfair Hu <foxfair@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MT
PORTVERSION=	2.661
PORTREVISION=	1
CATEGORIES=	www
.if defined(WITH_OLD_DISTFILE)
DISTNAME=	${PORTNAME}-${PORTVERSION}-full-lib
.endif

MAINTAINER=	arved@FreeBSD.org
COMMENT=	A web-based personal publishing system like weblogs

DATADIR=	www/data/mt
CGIDIR=		www/cgi-bin/mt

.if defined(WITH_MYSQL)
DB_DIR=		/var/db/mysql/blog
USE_MYSQL=	yes
.elif defined(WITH_POSTGRES)
DB_DIR=		${PREFIX}/pgsql/data/blog	# Or somewhere defined in $PGDATA
RUN_DEPENDS=	postgres:${PORTSDIR}/databases/postgresql7
.else
DB_DIR=		${PREFIX}/${CGIDIR}/db
WITH_DEFAULTDB=	yes
.endif

PLIST_SUB+=	DATADIR=${DATADIR} CGIDIR=${CGIDIR}

USE_PERL5_RUN=	yes
NO_BUILD=	yes
RESTRICTED=	"License does not permit distribution"

.if defined(WITH_OLD_DISTFILE)
PLIST_SUB+=	OLD=""
.else
WRKSRC=		${WRKDIR}/MT-${PORTVERSION}-full-lib
PLIST_SUB+=	OLD="@comment "
.endif

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
ECHO_MSG=/usr/bin/printf
IGNORE=	:\n\
Because of licensing restrictions, you must fetch the source distribution\n\
manually.  Goto http://www.movabletype.org/ register as if you are going\n\
to download 3.x, and then choosing 2.661 from the list after you log on.\n\
Download the file into ${DISTDIR}/, and then run make again.\n
.endif

do-install:
	@cd ${WRKSRC} && ${FIND} * -name "*.orig" -delete
	@${ECHO_MSG} "Installing cgi ${PREFIX}/${CGIDIR}"
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
	@${ECHO_MSG} "Installing data ${PREFIX}/${DATADIR}"
	@${MKDIR} ${PREFIX}/${DATADIR}
	@cd ${WRKSRC} && ${CP} -R docs images \
	  index.html schemas styles.css \
	  ${PREFIX}/${DATADIR}
.if defined(WITH_OLD_DISTFILE)
	@cd ${WRKSRC}; ${INSTALL_DATA} LICENSE LICENSE-COMMERCIAL \
		${PREFIX}/${DATADIR}
.endif
.if defined(WITH_DEFAULTDB)
	@${MKDIR} -m 755 ${DB_DIR}
	@${CHOWN} -R www:www ${DB_DIR}
.endif
	@${CHOWN} -R www:www ${PREFIX}/${CGIDIR} ${PREFIX}/${DATADIR}

post-install:
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG} "Please read the docs to initialize a blog DB in ${DB_DIR}"

.include <bsd.port.post.mk>
