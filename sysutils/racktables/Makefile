# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	racktables
DISTVERSION=	0.21.4
CATEGORIES?=	sysutils www
MASTER_SITES=	SF/${PORTNAME}/
DISTNAME=	RackTables-${DISTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Server room asset management suite

LICENSE=	GPLv2

NO_BUILD=	yes
RACKHOME?=	www/racktables

PORTEXAMPLES=	cleanup_ldap_cache.php init-sample-racks.sql syncdomain.php

USES=		shebangfix php:web perl5 python:run
NO_ARCH=	yes
USE_PERL5=	run
SHEBANG_FILES=	gateways/*

USE_PHP=	bcmath gd json mbstring mysqli pdo_mysql session
SUB_FILES=	pkg-message
PLIST_SUB=	WWWDIR_REL=${WWWDIR_REL} WWWDIR=${WWWDIR}
WWWUSER?=	www
WWWGRP?=	www

OPTIONS_DEFINE=	LDAP SNMP CURL PCNTL PCRE EXAMPLES
PCRE_DESC=	Regular Expression Support
PCNTL_DESC=	pcntl Support
LDAP_USE=	PHP=ldap
SNMP_USE=	PHP=snmp
CURL_USE=	PHP=curl
PCNTL_USE=	PHP=pcntl
PCRE_USE=	PHP=pcre

post-patch:
	@${FIND} ${WRKSRC} -name \*.orig -type f -delete

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}/wwwroot ${STAGEDIR}${WWWDIR}/gateways
	(cd ${WRKSRC} && ${COPYTREE_SHARE} wwwroot ${STAGEDIR}${WWWDIR})
	(cd ${WRKSRC} && ${COPYTREE_BIN} gateways ${STAGEDIR}${WWWDIR})
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/scripts/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
