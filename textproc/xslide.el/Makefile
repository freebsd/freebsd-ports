# New ports collection makefile for:	xslide.el
# Date created:		14 January 2002
# Whom:			Leo Kim <leo@florida.sarang.net>
#
# $FreeBSD$
#

PORTNAME=	xslide.el
PORTVERSION=	0.2
CATEGORIES=	textproc elisp
MASTER_SITES=	http://www.menteith.com/xslide/data/
DISTNAME=	xslide

MAINTAINER=	leo@florida.sarang.net

RUN_DEPENDS=	emacs:${PORTSDIR}/editors/emacs21

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_ZIP=	yes

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
		${INSTALL_DATA} \
			CHANGELOG.TXT README.TXT ${DOCSDIR} \
		)

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
