# New ports collection makefile for:	color-theme.el
# Date created:				Fri Jul 27 13:26:37 MSD 2007
# Whom:					Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$
#

PORTNAME=	color-theme.el
PORTVERSION=	6.6.0
PORTREVISION=	10
CATEGORIES=	misc elisp
MASTER_SITES=	http://download.gna.org/color-theme/
PKGNAMESUFFIX=	-${EMACS_NAME}
DISTNAME=	color-theme-${PORTVERSION}

MAINTAINER=	dsh@vlink.ru
COMMENT=	An Emacs-Lisp package with more than 50 color themes

USE_EMACS=	yes
PORTDOCS=	AUTHORS BUGS COPYING ChangeLog README

ELISPDIR=	${PREFIX}/${EMACS_SITE_LISPDIR}/color-theme
ELISPFILES=	color-theme.el color-theme.elc themes

do-build:
	(cd ${WRKSRC}; \
		${EMACS_CMD} -batch -q -f batch-byte-compile color-theme.el)

do-install:
	${MKDIR} ${ELISPDIR}
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} "${ELISPFILES}" ${ELISPDIR})
	(cd ${ELISPDIR}/themes; \
		${EMACS_CMD} -batch -q -f batch-byte-compile *.el)

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.  for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/$i ${DOCSDIR}
.  endfor
.endif

.include <bsd.port.mk>
