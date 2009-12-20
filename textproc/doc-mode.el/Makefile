# New ports collection makefile for:   doc-mode.el
# Date created:		2 May 2008
# Whom:			Peter Schuller <peter.schuller@infidyne.com>
#
# $FreeBSD$
#

PORTNAME=	doc-mode.el
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	textproc elisp
MASTER_SITES=	SF/xpt/doc-mode/doc-mode-${PORTVERSION}
DISTNAME=	doc-mode-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	peter.schuller@infidyne.com
COMMENT=	Asciidoc fontlocking for emacs

USE_EMACS=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/doc-mode.el ${PREFIX}/${EMACS_SITE_LISPDIR}/doc-mode.el

.include <bsd.port.mk>
