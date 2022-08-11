PORTNAME=	compat.el
DISTVERSION=	28.1.2.0
CATEGORIES=	misc elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	yasu@FreeBSD.org
COMMENT=	Compatibility library for Emacs Lisp

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		emacs gmake makeinfo
USE_GITHUB=	yes
GH_ACCOUNT=	phikal

ALL_TARGET=	all compat.info

NO_ARCH=	yes

INFO=		compat
PORTDOCS=	MANUAL NEWS.org README.md

OPTIONS_DEFINE=	DOCS

ELISP_FILES=	compat-24.el compat-24.elc compat-25.el compat-25.elc \
		compat-26.el compat-26.elc compat-27.el compat-27.elc \
		compat-28.el compat-28.elc compat-font-lock.el \
		compat-font-lock.elc compat-help.el compat-help.elc \
		compat-macs.el compat-macs.elc compat.el compat.elc

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/compat
	${INSTALL_DATA}  ${ELISP_FILES:C/^/${WRKSRC}\//} \
		${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/compat
	${INSTALL_DATA} ${WRKSRC}/*.info ${STAGEDIR}${PREFIX}/${INFO_PATH}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:C/^/${WRKSRC}\//} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
