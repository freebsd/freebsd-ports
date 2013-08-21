# Created by: Max N. Boyarov <m.boyarov@gmail.com>
# $FreeBSD$

PORTNAME=	dictem
PORTVERSION=	1.0.4
CATEGORIES=	textproc net elisp
MASTER_SITES=	SF/dictem/dictem/dictem-${PORTVERSION}
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	max.n.boyarov@gmail.com
COMMENT=	DictEm is a dict client for [X]Emacs

RUN_DEPENDS=	${LOCALBASE}/bin/dict:${PORTSDIR}/textproc/dict

USE_EMACS=	yes

SRC_EL=		dictem.el dictem-lingvo-dsl.el dictem-elisp.el

.for f in ${SRC_EL}
PLIST_FILES+=	${LISPDIR}/${f} \
		${LISPDIR}/${f:S/.el$/.elc/}
.endfor
PLIST_DIRS+=	${LISPDIR}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
PORTDOCS+=	README AUTHORS NEWS COPYING TODO

.include <bsd.port.pre.mk>

.if ${EMACS_NAME} == "xemacs"
LISPDIR=	${EMACS_LIBDIR}/site-packages/lisp/dictem
.else
LISPDIR=	${EMACS_VERSION_SITE_LISPDIR}/dictem
.endif

do-build:
.for f in ${SRC_EL}
	${EMACS_CMD} --no-site-file --no-init-file \
		-batch -L ${WRKSRC} \
		-f batch-byte-compile ${WRKSRC}/${f}
.endfor

do-install:
	${MKDIR} ${PREFIX}/${LISPDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${SRC_EL} ${SRC_EL:S/.el$/.elc/} \
		 ${PREFIX}/${LISPDIR}/

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
