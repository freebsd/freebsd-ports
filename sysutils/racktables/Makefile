# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	racktables
DISTVERSION=	0.20.11
CATEGORIES?=	sysutils www
MASTER_SITES=	SF/${PORTNAME}/
DISTNAME=	RackTables-${DISTVERSION}

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Server room asset management suite

LICENSE=	GPLv2

NO_BUILD=	yes
RACKHOME?=	www/racktables

PORTEXAMPLES=	init-sample-racks.sql syncdomain.php

USES=		shebangfix perl5 python:run
USE_PERL5=	run
SHEBANG_FILES=	gateways/*

WANT_PHP_WEB=	yes
USE_PHP=	bcmath gd json mbstring mysql pdo_mysql session
SUB_FILES=	pkg-message
PLIST_SUB=	WWWDIR_REL=${WWWDIR_REL} WWWDIR=${WWWDIR}
WWWUSER?=	www
WWWGRP?=	www

OPTIONS_DEFINE=	LDAP SNMP CURL LANG PCNTL PCRE
PCRE_DESC=	Regular Expression Support
PCNTL_DESC=	pcntl Support
LANG_DESC=	Additional Language Support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLDAP}
USE_PHP+=	ldap
.endif

.if ${PORT_OPTIONS:MSNMP}
USE_PHP+=	snmp
.endif

.if ${PORT_OPTIONS:MCURL}
USE_PHP+=	curl
.endif

.if ${PORT_OPTIONS:MLANG}
USE_PHP+=	lang
.endif

.if ${PORT_OPTIONS:MPCNTL}
USE_PHP+=	pcntl
.endif

.if ${PORT_OPTIONS:MPCRE}
USE_PHP+=	pcre
.endif

post-patch:
	@${FIND} ${WRKSRC} -name \*.orig -type f -delete

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}/wwwroot ${STAGEDIR}${WWWDIR}/gateways
	(cd ${WRKSRC} && ${COPYTREE_SHARE} wwwroot ${STAGEDIR}${WWWDIR})
	(cd ${WRKSRC} && ${COPYTREE_BIN} gateways ${STAGEDIR}${WWWDIR})
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/scripts/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
