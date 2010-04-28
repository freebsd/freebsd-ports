# New ports collection makefile for:	docbookide
# Date created:		2 July 2002
# Whom:			Sean Chittenden <seanc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	docbookide.el
PORTVERSION=	0.1
CATEGORIES=	textproc elisp
MASTER_SITES=	http://nwalsh.com/emacs/docbookide/
DISTNAME=	docbookide01

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Emacs lisp modules for editing DocBook documents

USE_ZIP=	yes
WRKSRC=		${WRKDIR}/docbookide
NO_BUILD=	yes

ELISP_FILES=	dbide-abbrev.el dbide-data.el dbide-font.el \
		dbide-process.el docbookide.el make-regexp.el

EMACS_LISPDIR=	${PREFIX}/share/emacs/site-lisp/docbookide
XEMACSLISPDIR=	${PREFIX}/lib/xemacs/site-lisp/docbookide

do-install:
	${MKDIR} ${EMACS_LISPDIR}
	${MKDIR} ${XEMACSLISPDIR}
.for f in ${ELISP_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${EMACS_LISPDIR}/
	${LN} -sf ${EMACS_LISPDIR}/${f} ${XEMACSLISPDIR}/
.endfor
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
