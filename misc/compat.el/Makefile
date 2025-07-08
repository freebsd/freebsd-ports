PORTNAME=	compat.el
DISTVERSION=	30.1.0.1
CATEGORIES=	misc elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	yasu@FreeBSD.org
COMMENT=	Compatibility library for Emacs Lisp
WWW=		https://github.com/emacs-compat/compat

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		emacs gmake makeinfo
USE_GITHUB=	yes
GH_ACCOUNT=	emacs-compat
GH_PROJECT=	compat

ALL_TARGET=	all compat.info

NO_ARCH=	yes

INFO=		compat
PORTDOCS=	NEWS.org README.md

OPTIONS_DEFINE=	DOCS

ELISP_FILES=	compat-25.el compat-25.elc compat-26.el compat-26.elc \
		compat-27.el compat-27.elc compat-28.el compat-28.elc \
		compat-29.el compat-29.elc compat-30.el compat-30.elc \
		compat-macs.el compat.el compat.elc

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/compat
	${INSTALL_DATA}  ${ELISP_FILES:C/^/${WRKSRC}\//} \
		${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/compat
	${INSTALL_DATA} ${WRKSRC}/*.info ${STAGEDIR}${PREFIX}/${INFO_PATH}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:C/^/${WRKSRC}\//} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
