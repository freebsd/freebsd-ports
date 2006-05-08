# New ports collection makefile for:	xslide.el
# Date created:		14 January 2002
# Whom:			Leo Kim <leo@florida.sarang.net>
#
# $FreeBSD$
#

PORTNAME=	xslide.el
PORTVERSION=	0.2.2
CATEGORIES=	textproc elisp
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	xslide
DISTNAME=	xslide-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Emacs major mode for editing XSL stylesheets

NO_BUILD=	yes
PORTDOCS=	README.TXT TODO NEWS ChangeLog

ELISPDIR=	${PREFIX}/share/emacs/site-lisp

do-install:
	@${MKDIR} ${ELISPDIR}
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && \
		${INSTALL_DATA} \
			xslide.el \
			xslide-abbrev.el \
			xslide-data.el \
			xslide-font.el \
			xslide-initial.xsl \
			xslide-process.el \
			${ELISPDIR} && \
		${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR} \
		)

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
