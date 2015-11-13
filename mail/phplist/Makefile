# Created by: Nick Hilliard <nick@foobar.org>
# $FreeBSD$

PORTNAME=	phplist
PORTVERSION=	3.2.1
CATEGORIES=	mail www
MASTER_SITES=	SF

MAINTAINER=	ports@bsdserwis.com
COMMENT=	Full-featured open-source newsletter manager

LICENSE=	GPLv3
LICENSE_FILe=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PEARDIR}/HTTP/Request.php:${PORTSDIR}/www/pear-HTTP_Request

USES=		cpe tar:tgz
USE_PHP=	hash iconv imap mysql pcre session xml zlib
WANT_PHP_WEB=	yes
NO_BUILD=	yes
NO_ARCH=	yes

PEARDIR?=	${LOCALBASE}/share/pear

PORTDOCS=	INSTALL PEOPLE README.md TODO UPGRADE VERSION

OPTIONS_DEFINE=	DOCS
SUB_FILES=	phplist

post-extract:
	@${MV} ${WRKSRC}/public_html/lists/config/config.php ${WRKSRC}/public_html/lists/config/config.php.sample

# Note: there is file(s) with non-ascii filenames. So it's difficult to add
# such files to pkg-plist. That's why there is find with delete
#
do-install:
	@${FIND} ${WRKSRC}/public_html/ -type f -regex '.*[^!-~].*' -delete
	${MKDIR} ${STAGEDIR}${WWWDIR}/
	(cd ${WRKSRC}/public_html/ && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})
	${INSTALL_SCRIPT} ${WRKDIR}/phplist ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/doc/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
