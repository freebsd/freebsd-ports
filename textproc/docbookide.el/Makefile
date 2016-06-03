# Created by: Sean Chittenden <seanc@FreeBSD.org>
# $FreeBSD$

PORTNAME=	docbookide.el
PORTVERSION=	0.1
CATEGORIES=	textproc elisp
MASTER_SITES=	http://nwalsh.com/emacs/docbookide/
DISTNAME=	docbookide01

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Emacs lisp modules for editing DocBook documents

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

USES=		zip
WRKSRC=		${WRKDIR}/docbookide
NO_BUILD=	yes

ELISP_FILES=	dbide-abbrev.el dbide-data.el dbide-font.el \
		dbide-process.el docbookide.el make-regexp.el

EMACS_LISPDIR=	${PREFIX}/share/emacs/site-lisp/docbookide
XEMACSLISPDIR=	${PREFIX}/lib/xemacs/site-lisp/docbookide

do-install:
	${MKDIR} ${STAGEDIR}${EMACS_LISPDIR}
	${MKDIR} ${STAGEDIR}${XEMACSLISPDIR}
.for f in ${ELISP_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${EMACS_LISPDIR}
	${LN} -sf ${EMACS_LISPDIR}/${f} ${STAGEDIR}${XEMACSLISPDIR}
.endfor

.include <bsd.port.mk>
