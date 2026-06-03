PORTNAME=	tuareg-mode
PORTVERSION=	2.0.8
PORTREVISION=	23
PORTEPOCH=	1
CATEGORIES=	lang elisp

MAINTAINER=	michipili@gmail.com
COMMENT=	Emacs major mode for editing Caml code
WWW=		http://tuareg.forge.ocamlcore.org/

LICENSE=	GPLv2

USES=		emacs
USE_GITHUB=	yes
GH_ACCOUNT=	ocaml
GH_PROJECT=	tuareg

CONFLICTS_INSTALL=	tuareg-mode-emacs_*

NO_ARCH=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS
ELISP_FILES=	ocamldebug.el tuareg.el
.for f in ${ELISP_FILES}
PLIST_FILES+=	${EMACS_SITE_LISPDIR}/$f
.endfor

PORTDOCS=	README.md

do-install:
	@${MKDIR} ${STAGEDIR}${EMACS_SITE_LISPDIR}
.for tuareg_mode_f in ${ELISP_FILES}
	${INSTALL_DATA} ${WRKSRC}/${tuareg_mode_f} \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:C|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
