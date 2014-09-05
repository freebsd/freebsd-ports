# Created by: Maurice Castro <maurice@castro.aus.net>
# $FreeBSD$

PORTNAME=	davical
PORTVERSION=	1.1.2
CATEGORIES?=	www

MAINTAINER=	maurice@castro.aus.net
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

OPTIONS_DEFINE=	DOCS

post-extract:
	@${FIND} ${WRKSRC} -name .gitignore -delete

do-install:
.for dirs in htdocs inc config
	${MKDIR} ${STAGEDIR}${WWWDIR}/${dirs}
.endfor
	cd ${WRKSRC}/htdocs && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/htdocs
	cd ${WRKSRC}/inc && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/inc "! -name always.php.in"
	${CP} -p ${WRKSRC}/config/example-config.php ${STAGEDIR}${WWWDIR}/config/config.php.sample

post-install:
.for docdirs in config docs scripts dba
	${MKDIR} ${STAGEDIR}${DOCSDIR}/${docdirs}
	cd ${WRKSRC}/${docdirs} && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/${docdirs}
.endfor
	${INSTALL_DATA} ${WRKDIR}/httpd-davical.conf ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${STAGEDIR}${DOCSDIR}
	${CHMOD} a+x ${STAGEDIR}${DOCSDIR}/dba/update-davical-database

.include <bsd.port.mk>
