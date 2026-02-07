PORTNAME=	davical
DISTVERSIONPREFIX=	r
DISTVERSION=	1.1.12
PORTREVISION=	1
CATEGORIES?=	www
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Simple CalDAV server using a postgres backend
WWW=		https://www.davical.org/

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PHP_PKGNAMEPREFIX}libawl>=0.60:devel/php-libawl@${PHP_FLAVOR} \
		p5-DBD-Pg>=0:databases/p5-DBD-Pg \
		p5-DBI>=0:databases/p5-DBI \
		p5-YAML>=0:textproc/p5-YAML \
		pwgen:sysutils/pwgen

USES=		cpe pgsql php:flavors shebangfix

USE_GITLAB=	yes
GL_ACCOUNT=	davical-project
GL_TAGNAME=	4301a795ac7a7636846bcc15348d96c68a1830fd

USE_PHP=	calendar curl gettext iconv pdo \
		pdo_pgsql pgsql session xml

NO_ARCH=	yes
NO_BUILD=	yes

PORTDOCS=	README INSTALL davical_en_user_guide.odt \
		phpdoc.ini translation.rst
PORTEXAMPLES=	config

SHEBANG_FILES=	scripts/sync-remote-caldav.php
SUB_FILES=	pkg-message httpd-davical.conf

OPTIONS_DEFINE=	DOCS EXAMPLES

post-extract:
	${FIND} ${WRKSRC} -name .gitignore -delete

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}/htdocs \
		${STAGEDIR}${WWWDIR}/inc \
		${STAGEDIR}${WWWDIR}/config \
		${STAGEDIR}${DATADIR}
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

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} config ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
