# New ports collection makefile for:	testlink
# Date created:		2010-12-26
# Whom:			TAKATSU Tomonari <tota@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	testlink
PORTVERSION=	1.9.0
CATEGORIES=	www devel
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}/TestLink%201.9/TestLink%20${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	A web based test management and test execution system

USE_ZIP=	yes
USE_PHP=	gd iconv mbstring
WANT_PHP_WEB=	yes
USE_DOS2UNIX=	yes
NO_BUILD=	yes
PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS=	MYSQL	"MySQL back-end (use mysql PHP extension)" on \
		PGSQL	"PostgreSQL back-end (use pgsql PHP extension)" off \
		OPENLDAP	"Enable OpenLDAP support" off \
		EXTJS	"Enable Ext JS support" on

.include <bsd.port.pre.mk>

.if defined(WITHOUT_MYSQL) && !defined(WITH_PGSQL)
IGNORE=	needs at least one database back-end
.endif

.if defined(WITH_MYSQL)
USE_PHP+=	mysql
.endif

.if defined(WITH_PGSQL)
USE_PHP+=	pgsql
.endif

.if defined(WITH_OPENLDAP)
USE_PHP+=	ldap
.endif

.if defined(WITH_EXTJS)
USE_PHP+=	json
.endif

post-patch:
.for f in CHANGELOG CODE_REUSE README TL-1.9-Prague-NEWS.txt
	@${MV} ${WRKSRC}/${f} ${WRKSRC}/docs
.endfor
	@${MV} ${WRKSRC}/docs/db_sample ${WRKDIR}
	@${MV} ${WRKSRC}/docs/file_examples ${WRKDIR}
	@${MV} ${WRKSRC}/docs ${WRKDIR}
	@${FIND} ${WRKSRC} -name "\.*" -delete

do-install:
	@${MKDIR} ${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${WWWDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKDIR}/docs && ${COPYTREE_SHARE} . ${DOCSDIR}
	@${LN} -s ${DOCSDIR} ${WWWDIR}/docs
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKDIR} && ${COPYTREE_SHARE} db_sample ${EXAMPLESDIR}
	@cd ${WRKDIR} && ${COPYTREE_SHARE} file_examples ${EXAMPLESDIR}
.endif

post-install:
	@${RM} ${WWWDIR}/LICENSE
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

x-generate-plist:
	${FIND} ${WWWDIR} -type f | ${SORT} | ${SED} -e 's,${WWWDIR},%%WWWDIR%%,g' >> pkg-plist.new
	${FIND} ${WWWDIR} -type d -depth | ${SORT} -r | ${SED} -e 's,${WWWDIR},@dirrm %%WWWDIR%%,g' >> pkg-plist.new
.for f in gui/templates_c logs upload_area
	${ECHO} '@exec mkdir -p %D/%%WWWDIR%%/${f}' >> pkg-plist.new
.endfor
	${ECHO} '@exec chown -R %%WWWOWN%%:%%WWWGRP%% %D/%%WWWDIR%%' >> pkg-plist.new

.include <bsd.port.post.mk>
