# New ports collection makefile for:	entrans
# Date created:		Jan-25-2007
# Whom:			Prudhvi Krishna <prudhvikrishna@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	entrans
PORTVERSION=	0.3.2
CATEGORIES=	www
MASTER_SITES=	SF

MAINTAINER=	prudhvi-krishna-bsd@surapaneni.in
COMMENT=	Entrans is an online, collaborative translation tool

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_PHP=	mysql
NO_BUILD=	YES
WANT_PHP_WEB=	YES
ENTRANS?=	www/entrans
PLIST_SUB+=	ENTRANS=${ENTRANS}
PLIST=		${WRKDIR}/pkg-plist

PORTDOCS=	README INSTALL COPYING AUTHORS HACKING THANKS

pre-install:
	cd ${WRKSRC} && ${FIND} -s * -type f | \
		${SED} -e 's|^|${ENTRANS}/|' > ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm ${ENTRANS}/|' >> ${PLIST} \
		&& ${ECHO_CMD} @dirrm ${ENTRANS} >> ${PLIST} \
		&& ${ECHO_CMD} @dirrmtry www/data >> ${PLIST}
	if [ ! -f ${WRKSRC}/conf/database.conf.php.sample ]; then ${CP} \
		${WRKSRC}/conf/database.conf.php.sample ${WRKSRC}/conf/database.conf.php; fi

do-install:
	-@${MKDIR} ${PREFIX}/${ENTRANS}
	@${CHOWN} ${WWWOWN}:${WWWGRP} ${PREFIX}/${ENTRANS}
	@${CHMOD} 755 ${PREFIX}/${ENTRANS}
	${CP} -R ${WRKSRC}/ ${PREFIX}/${ENTRANS}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/${i}
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
