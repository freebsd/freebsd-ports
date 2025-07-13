PORTNAME=	dictem
PORTVERSION=	1.0.4
PORTREVISION=	23
CATEGORIES=	textproc net elisp
MASTER_SITES=	SF/dictem/dictem/dictem-${PORTVERSION}
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	max.n.boyarov@gmail.com
COMMENT=	DICT protocol client for [X]Emacs
WWW=		https://sourceforge.net/projects/dictem/

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/bin/dict:textproc/dict

USES=		emacs

NO_ARCH=	yes

SRC_EL=		dictem.el dictem-lingvo-dsl.el dictem-elisp.el

.for f in ${SRC_EL}
PLIST_FILES+=	${LISPDIR}/${f} ${LISPDIR}/${f}c
.endfor

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
PORTDOCS=	README AUTHORS NEWS COPYING TODO

LISPDIR=	${EMACS_VERSION_SITE_LISPDIR}/dictem

OPTIONS_DEFINE=	DOCS

do-build:
	(cd ${WRKSRC} && ${EMACS_CMD} --no-site-file --no-init-file -batch \
		-l compile.el -f compile-dictem ${SRC_EL})

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${LISPDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${SRC_EL} ${SRC_EL:S/.el$/.elc/} \
		 ${STAGEDIR}${PREFIX}/${LISPDIR}/)

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
