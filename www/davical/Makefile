# New ports collection makefile for:    davical
# Date created:                 Tue May 13 09:59:22 EST 2008
# Whom:                         Maurice Castro <maurice@castro.aus.net>
#
# $FreeBSD$
#

PORTNAME=	davical
PORTVERSION=	0.9.8.1
CATEGORIES?=	www
MASTER_SITES=	http://debian.mcmillan.net.nz/packages/davical/ \
		SF/rscds/${PORTNAME}/${PORTVERSION}
DISTNAME=	davical-${PORTVERSION}

MAINTAINER=	maurice@castro.aus.net
COMMENT=	A simple CalDAV server using a postgres backend

RUN_DEPENDS=	${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash \
		${LOCALBASE}/include/php/ext/pgsql:${PORTSDIR}/databases/php5-pgsql \
		${LOCALBASE}/lib/php/${PHP_EXT_DIR}/pdo.so:${PORTSDIR}/databases/php5-pdo \
		${LOCALBASE}/lib/php/${PHP_EXT_DIR}/pdo_pgsql.so:${PORTSDIR}/databases/php5-pdo_pgsql \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${SITE_PERL}/YAML.pm:${PORTSDIR}/textproc/p5-YAML \
		${SITE_PERL}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg \
		${LOCALBASE}/bin/pwgen:${PORTSDIR}/sysutils/pwgen \
		php-libawl>=0.40:${PORTSDIR}/devel/php-libawl \
		postgresql-client>=8.2:${PORTSDIR}/databases/postgresql${PGSQL_VER}-client

NO_BUILD=	yes
USE_PGSQL=	yes

USE_PHP=	gettext pcre xml iconv

SUB_FILES=	pkg-message httpd-davical.conf
WWWDIR?=	${PREFIX}/www/${PORTNAME}

post-patch:
	${RM} ${WRKSRC}/inc/always.php.orig
	${RM} ${WRKSRC}/dba/create-database.sh.orig

do-install:
	${MKDIR} ${WWWDIR} ${WWWDIR}/htdocs ${WWWDIR}/inc ${WWWDIR}/config
	cd ${WRKSRC}/htdocs && ${COPYTREE_SHARE} . ${WWWDIR}/htdocs
	cd ${WRKSRC}/inc && ${COPYTREE_SHARE} . ${WWWDIR}/inc
	${CP} -pv ${WRKSRC}/config/example-config.php ${WWWDIR}/config/

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR} ${DOCSDIR}/config ${DOCSDIR}/docs ${DOCSDIR}/scripts ${DOCSDIR}/dba
	cd ${WRKSRC}/config && ${COPYTREE_SHARE} . ${DOCSDIR}/config
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${DOCSDIR}/docs
	cd ${WRKSRC}/scripts && ${COPYTREE_SHARE} . ${DOCSDIR}/scripts
	cd ${WRKSRC}/dba && ${COPYTREE_SHARE} . ${DOCSDIR}/dba
	${CP} -pv ${WRKDIR}/httpd-davical.conf ${DOCSDIR}
	${CP} -pv ${WRKSRC}/README ${DOCSDIR}
	${CP} -pv ${WRKSRC}/INSTALL ${DOCSDIR}
	${CHMOD} a+x ${DOCSDIR}/dba/update-davical-database

.endif

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
