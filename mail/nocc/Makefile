# New ports collection makefile for:	nocc
# Date created:		Fri Feb 3 13:31:37 CET 2002
# Whom:			Alex Dupre <sysadmin@alexdupre.com>
#
# $FreeBSD$
#

PORTNAME=	nocc
PORTVERSION=	1.9.2
CATEGORIES=	mail www
MASTER_SITES=	SF/${PORTNAME}/NOCC/${PORTVERSION}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A webmail system which access POP3 and IMAP mail servers

USE_PHP=	iconv imap mbstring pcre session
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

do-install:
	@${MKDIR} ${WWWDIR}
.for i in ${NOCCCOMP}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} ${i} ${WWWDIR}
.endfor
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
.if !defined(NOPORTDOCS)
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
