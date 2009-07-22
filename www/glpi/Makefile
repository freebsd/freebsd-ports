# New ports collection makefile for:	glpi
# Date created:			9 February 2007
# Whom:				Mathias Monnerville <mathias@monnerville.com>
#
# $FreeBSD$
#

PORTNAME=	glpi
DISTVERSION=	0.72
CATEGORIES=	www
MASTER_SITES=	http://glpi-project.org/IMG/gz/ \
		http://download.gna.org/kanicule/freebsd/distfiles/

MAINTAINER=	mathias@monnerville.com
COMMENT=	Free IT and asset management software

USE_PHP=	mysql pcre session xml
WANT_PHP_WEB=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
CPIOARGS=	--quiet -pdum -R

GLPIDIR?=	www/${PORTNAME}

.include <bsd.port.pre.mk>

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

.include <bsd.port.post.mk>
