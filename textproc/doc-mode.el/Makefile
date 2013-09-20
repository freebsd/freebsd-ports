# Created by: Peter Schuller <peter.schuller@infidyne.com>
# $FreeBSD$

PORTNAME=	doc-mode.el
PORTVERSION=	1.1
PORTREVISION=	11
CATEGORIES=	textproc elisp
MASTER_SITES=	SF/xpt/doc-mode/doc-mode-${PORTVERSION}
DISTNAME=	doc-mode-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Asciidoc fontlocking for emacs

USE_EMACS=	yes
NO_BUILD=	yes

NO_STAGE=	yes
do-install:
	${INSTALL_DATA} ${WRKSRC}/doc-mode.el ${PREFIX}/${EMACS_SITE_LISPDIR}/doc-mode.el

.include <bsd.port.mk>
