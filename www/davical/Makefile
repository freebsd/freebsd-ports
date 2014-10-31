# Created by: Maurice Castro <maurice@castro.aus.net>
# $FreeBSD$

PORTNAME=	davical
PORTVERSION=	1.1.2
PORTREVISION=	1
CATEGORIES?=	www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple CalDAV server using a postgres backend

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML \
		p5-DBD-Pg>=0:${PORTSDIR}/databases/p5-DBD-Pg \
		${LOCALBASE}/bin/pwgen:${PORTSDIR}/sysutils/pwgen \
		php-libawl>=0.54:${PORTSDIR}/devel/php-libawl

USE_GITHUB=	yes
GH_ACCOUNT=	DAViCal
GH_TAGNAME=	r${DISTVERSION}
GH_COMMIT=	cc8e6a0

NO_BUILD=	yes
USE_PHP=	gettext iconv pcre pdo pdo_pgsql pgsql xml calendar
USES=		shebangfix pgsql
SHEBANG_FILES=	scripts/sync-remote-caldav.php
SUB_FILES=	pkg-message httpd-davical.conf
PORTDOCS=	api website \
		README INSTALL davical_en_user_guide.odt translation.rst
PORTEXAMPLES=	config

OPTIONS_DEFINE=	DOCS EXAMPLES

post-extract:
	@${FIND} ${WRKSRC} -name .gitignore -delete

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}/htdocs \
		${STAGEDIR}${WWWDIR}/inc \
		${STAGEDIR}${WWWDIR}/config \
		${STAGEDIR}${EXAMPLESDIR} \
		${STAGEDIR}${DATADIR} \
		${STAGEDIR}${DOCSDIR}
	# WWWDIR
	(cd ${WRKSRC}/htdocs && \
		${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/htdocs)
	(cd ${WRKSRC}/inc && ${COPYTREE_SHARE} . \
		${STAGEDIR}${WWWDIR}/inc "! -name always.php.in")
	${INSTALL_DATA} ${WRKSRC}/config/example-config.php \
		${STAGEDIR}${WWWDIR}/config/config.php.sample
	# DATADIR
	(cd ${WRKSRC} && ${COPYTREE_SHARE} scripts ${STAGEDIR}${DATADIR})
	(cd ${WRKSRC} && ${COPYTREE_SHARE} dba ${STAGEDIR}${DATADIR} \
		"! -name update-davical-database")
	${INSTALL_DATA} ${WRKDIR}/httpd-davical.conf ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/dba/update-davical-database \
		${STAGEDIR}${DATADIR}/dba
	# DOCSDIR
	(cd ${WRKSRC}/docs && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${STAGEDIR}${DOCSDIR}
	# EXAMPLESDIR
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} config ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
