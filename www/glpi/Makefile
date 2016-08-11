# Created by: Mathias Monnerville <mathias@monnerville.com>
# $FreeBSD$

PORTNAME=	glpi
PORTVERSION=	0.90.3
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	http://github.com/glpi-project/glpi/releases/download/0.90.3/

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
IMAP_DESC=	IMAP support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLDAP}
USE_PHP+=	ldap
.endif

.if ${PORT_OPTIONS:MIMAP}
USE_PHP+=	imap
.endif

post-extract:
	@${FIND} ${WRKSRC} -name '*~' -delete

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
