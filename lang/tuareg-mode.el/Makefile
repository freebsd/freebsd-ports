# Created by: dd
# $FreeBSD$

PORTNAME=	tuareg-mode
PORTVERSION=	2.0.8
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	lang elisp
MASTER_SITES=	GH

MAINTAINER=	michipili@gmail.com
COMMENT=	Emacs major mode for editing Caml code

LICENSE=	GPLv2

USE_EMACS=	yes
USE_GITHUB=	yes

GH_ACCOUNT=	ocaml
GH_PROJECT=	tuareg
GH_COMMIT=	62f6854

OPTIONS_DEFINE=	DOCS
ELISP_FILES=	ocamldebug.el tuareg.el
.for f in ${ELISP_FILES}
PLIST_FILES+=	%%EMACS_SITE_LISPDIR%%/$f %%EMACS_SITE_LISPDIR%%/$fc
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
