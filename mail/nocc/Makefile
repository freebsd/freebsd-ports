# New ports collection makefile for:	nocc
# Date created:		Fri Feb 3 13:31:37 CET 2002
# Whom:			Alex Dupre <sysadmin@alexdupre.com>
#
# $FreeBSD$
#

PORTNAME=	nocc
PORTVERSION=	1.8
CATEGORIES=	mail www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A web-based e-mail system which access POP3 and IMAP mail servers

USE_PHP=	iconv imap mbstring pcre session
WANT_PHP_WEB=	yes

SUB_FILES=	pkg-message
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PORTDOCS=	*

do-install:
	${MKDIR} ${PREFIX}/www/nocc
	${CP} -Rp ${WRKSRC}/classes ${WRKSRC}/config ${WRKSRC}/fckeditor \
		${WRKSRC}/html ${WRKSRC}/js ${WRKSRC}/lang ${WRKSRC}/themes \
		${WRKSRC}/utils \
		${PREFIX}/www/nocc
	${CP} -p ${WRKSRC}/*.php ${WRKSRC}/*.ico ${PREFIX}/www/nocc
	@if [ ! -f ${PREFIX}/www/nocc/config/conf.php ]; then \
		${CP} ${PREFIX}/www/nocc/config/conf.php.dist \
			${PREFIX}/www/nocc/config/conf.php; \
	fi
	${CHOWN} -R www:www ${PREFIX}/www/nocc
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o ${DOCOWN} -g ${DOCGRP} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
