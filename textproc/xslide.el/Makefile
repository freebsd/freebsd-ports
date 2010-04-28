# New ports collection makefile for:	xslide.el
# Date created:		14 January 2002
# Whom:			Leo Kim <leo@florida.sarang.net>
#
# $FreeBSD$
#

PORTNAME=	xslide.el
PORTVERSION=	0.2.2
PORTREVISION=	1
CATEGORIES=	textproc elisp
MASTER_SITES=	SF/xslide/xslide/${PORTVERSION}
DISTNAME=	xslide-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Emacs major mode for editing XSL stylesheets

NO_BUILD=	yes
PORTDOCS=	README.TXT TODO NEWS ChangeLog

ELISPDIR=	${PREFIX}/share/emacs/site-lisp
XELISPDIR=	${PREFIX}/lib/xemacs/site-lisp

do-install:
	@${MKDIR} ${ELISPDIR} ${XELISPDIR}
	(cd ${WRKSRC} && \
		for f in xslide.el \
			 xslide-abbrev.el \
			 xslide-data.el \
			 xslide-font.el \
			 xslide-initial.xsl \
			 xslide-process.el; \
		do \
		    ${INSTALL_DATA} $$f ${ELISPDIR}; \
		    ${LN} -sf ${ELISPDIR}/$$f ${XELISPDIR}; \
		done;)
.ifndef NOPORTDOCS
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && \
		${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR})
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
