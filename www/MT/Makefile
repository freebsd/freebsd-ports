# New ports collection makefile for:	MT
# Date created:			Fri Jun 13 16:39:20 CST 2003
# Whom:				Foxfair Hu <foxfair@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MT
PORTVERSION=	2.64
CATEGORIES=	www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A web-based personal publishing system like weblogs

DISTNAME=	${PORTNAME}-${PORTVERSION}-full-lib
DOWNLOAD_URL?=	http://www.movabletype.org/download.shtml

DATADIR=	www/data/mt
CGIDIR=		www/cgi-bin/mt

.if defined(WITH_MYSQL)
DB_DIR=		/var/db/mysql/blog
RUN_DEPENDS=	${PREFIX}/libexec/mysqld:${PORTSDIR}/databases/mysql323-server
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

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}) && !defined(PACKAGE_BUILDING)
ECHO_MSG=/usr/bin/printf
IGNORE=	:\n\
Because of licensing restrictions, you must fetch the source distribution\n\
manually.  Please access ${DOWNLOAD_URL}, follow\n\
the registration instructions, select \"full version, with libraries\" and\n\
\"gzipped tar\", download the file into ${DISTDIR}/, and then\n\
run make again.\n
.endif

do-install:
	@cd ${WRKSRC} && ${FIND} * -name "*.orig" -delete
	@${ECHO} "Installing cgi ${PREFIX}/${CGIDIR}"
	@${MKDIR} ${PREFIX}/${CGIDIR}
	@cd ${WRKSRC} && ${CP} -R *.cgi lib extlib tmpl search_templates \
	  ${PREFIX}/${CGIDIR}
	@${SED} -e 's#WWW.YOUR-SITE.COM/PATH/TO/MT/#${HOST}/cgi-bin/mt/#g' \
	  -e 's/# StaticWebPath/StaticWebPath/g' \
	  -e 's#path/to/static-files#mt#g' \
	  -e 's/# NoHTMLEntities 1/NoHTMLEntities 1/g' \
	  ${WRKSRC}/mt.cfg > ${PREFIX}/${CGIDIR}/mt.cfg
	@${ECHO} "Installing data ${PREFIX}/${DATADIR}"
	@${MKDIR} ${PREFIX}/${DATADIR}
	@cd ${WRKSRC} && ${CP} -R LICENSE LICENSE-COMMERCIAL docs images \
	  index.html plugins schemas styles.css \
	  ${PREFIX}/${DATADIR}
.if defined(WITH_DEFAULTDB)
	@${MKDIR} -m 755 ${DB_DIR}
	@${CHOWN} -R www:www ${DB_DIR}
.endif
	@${CHOWN} -R www:www ${PREFIX}/${CGIDIR} ${PREFIX}/${DATADIR}

post-install:
	@${CAT} ${PKGMESSAGE}
	@${ECHO} "Please read the docs to initialize a blog DB in ${DB_DIR}"

.include <bsd.port.post.mk>
