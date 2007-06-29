# New ports collection makefile for:   wordpress-mu
# Date created:                2004-12-19
# Whom:                        Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	wordpress-mu
PORTVERSION=	1.2.1
PORTEPOCH=	2
CATEGORIES=	www
MASTER_SITES=	http://ftp.twaren.net/local-distfiles/wpmu/ \
		ftp://ftp.stu.edu.tw/pub/wpmu/
DISTNAME=	wordpressmu-${PORTVERSION}

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	Multi-user version of the famous WordPress blogging application

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_PHP=	mysql pcre xml
NO_BUILD=	YES
WANT_PHP_WEB=	YES
WORDPRESSMU?=	www/data/wordpress-mu
PLIST_SUB+=	WORDPRESSMU=${WORDPRESSMU}
PLIST=		${WRKDIR}/pkg-plist

PORTDOCS=	license.txt README.txt

pre-everything::
	@${ECHO_CMD} "If you want to upgrade, you must read upgrade document."
	@${ECHO_CMD} ""
	@sleep 1

pre-install:
	cd ${WRKSRC} && ${FIND} -s * -type f | \
		${SED} -e 's|^|${WORDPRESSMU}/|' > ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm ${WORDPRESSMU}/|' >> ${PLIST} \
		&& ${ECHO_CMD} @dirrm ${WORDPRESSMU} >> ${PLIST} \
		&& ${ECHO_CMD} @dirrmtry www/data >> ${PLIST}

do-install:
	@${MKDIR} ${PREFIX}/${WORDPRESSMU}
	@${CHOWN} ${WWWOWN}:${WWWGRP} ${PREFIX}/${WORDPRESSMU}
	@${CHMOD} 755 ${PREFIX}/${WORDPRESSMU}
	@${CP} -R ${WRKSRC}/ ${PREFIX}/${WORDPRESSMU}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
