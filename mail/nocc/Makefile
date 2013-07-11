# Created by: Alex Dupre <sysadmin@alexdupre.com>
# $FreeBSD$

PORTNAME=	nocc
PORTVERSION=	1.9.3
PORTREVISION=	1
CATEGORIES=	mail www
MASTER_SITES=	SF/${PORTNAME}/NOCC/${PORTVERSION}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A webmail system which access POP3 and IMAP mail servers

OPTIONS_DEFINE=	DOCS

USE_PHP=	ctype iconv imap mbstring pcre session
WANT_PHP_WEB=	yes

SUB_FILES=	pkg-message
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

NOCCCOMP=	.htaccess favicon.ico robots.txt \
		action.php common.php contacts.php contacts_manager.php \
		delete.php down_mail.php download.php get_img.php \
		help.php index.php logout.php rss.php send.php \
		ckeditor classes config html js lang themes utils

PORTDOCS=	*

.include <bsd.port.options.mk>

do-install:
	@${MKDIR} ${WWWDIR}
.for i in ${NOCCCOMP}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} ${i} ${WWWDIR}
.endfor
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCSDIR}
.endif
	@(cd ${WRKSRC}; ${FIND} ${NOCCCOMP} -not -type d) | ${SORT} | \
		${SED} -ne 's,^,${WWWDIR_REL}/,p' >> ${TMPPLIST}
	@(cd ${WRKSRC}; ${FIND} ${NOCCCOMP} -type d) | ${SORT} -r | \
		${SED} -ne 's,^,@dirrm ${WWWDIR_REL}/,p' >> ${TMPPLIST}
	@${ECHO_CMD} '@dirrm ${WWWDIR_REL}' >> ${TMPPLIST}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
