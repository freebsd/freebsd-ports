# Created by: Mathias Monnerville <mathias@monnerville.com>
# $FreeBSD$

PORTNAME=	glpi
PORTVERSION=	0.90.5
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	https://github.com/glpi-project/glpi/releases/download/${PORTVERSION}/

MAINTAINER=	mathias@monnerville.com
COMMENT=	Free IT and asset management software

LICENSE=	GPLv2

USES=		cpe gettext php
CPE_VENDOR=	glpi-project
USE_PHP=	mysqli mbstring pcre session xml json ctype gd

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
GLPIDIR?=	www/${PORTNAME}

SUB_FILES=	pkg-message
SUB_LIST=	GLPIDIR=${GLPIDIR} PREFIX=${PREFIX}

OPTIONS_DEFINE=	LDAP IMAP
OPTIONS_DEFAULT=	LDAP IMAP

IMAP_DESC=	IMAP support
LDAP_USE=	PHP=ldap
IMAP_USE=	PHP=imap

post-extract:
	@${FIND} ${WRKSRC} -name '*~' -delete

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
