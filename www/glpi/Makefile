# Created by: Mathias Monnerville <mathias@monnerville.com>
# $FreeBSD$

PORTNAME=	glpi
PORTVERSION=	0.83.8
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	http://droidng.free.fr/freebsd/ \
		http://glpi-project.org/IMG/gz/

MAINTAINER=	mathias@monnerville.com
COMMENT=	Free IT and asset management software

USE_PHP=	mysql mbstring pcre session xml json ctype
WANT_PHP_WEB=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
CPIOARGS=	--quiet -pdum -R

GLPIDIR?=	www/${PORTNAME}

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

post-configure:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' \
	  -e 's,%%GLPIDIR%%,${GLPIDIR},g' pkg-message > ${PKGMESSAGE}

do-install:
	@${MKDIR} -m 0755 ${PREFIX}/${GLPIDIR}
	@cd ${WRKSRC} && ${FIND} * -print | ${CPIO} ${CPIOARGS} ${WWWOWN}:${WWWGRP} ${PREFIX}/${GLPIDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${GLPIDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
