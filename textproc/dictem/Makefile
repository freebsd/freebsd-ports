# New ports collection makefile for:	dictem
# Date created:				24 Apr 2006
# Whom:					Max N. Boyarov <m.boyarov@gmail.com>
#
# $FreeBSD$

PORTNAME=	dictem
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	textproc net elisp
MASTER_SITES=	SF/dictem/dictem/dictem-${PORTVERSION}
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	m.boyarov@gmail.com
COMMENT=	DictEm is a dict client for [X]Emacs

RUN_DEPENDS=	${LOCALBASE}/bin/dict:${PORTSDIR}/textproc/dict

USE_EMACS=	yes

PLIST_FILES+=	${LISPDIR}/dictem.el	\
		${LISPDIR}/dictem.elc
PLIST_DIRS+=	${LISPDIR}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
PORTDOCS+=	README AUTHORS NEWS ChangeLog COPYING TODO

.include <bsd.port.pre.mk>

.if ${EMACS_NAME} == "xemacs"
LISPDIR=	${EMACS_LIBDIR}/site-packages/lisp/dictem
.else
LISPDIR=	${EMACS_VERSION_SITE_LISPDIR}/dictem
.endif

do-build:
	${EMACS_CMD} -batch -f batch-byte-compile ${WRKSRC}/dictem.el

do-install:
	${MKDIR} ${PREFIX}/${LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/dictem.el ${PREFIX}/${LISPDIR}/
	${INSTALL_DATA} ${WRKSRC}/dictem.elc ${PREFIX}/${LISPDIR}/

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
