# New ports collection makefile for:   wordpress-mu
# Date created:                2004-12-19
# Whom:                        Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	wordpress-mu
PORTVERSION=	2005.02.23
CATEGORIES=	www
MASTER_SITES=	http://blogs.linux.ie/download/wpmu/ \
		http://mu.wordpress.org/download/
DISTNAME=	wpmu-${PORTVERSION:S/./-/g}

MAINTAINER=	tjs@cdpa.nsysu.edu.tw
COMMENT=	Multi-user version of the famous WordPress blogging application

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_PHP=	mysql pcre xml
PHP4_PORT?=	www/mod_php4
NO_BUILD=	yes
WANT_PHP_WEB=	yes
WORDPRESSMU?=	www/data/wordpress-mu
PLIST_SUB+=	WORDPRESSMU=${WORDPRESSMU}
PLIST=		${WRKDIR}/pkg-plist

PORTDOCS=	license.txt readme.html

do-install:
	@${MKDIR} ${PREFIX}/${WORDPRESSMU}
	@${CHOWN} www:www ${PREFIX}/${WORDPRESSMU}
	@${CHMOD} 755 ${PREFIX}/${WORDPRESSMU}
	@${CP} -R ${WRKSRC}/ ${PREFIX}/${WORDPRESSMU}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/wp-inst/${i} ${DOCSDIR}
.endfor
.endif

pre-install:
	cd ${WRKSRC} && ${FIND} -s * -type f | \
		${SED} -e 's|^|${WORDPRESSMU}/|' > ${PLIST} \
		&& ${FIND} -d * -type d | \
	${SED} -e 's|^|@dirrm ${WORDPRESSMU}/|' >> ${PLIST} \
		&& ${ECHO_CMD} @dirrm ${WORDPRESSMU} >> ${PLIST}

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
