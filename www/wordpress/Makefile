# New ports collection makefile for:	wordpress
# Date created:		2004-07-29
# Whom:			Elvis Chiang <elvis@sslab.cs.ccu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	wordpress
PORTVERSION=	3.0.0
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	http://wordpress.org/ \
		ftp://ftp.stu.edu.tw/pub/wordpress/ \
		ftp://ftp.twaren.net/local-distfiles/wordpress/
MASTER_SITE_SUBDIR=	cafelog
DISTNAME=		wordpress-${PORTVERSION:S/.0//}

MAINTAINER=	ychsiao@ychsiao.org
COMMENT=	A state-of-the-art semantic personal publishing platform

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_PHP=	mysql pcre xml gd tokenizer
NO_BUILD=	YES
WANT_PHP_WEB=	YES
WORDPRESS?=	www/data/wordpress
PLIST_SUB+=	WORDPRESS=${WORDPRESS}
PLIST=		${WRKDIR}/pkg-plist

PORTDOCS=	license.txt readme.html

pre-everything::
	@${ECHO_CMD} "If you want to upgrade, you must read upgrade document."
	@${ECHO_CMD} ""
	@sleep 1

pre-install:
	cd ${WRKSRC} && ${FIND} -s * -type f | \
		${SED} -e 's|^|${WORDPRESS}/|' > ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm ${WORDPRESS}/|' >> ${PLIST} \
		&& ${ECHO_CMD} @dirrm ${WORDPRESS} >> ${PLIST} \
		&& ${ECHO_CMD} @dirrmtry www/data >> ${PLIST}
	if [ ! -f ${WRKSRC}/wp-config-sample.php ]; then ${CP} \
		${WRKSRC}/wp-config.php.sample ${WRKSRC}/wp-config.php; fi

do-install:
	-@${MKDIR} ${PREFIX}/${WORDPRESS}
	@${CHOWN} ${WWWOWN}:${WWWGRP} ${PREFIX}/${WORDPRESS}
	@${CHMOD} 755 ${PREFIX}/${WORDPRESS}
	${CP} -R ${WRKSRC}/ ${PREFIX}/${WORDPRESS}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/${i}
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
