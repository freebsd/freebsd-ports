# Created by: Rob Evers <rob@debank.tv>
# $FreeBSD$

PORTNAME=	postfixadmin
PORTVERSION=	3.2
PORTREVISION=	2
CATEGORIES=	mail www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports.maintainer@evilphi.com
COMMENT=	PHP web-based management tool for Postfix virtual domains and users

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/GPL-LICENSE.TXT

RUN_DEPENDS+=	p5-DBI>=1.634:databases/p5-DBI \
		p5-Email-Sender>=1.300031:mail/p5-Email-Sender \
		p5-Email-Valid>=0.12:mail/p5-Email-Valid \
		p5-Log-Dispatch>=1.79:devel/p5-Log-Dispatch \
		p5-Log-Log4perl>=0.26:devel/p5-Log-Log4perl \
		p5-MIME-EncWords>=0.040:mail/p5-MIME-EncWords

USES=		cpe perl5 shebangfix php
CPE_VENDOR=	postfix_admin_project
CPE_PRODUCT=	postfix_admin

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES+=	pkg-message
PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

OPTIONS_DEFINE=	DOCS
OPTIONS_MULTI=	DB
OPTIONS_MULTI_DB=	MYSQL PGSQL SQLITE
OPTIONS_DEFAULT=	PGSQL

USE_PERL5=	run

USE_PHP=	mbstring openssl pcre phar session spl xmlrpc

MYSQL_USE=	php=mysqli
PGSQL_USE=	php=pgsql
SQLITE_USE=	php=sqlite3

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	@${MKDIR} ${STAGEDIR}${WWWDIR}/templates_c
	${INSTALL_DATA} ${WRKSRC}/*.php ${STAGEDIR}${WWWDIR}
.for i in configs languages lib model public scripts templates tests
	@cd ${WRKSRC}/${i} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/${i}
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/GPL-LICENSE.TXT ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE.TXT ${STAGEDIR}${DATADIR}
.for i in ADDITIONS VIRTUAL_VACATION
	@cd ${WRKSRC}/${i} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/${i}
.endfor

do-install-DOCS-on:
	@cd ${WRKSRC}/DOCUMENTS && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
.for i in CHANGELOG.TXT INSTALL.TXT README.md
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
