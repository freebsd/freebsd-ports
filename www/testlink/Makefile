# $FreeBSD$

PORTNAME=	testlink
PORTVERSION=	1.9.5
PORTREVISION=	1
CATEGORIES=	www devel
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}/TestLink%201.9/TestLink%20${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Web based test management and test execution system

LICENSE=	GPLv2

USE_PHP=	gd iconv mbstring session xml
WANT_PHP_WEB=	yes
NO_BUILD=	yes
PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}
REINPLACE_ARGS=	-i ''

PORTDOCS=	*
PORTEXAMPLES=	*
DOCS=	CHANGELOG CODE_REUSE README
EXAMPLES=	db_sample file_examples samples.txt

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

.for e in ${EXAMPLES}
EXCLUDE_EXAMPLES+=	--exclude=${e}
.endfor

post-patch:
	@${REINPLACE_CMD} -e 's|/var/testlink|${WWWDIR}|' ${WRKSRC}/config.inc.php
	@${FIND} ${WRKSRC} -name "\.*" -delete
	@${FIND} ${WRKSRC} -name "*.orig" -delete
	@${RM} -rf ${WRKSRC}/.idea

do-install:
	@${MKDIR} ${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} cfg ${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} custom ${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} gui ${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} install ${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} lib ${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} locale ${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} logs ${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} third_party ${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} upload_area ${WWWDIR}
	@${INSTALL_DATA} ${WRKSRC}/*.php* ${WWWDIR}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for f in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
	@${TAR} ${EXCLUDE_EXAMPLES} -C ${WRKSRC}/docs -cf - . | ${TAR} --unlink -C ${DOCSDIR} -xf -
	@${LN} -s ${DOCSDIR} ${WWWDIR}/docs
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
.for f in ${EXAMPLES}
	@cd ${WRKSRC}/docs && ${COPYTREE_SHARE} ${f} ${EXAMPLESDIR}
.endfor
.endif
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

x-generate-plist:
	${FIND} ${WWWDIR} -type f | ${SORT} | ${SED} -e 's,${WWWDIR},%%WWWDIR%%,g' > pkg-plist.new
	${FIND} ${WWWDIR} -type d -depth | ${SORT} -r | ${SED} -e 's,${WWWDIR},@dirrm %%WWWDIR%%,g' >> pkg-plist.new
.for f in gui/templates_c logs upload_area
	${ECHO} '@exec mkdir -p %D/%%WWWDIR%%/${f}' >> pkg-plist.new
.endfor
	${ECHO} '@exec chown -R %%WWWOWN%%:%%WWWGRP%% %D/%%WWWDIR%%' >> pkg-plist.new

.include <bsd.port.mk>
