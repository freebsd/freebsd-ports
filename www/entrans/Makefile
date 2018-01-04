# Created by: Prudhvi Krishna <prudhvikrishna@gmail.com>
# $FreeBSD$

PORTNAME=	entrans
PORTVERSION=	0.3.3
CATEGORIES=	www
MASTER_SITES=	SF

MAINTAINER=	prudhvi-krishna-bsd@surapaneni.in
COMMENT=	Entrans is an online, collaborative translation tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

IGNORE_WITH_PHP=	70 71 72

USES=		php:web
USE_PHP=	mysql
NO_BUILD=	yes
NO_ARCH=	yes
ENTRANS?=	www/entrans
PLIST_SUB+=	ENTRANS=${ENTRANS}
PLIST=		${WRKDIR}/pkg-plist

PORTDOCS=	README INSTALL COPYING AUTHORS HACKING THANKS

OPTIONS_DEFINE=	DOCS

pre-install:
	cd ${WRKSRC} && ${FIND} -s * -type f | \
		${SED} -e 's|^|${ENTRANS}/|' > ${PLIST} \
		&& ${FIND} -d * -type d -empty | \
		${SED} -e 's|^|@dir ${ENTRANS}/|' >> ${PLIST}
	if [ ! -f ${WRKSRC}/conf/database.conf.php.sample ]; then ${CP} \
		${WRKSRC}/conf/database.conf.php.sample ${WRKSRC}/conf/database.conf.php; fi

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${ENTRANS}
	${CP} -R ${WRKSRC}/ ${STAGEDIR}${PREFIX}/${ENTRANS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}/${i}
.endfor

.include <bsd.port.mk>
