PORTNAME=	tuareg-mode
PORTVERSION=	2.0.8
PORTREVISION=	22
PORTEPOCH=	1
CATEGORIES=	lang elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	michipili@gmail.com
COMMENT=	Emacs major mode for editing Caml code
WWW=		http://tuareg.forge.ocamlcore.org/

LICENSE=	GPLv2

USES=		emacs
USE_GITHUB=	yes
GH_ACCOUNT=	ocaml
GH_PROJECT=	tuareg

OPTIONS_DEFINE=	DOCS
ELISP_FILES=	ocamldebug.el tuareg.el
.for f in ${ELISP_FILES}
PLIST_FILES+=	${EMACS_SITE_LISPDIR}/$f ${EMACS_SITE_LISPDIR}/$fc
.endfor

PORTDOCS=	README.md

do-build:
	(cd ${WRKSRC} && \
		${EMACS_CMD} -batch -q -f batch-byte-compile ${ELISP_FILES})

do-install:
	@${MKDIR} ${STAGEDIR}${EMACS_SITE_LISPDIR}
.for tuareg_mode_f in ${ELISP_FILES}
	${INSTALL_DATA} ${WRKSRC}/${tuareg_mode_f} ${WRKSRC}/${tuareg_mode_f}c \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:C|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
