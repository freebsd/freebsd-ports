# Created by: Leo Kim <leo@florida.sarang.net>
# $FreeBSD$

PORTNAME=	xslide.el
PORTVERSION=	0.2.2
PORTREVISION=	1
CATEGORIES=	textproc elisp
MASTER_SITES=	SF/xslide/xslide/${PORTVERSION}
DISTNAME=	xslide-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Emacs major mode for editing XSL stylesheets

LICENSE=	GPLv2+

PORTDOCS=	README.TXT TODO NEWS ChangeLog
NO_BUILD=	yes
NO_ARCH=	yes

ELISPDIR=	${PREFIX}/share/emacs/site-lisp
XELISPDIR=	${PREFIX}/lib/xemacs/site-lisp

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${ELISPDIR} ${STAGEDIR}${XELISPDIR}
.for f in xslide.el xslide-abbrev.el xslide-data.el xslide-font.el \
xslide-initial.xsl xslide-process.el
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${ELISPDIR}
	${LN} -sf ${ELISPDIR}/${f} ${STAGEDIR}${XELISPDIR}
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
