# New ports collection makefile for:   dictionary
# Date created:                23 March 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	dictionary
PORTVERSION=	1.8.7
PORTREVISION=	3
CATEGORIES=	textproc net elisp
MASTER_SITES=	http://me.in-berlin.de/~myrkr/dictionary/ \
		http://bsdchat.com/dist/dryice/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A dictionary client for Emacs

USE_EMACS=	yes
EMACS_PORT_NAME?=	emacs22

LISPDIR=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
ELS=		connection.el dictionary.el link.el

do-build:
	cd ${WRKSRC}; ${EMACS_CMD} -batch -l lpath.el -f batch-byte-compile ${ELS}

do-install:
	${MKDIR} ${LISPDIR}
.for i in ${ELS} *.elc dictionary-init.el
	${INSTALL_DATA} ${WRKSRC}/${i} ${LISPDIR}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
