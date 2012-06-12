# New ports collection makefile for:	testlink
# Date created:		2010-12-26
# Whom:			TAKATSU Tomonari <tota@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	testlink
PORTVERSION=	1.9.3
CATEGORIES=	www devel
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}/TestLink%201.9/TestLink%20${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	A web based test management and test execution system

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_PHP=	gd iconv mbstring session
WANT_PHP_WEB=	yes
NO_BUILD=	yes
PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=		OPENLDAP EXTJS
OPTIONS_MULTI=		BACKEND
OPTIONS_MULTI_BACKEND=	MYSQL PGSQL
MYSQL_DESC=		back-end (use mysql PHP extension)
PGSQL_DESC=		back-end (use pgsql PHP extension)
OPENLDAP_DESC=		Enable OpenLDAP support
EXTJS_DESC=		Enable Ext JS support

OPTIONS_DEFAULT=	MYSQL EXTJS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_PHP+=	mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PHP+=	pgsql
.endif

.if ${PORT_OPTIONS:MOPENLDAP}
USE_PHP+=	ldap
.endif

.if ${PORT_OPTIONS:MEXTJS}
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
	${FIND} ${WWWDIR} -type f | ${SORT} | ${SED} -e 's,${WWWDIR},%%WWWDIR%%,g' > pkg-plist.new
	${FIND} ${WWWDIR} -type d -depth | ${SORT} -r | ${SED} -e 's,${WWWDIR},@dirrm %%WWWDIR%%,g' >> pkg-plist.new
.for f in gui/templates_c logs upload_area
	${ECHO} '@exec mkdir -p %D/%%WWWDIR%%/${f}' >> pkg-plist.new
.endfor
	${ECHO} '@exec chown -R %%WWWOWN%%:%%WWWGRP%% %D/%%WWWDIR%%' >> pkg-plist.new

.include <bsd.port.mk>
