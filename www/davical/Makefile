# New ports collection makefile for:    davical
# Date created:                 Tue May 13 09:59:22 EST 2008
# Whom:                         Maurice Castro <maurice@castro.aus.net>
#
# $FreeBSD$
#

PORTNAME=	davical
PORTVERSION=	1.1.1
CATEGORIES?=	www
MASTER_SITES=	http://debian.mcmillan.net.nz/packages/davical/ \
		SF/rscds/${PORTNAME}/${PORTVERSION}
DISTNAME=	davical-${PORTVERSION}

MAINTAINER=	maurice@castro.aus.net
COMMENT=	A simple CalDAV server using a postgres backend

RUN_DEPENDS=	p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML \
		p5-DBD-Pg>=0:${PORTSDIR}/databases/p5-DBD-Pg \
		${LOCALBASE}/bin/pwgen:${PORTSDIR}/sysutils/pwgen \
		php-libawl>=0.53:${PORTSDIR}/devel/php-libawl

NO_BUILD=	yes
USE_PGSQL=	yes
USE_PHP=	gettext iconv pcre pdo pdo_pgsql pgsql xml calendar

SUB_FILES=	pkg-message httpd-davical.conf

do-install:
.for dirs in htdocs inc config
	${MKDIR} ${WWWDIR}/${dirs}
.endfor
	cd ${WRKSRC}/htdocs && ${COPYTREE_SHARE} . ${WWWDIR}/htdocs
	cd ${WRKSRC}/inc && ${COPYTREE_SHARE} . ${WWWDIR}/inc "! -name *.in"
	${CP} -pv ${WRKSRC}/config/example-config.php ${WWWDIR}/config/

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
.for docdirs in config docs scripts dba
	${MKDIR} ${DOCSDIR}/${docdirs}
	cd ${WRKSRC}/${docdirs} && ${COPYTREE_SHARE} . ${DOCSDIR}/${docdirs}
.endfor
	${INSTALL_DATA} ${WRKDIR}/httpd-davical.conf ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DOCSDIR}
	${CHMOD} a+x ${DOCSDIR}/dba/update-davical-database

.endif

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
