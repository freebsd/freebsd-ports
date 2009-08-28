# New ports collection makefile for:   lilurl
# Date created:                2006/09/10
# Whom:                        chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	lilurl
PORTVERSION=	0.1.1
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple PHP/MySQL script for generating lil? URLs

USE_PHP=	mysql pcre
NO_BUILD=	yes
WANT_PHP_WEB=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
LILURL_DIR?=	www/lilurl
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message
PLIST=		${WRKDIR}/pkg-plist

.include <bsd.port.pre.mk>

post-extract:
	@${MV} ${WRKSRC}/includes/conf.php ${WRKSRC}/includes/conf.php.sample

pre-install:
	@cd ${WRKSRC} && ${FIND} -s . -type f | \
		${SED} -e 's|^./||;s|^|${LILURL_DIR}/|' > ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm ${LILURL_DIR}/|' >> ${PLIST} \
		&& ${ECHO_CMD} @dirrm ${LILURL_DIR} >> ${PLIST}

do-install:
	${MKDIR} ${PREFIX}/${LILURL_DIR}
	@${CP} -R ${WRKSRC}/ ${PREFIX}/${LILURL_DIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${LILURL_DIR}

post-install:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},; s,%%LILURL_DIR%%,${LILURL_DIR},g' \
		${PKGMESSAGE}

.include <bsd.port.post.mk>
