# New ports collection makefile for:	phpGedView
# Date created:				20 fevrier 2004
# Whom:					Hubert Tournier <hubert@frbsd.org>
#
# $FreeBSD$
#

PORTNAME=	phpgedview
PORTVERSION=	2.65.3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	phpGedView-${PORTVERSION}

MAINTAINER=	hubert@frbsd.org
COMMENT=	Online genealogy viewer

USE_PHP=	yes
WRKSRC=		${WRKDIR}/phpGedView
NO_BUILD=	yes

GEDVIEWDIR?=	www/data/phpGedView
PLIST_SUB+=	GEDVIEWDIR=${GEDVIEWDIR}

do-install:
	${MKDIR} ${PREFIX}/${GEDVIEWDIR}
	${LN} -f ${WRKSRC}/authenticate.php ${WRKSRC}/authenticate.php-dist
	${LN} -f ${WRKSRC}/config.php ${WRKSRC}/config.php-dist
	${CP} -Rn ${WRKSRC}/* ${PREFIX}/${GEDVIEWDIR}
	${RM} ${PREFIX}/${GEDVIEWDIR}/GPL.txt
	${RM} ${PREFIX}/${GEDVIEWDIR}/changelog.txt
	${RM} ${PREFIX}/${GEDVIEWDIR}/languages/LANG_CHANGELOG.txt
	${FIND} ${PREFIX}/${GEDVIEWDIR} -type d -exec ${CHMOD} a+x {} \;
	${CHMOD} a+w ${PREFIX}/${GEDVIEWDIR}/authenticate.php
	${CHMOD} a+w ${PREFIX}/${GEDVIEWDIR}/config.php
	${CHMOD} a+w ${PREFIX}/${GEDVIEWDIR}/index

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
