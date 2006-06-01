# New ports collection makefile for:	tdtd.el
# Date created:		15 September 2000
# Whom:			Leo Kim <leo@florida.sarang.net>
#
# $FreeBSD$
#

PORTNAME=	tdtd.el
PORTVERSION=	0.7.1
PORTREVISION=	1
CATEGORIES=	textproc elisp
MASTER_SITES=	http://www.menteith.com/tdtd/data/
DISTNAME=	tdtd071
EXTRACT_SUFX=	.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An emacs major mode for editing SGML and XML DTDs

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_ZIP=	yes

ELISPDIR=	${PREFIX}/share/emacs/site-lisp
XELISPDIR=	${PREFIX}/lib/xemacs/site-lisp
PORTDOCS=	TODO changelog.txt dot_emacs readme.txt tutorial.txt

do-install:
	${MKDIR} ${ELISPDIR} ${XELISPDIR}
	@(cd ${WRKSRC}; \
		for el in tdtd.el tdtd-font.el; do \
		    ${INSTALL_DATA} $$el ${ELISPDIR}; \
		    ${LN} -sf ${ELISPDIR}/$$el ${XELISPDIR}; \
		done; \
	)
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
