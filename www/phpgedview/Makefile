# New ports collection makefile for:	phpGedView
# Date created:				20 fevrier 2004
# Whom:					Hubert Tournier <hubert@frbsd.org>
#
# $FreeBSD$
#

PORTNAME=	phpGedView
PORTVERSION=	3.2.1
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	phpgedview
DISTNAME=	${PORTNAME}-${PORTVERSION}final

MAINTAINER=	alecn2002@yandex.ru
COMMENT=	Online genealogy viewer

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_PHP=	yes
NO_BUILD=	yes
USE_MYSQL=	yes

GEDVIEWDIR?=	www/data/phpGedView
FULLGWDIR=	${PREFIX}/${GEDVIEWDIR}
PLIST_SUB+=	GEDVIEWDIR=${GEDVIEWDIR}

PLIST=		${WRKDIR}/pkg-plist

FILES_TO_DISTATE=	authentication_index.php \
			authentication_mysql.php \
			config.php \
			config_download.php \
			config_gedcom.php

post-extract:
.for f in ${FILES_TO_DISTATE}
	${MV}  ${WRKSRC}/${f} ${WRKSRC}/${f}-dist
.endfor
	${FIND} -s -d ${WRKSRC} -type f | ${SED} "s?${WRKSRC}?%%GEDVIEWDIR%%?g" >${PLIST}
	${FIND} -s -d ${WRKSRC} -type d  | ${SED} "s?${WRKSRC}?@dirrm %%GEDVIEWDIR%%?g" >> ${PLIST}
	${ECHO_CMD} @dirrmtry www/data >> ${PLIST}

do-install:
	${INSTALL_DATA} -d ${FULLGWDIR}
	${CP} -Rnv ${WRKSRC}/* ${FULLGWDIR}
	${FIND} ${FULLGWDIR} -type d -exec ${CHMOD} a+x {} \;
.for f in ${FILES_TO_DISTATE}
	${CHMOD} a+w ${FULLGWDIR}/${f}-dist
.endfor
	${CHMOD} a+w ${FULLGWDIR}/index

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
