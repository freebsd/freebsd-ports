# New ports collection makefile for:	htmlize.el
# Date created:				15 January 2004
# Whom:					Marc van Woerkom <marc.vanwoerkom@fernuni-hagen.de>
#
# $FreeBSD$
#

PORTNAME=	htmlize.el
PORTVERSION=	1.16
CATEGORIES=	textproc elisp
MASTER_SITES=	http://fly.srk.fer.hr/~hniksic/emacs/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	marc.vanwoerkom@fernuni-hagen.de
COMMENT=	Emacs major mode to create HTML files from Emacs buffers (in colour!)

RUN_DEPENDS=	emacs:${PORTSDIR}/editors/emacs

NO_BUILD=	yes

LISPDIR=	${PREFIX}/share/emacs/site-lisp

do-install:
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME} ${LISPDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
