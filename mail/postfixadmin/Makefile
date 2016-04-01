# Created by: Rob Evers <rob@debank.tv>
# $FreeBSD$

PORTNAME=	postfixadmin
PORTVERSION=	2.93
CATEGORIES=	mail www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports.maintainer@evilphi.com
COMMENT=	PHP web-based management tool for Postfix virtual domains and users

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/GPL-LICENSE.TXT

RUN_DEPENDS+=	p5-DBI>=1.634:databases/p5-DBI \
		p5-Email-Valid>=0.12:mail/p5-Email-Valid \
		p5-Log-Dispatch>=1.79:devel/p5-Log-Dispatch \
		p5-Log-Log4perl>=0.26:devel/p5-Log-Log4perl \
		p5-Mail-Sender>=0.7.04:mail/p5-Mail-Sender \
		p5-MIME-EncWords>=0.040:mail/p5-MIME-EncWords

USES=		cpe perl5 shebangfix
CPE_VENDOR=	postfix_admin_project
CPE_PRODUCT=	postfix_admin

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES+=	pkg-message
PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

OPTIONS_DEFINE=	DOCS
OPTIONS_SINGLE=	DB
OPTIONS_SINGLE_DB=	MYSQL MYSQLI PGSQL
MYSQLI_DESC=	MySQL 4.1+ back-end (use mysqli PHP extension)

OPTIONS_DEFAULT=	PGSQL

USE_PERL5=	run

USE_PHP=	pcre session mbstring spl xmlrpc

MYSQL_USE=	php=mysql
MYSQLI_USE=	php=mysqli
PGSQL_USE=	php=pgsql

WANT_PHP_WEB=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
.for i in *.php calendar.js
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${WWWDIR}
.endfor
.for i in configs css images languages model scripts smarty templates templates_c tests users
	@cd ${WRKSRC}/${i} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/${i}
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.TXT ${STAGEDIR}${DATADIR}
.for i in ADDITIONS VIRTUAL_VACATION
	@cd ${WRKSRC}/${i} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/${i}
.endfor

do-install-DOCS-on:
	@cd ${WRKSRC}/DOCUMENTS && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
