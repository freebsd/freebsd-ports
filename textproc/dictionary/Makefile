# Created by: Kimura Fuyuki <fuyuki@mj.0038.net>
# $FreeBSD$

PORTNAME=	dictionary
PORTVERSION=	1.8.7
PORTREVISION=	23
CATEGORIES=	textproc net elisp
MASTER_SITES=	http://me.in-berlin.de/~myrkr/dictionary/ \
		http://bsdchat.com/dist/dryice/
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dictionary client for Emacs

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/GPL

USES=		emacs

LISPDIR=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
ELS=		connection.el dictionary.el link.el

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-build:
	cd ${WRKSRC} && ${EMACS_CMD} -batch -l lpath.el -f batch-byte-compile ${ELS}

do-install:
	@${MKDIR} ${STAGEDIR}${LISPDIR}
.for i in ${ELS} *.elc dictionary-init.el
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${LISPDIR}
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
