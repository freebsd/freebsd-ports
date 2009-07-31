# New ports collection makefile for:	htmlize.el
# Date created:				15 January 2004
# Whom:					Marc van Woerkom <marc.vanwoerkom@fernuni-hagen.de>
#
# $FreeBSD$
#

PORTNAME=	htmlize.el
PORTVERSION=	1.34
PORTREVISION=	1
CATEGORIES=	textproc elisp
MASTER_SITES=	http://fly.srk.fer.hr/~hniksic/emacs/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Emacs major mode to create HTML files from Emacs buffers (in colour!)

USE_EMACS=	yes
EMACS_PORT_NAME?=	emacs21
NO_WRKSUBDIR=	yes
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	${WRKSRC}/htmlize.el

PLIST_FILES=	${EMACS_SITE_LISPDIR}/htmlize.el \
		${EMACS_SITE_LISPDIR}/htmlize.elc

LISPDIR=	${PREFIX}/${EMACS_SITE_LISPDIR}

do-build:
	cd ${WRKSRC}; ${EMACS_CMD} -batch -q -f batch-byte-compile htmlize.el

do-install:
	${INSTALL_DATA} ${WRKSRC}/htmlize.* ${LISPDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
