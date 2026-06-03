PORTNAME=	compat.el
DISTVERSION=	31.0.0.1
CATEGORIES=	misc elisp

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Compatibility library for Emacs Lisp
WWW=		https://github.com/emacs-compat/compat

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		emacs:build gmake makeinfo
USE_GITHUB=	yes
GH_ACCOUNT=	emacs-compat
GH_PROJECT=	compat

ALL_TARGET=	compat.info

CONFLICTS_INSTALL=	compat.el-emacs_*

NO_ARCH=	yes
INFO=		compat
PLIST_FILES=	${ELISP_FILES:S|^|${EMACS_SITE_LISPDIR}/compat/|}
PORTDOCS=	NEWS.org README.md

OPTIONS_DEFINE=	DOCS

ELISP_FILES=	compat-26.el compat-27.el compat-28.el compat-29.el \
		compat-30.el compat-31.el compat-macs.el compat.el

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/compat
	${INSTALL_DATA}  ${ELISP_FILES:C/^/${WRKSRC}\//} \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/compat
	${INSTALL_DATA} ${WRKSRC}/*.info ${STAGEDIR}${PREFIX}/${INFO_PATH}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:C/^/${WRKSRC}\//} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
