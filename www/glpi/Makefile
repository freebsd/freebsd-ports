# Created by: Mathias Monnerville <mathias@monnerville.com>
# $FreeBSD$

PORTNAME=	glpi
PORTVERSION=	0.84.2
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	http://droidng.free.fr/freebsd/ \
		http://glpi-project.org/IMG/gz/

MAINTAINER=	mathias@monnerville.com
COMMENT=	Free IT and asset management software

LICENSE=	GPLv2

USE_PHP=	mysql mbstring pcre session xml json ctype
WANT_PHP_WEB=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
CPIOARGS=	--quiet -pdum

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
	@${MKDIR} -m 0755 ${STAGEDIR}${PREFIX}/${GLPIDIR}
	@cd ${WRKSRC} && ${FIND} * -print | ${CPIO} ${CPIOARGS} ${STAGEDIR}${PREFIX}/${GLPIDIR}

.include <bsd.port.mk>
