# New ports collection makefile for:   wordpress-mu
# Date created:                2004-12-19
# Whom:                        Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	wordpress-mu
PORTVERSION=	2005.01.12
CATEGORIES=	www
MASTER_SITES=	http://mu.wordpress.org/download/
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

post-install:
	@${ECHO_MSG}
	@${ECHO_MSG} "          **** NOTE ****"
	@${ECHO_MSG} "Before the first use of WordPress-MU, copy wp-inst/wp-config-sample.php to wp-inst/wp-config.php"
	@${ECHO_MSG} "in ${PREFIX}/${WORDPRESSMU}/wp-inst/"
	@${ECHO_MSG} "And Modify it to fit your MySQL."
	@${ECHO_MSG} "Maybe you need 'mysqladmin create wordpress' first"
	@${ECHO_MSG}

.include <bsd.port.mk>
