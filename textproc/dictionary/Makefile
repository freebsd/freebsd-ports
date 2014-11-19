# Created by: Kimura Fuyuki <fuyuki@mj.0038.net>
# $FreeBSD$

PORTNAME=	dictionary
PORTVERSION=	1.8.7
PORTREVISION=	15
CATEGORIES=	textproc net elisp
MASTER_SITES=	http://me.in-berlin.de/~myrkr/dictionary/ \
		http://bsdchat.com/dist/dryice/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dictionary client for Emacs

USE_EMACS=	yes

LISPDIR=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
ELS=		connection.el dictionary.el link.el
DOCSDIR=	README

do-build:
	cd ${WRKSRC}; ${EMACS_CMD} -batch -l lpath.el -f batch-byte-compile ${ELS}

do-install:
	@${MKDIR} ${STAGEDIR}${LISPDIR}
.for i in ${ELS} *.elc dictionary-init.el
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${LISPDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
