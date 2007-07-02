# New ports collection makefile for:	nocc
# Date created:		Fri Feb 3 13:31:37 CET 2002
# Whom:			Alex Dupre <sysadmin@alexdupre.com>
#
# $FreeBSD$
#

PORTNAME=	nocc
DISTVERSION=	1.4
CATEGORIES=	mail www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A web-based e-mail system which access POP3 and IMAP mail servers

USE_PHP=	imap pcre session
WANT_PHP_WEB=	yes

SUB_FILES=	pkg-message
NO_BUILD=	yes

PORTDOCS=	*

post-extract:
	@${RM} -f ${WRKSRC}/themes/._.DS_Store ${WRKSRC}/themes/.DS_Store

do-install:
	${MKDIR} ${PREFIX}/www/nocc
	${CP} -Rp ${WRKSRC}/fckeditor ${WRKSRC}/html ${WRKSRC}/lang ${WRKSRC}/themes \
	          ${PREFIX}/www/nocc
	${CP} -p ${WRKSRC}/*.php ${PREFIX}/www/nocc
	${CP} -p ${WRKSRC}/conf.php.dist ${PREFIX}/www/nocc
	@if [ ! -f ${PREFIX}/www/nocc/conf.php ]; then \
		${CP} ${PREFIX}/www/nocc/conf.php.dist \
			${PREFIX}/www/nocc/conf.php; \
	fi
	${CHOWN} -R www:www ${PREFIX}/www/nocc
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o ${DOCOWN} -g ${DOCGRP} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
