# New ports collection makefile for:	wordpress
# Date created:		2004-07-29
# Whom:			Elvis Chiang <elvis@sslab.cs.ccu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	wordpress
PORTVERSION=	1.2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	cafelog
EXTRACT_SUFX=	-mingus.tar.gz

MAINTAINER=	elvis@sslab.cs.ccu.edu.tw
COMMENT=	A state-of-the-art semantic personal publishing platform

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_PHP=	mysql
PHP4_PORT?=	www/mod_php4
NO_BUILD=	YES
WANT_PHP_WEB=	YES
WORDPRESS?=	www/data-dist/wordpress
PLIST_SUB+=	WORDPRESS=${WORDPRESS}

.if !defined(NOPORTDOCS)
PORTDOCS=	license.txt readme.html
.endif

do-install:
	-${MKDIR} ${PREFIX}/${WORDPRESS}
	@${CHOWN} www:www ${PREFIX}/${WORDPRESS}
	@${CHMOD} 755 ${PREFIX}/${WORDPRESS}
	@${CP} -R ${WRKSRC}/ ${PREFIX}/${WORDPRESS}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/${i}
.endfor
.endif

post-install:
	@${ECHO_MSG}
	@${ECHO_MSG} "          **** NOTE ****"
	@${ECHO_MSG} "Before the first use of WordPress, copy wp-config-sample.php to wp-config.php"
	@${ECHO_MSG} "in ${PREFIX}/${WORDPRESS}"
	@${ECHO_MSG} "And Modify it to fit your MySQL."
	@${ECHO_MSG} "Maybe you need 'mysqladmin create wordpress' first"
	@${ECHO_MSG}

.include <bsd.port.mk>
