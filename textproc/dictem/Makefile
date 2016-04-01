# Created by: Max N. Boyarov <m.boyarov@gmail.com>
# $FreeBSD$

PORTNAME=	dictem
PORTVERSION=	1.0.4
PORTREVISION=	2
CATEGORIES=	textproc net elisp
MASTER_SITES=	SF/dictem/dictem/dictem-${PORTVERSION}
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	max.n.boyarov@gmail.com
COMMENT=	DictEm is a dict client for [X]Emacs

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/bin/dict:textproc/dict

USE_EMACS=	yes

SRC_EL=		dictem.el dictem-lingvo-dsl.el dictem-elisp.el

.for f in ${SRC_EL}
PLIST_FILES+=	${LISPDIR}/${f} \
		${LISPDIR}/${f:S/.el$/.elc/}
.endfor

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
PORTDOCS+=	README AUTHORS NEWS COPYING TODO

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${EMACS_NAME} == "xemacs"
LISPDIR=	${EMACS_LIBDIR}/site-packages/lisp/dictem
.else
LISPDIR=	${EMACS_VERSION_SITE_LISPDIR}/dictem
.endif

do-build:
	cd ${WRKSRC} && ${EMACS_CMD} --no-site-file --no-init-file -batch \
		-l compile.el -f compile-dictem ${SRC_EL}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${LISPDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${SRC_EL} ${SRC_EL:S/.el$/.elc/} \
		 ${STAGEDIR}${PREFIX}/${LISPDIR}/

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.post.mk>
