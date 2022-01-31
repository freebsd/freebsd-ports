# Created by: Alex Dupre <sysadmin@alexdupre.com>

PORTNAME=	nocc
PORTVERSION=	1.9.11
CATEGORIES=	mail www
MASTER_SITES=	SF/${PORTNAME}/NOCC/${PORTVERSION}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Webmail system which access POP3 and IMAP mail servers

LICENSE=	GPLv2

USES=		cpe php:web

OPTIONS_DEFINE=	DOCS

USE_PHP=	ctype iconv imap mbstring openssl pcre session

SUB_FILES=	pkg-message
NO_ARCH=	yes
NO_BUILD=	yes

NOCCCOMP=	.htaccess favicon.ico robots.txt \
		action.php ckeditor.php ckeditor5.php common.php \
		contacts.php contacts_manager.php \
		delete.php down_mail.php download.php get_img.php \
		help.php index.php logout.php rss.php send.php \
		ckeditor5 classes config html htmlpurifier js lang \
		themes utils

PORTDOCS=	*

post-extract:
	@${FIND} ${WRKSRC} -type d -empty -delete

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
.for i in ${NOCCCOMP}
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${i} ${STAGEDIR}${WWWDIR}
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${STAGEDIR}${DOCSDIR}
	@${ECHO_CMD} "@owner ${WWWOWN}" >> ${TMPPLIST}
	@${ECHO_CMD} "@group ${WWWGRP}" >> ${TMPPLIST}
	@(cd ${WRKSRC}; ${FIND} ${NOCCCOMP} -not -type d) | ${SORT} | \
		${SED} -ne 's,^,${WWWDIR_REL}/,p' >> ${TMPPLIST}
	@${ECHO_CMD} "@owner" >> ${TMPPLIST}
	@${ECHO_CMD} "@group" >> ${TMPPLIST}

.include <bsd.port.mk>
