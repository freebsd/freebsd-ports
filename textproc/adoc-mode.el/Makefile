PORTNAME=	adoc-mode.el
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.0
CATEGORIES=	textproc elisp

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Major-mode for editing AsciiDoc files in Emacs
WWW=		https://github.com/bbatsov/adoc-mode

LICENSE=	GPLv2+

USES=		emacs:build
USE_GITHUB=	yes
GH_ACCOUNT=	bbatsov
GH_PROJECT=	adoc-mode

CONFLICTS_INSTALL=	adoc-mode.el-emacs_*

NO_ARCH=	yes

PLIST_FILES=	${EMACS_SITE_LISPDIR}/adoc-mode/adoc-mode-autoloads.el \
		${EMACS_SITE_LISPDIR}/adoc-mode/adoc-mode-image.el \
		${EMACS_SITE_LISPDIR}/adoc-mode/adoc-mode-tempo.el \
		${EMACS_SITE_LISPDIR}/adoc-mode/adoc-mode.el

PORTDOCS=	CHANGELOG.md CONTRIBUTING.md README.adoc

OPTIONS_DEFINE=	DOCS

do-build:
	${EMACS_CMD} --batch -q --no-site-file \
		--eval "(make-directory-autoloads \"${WRKSRC}/\" \
		\"${WRKSRC}/adoc-mode-autoloads.el\")"

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/adoc-mode
	${INSTALL_DATA} ${WRKSRC}/adoc-mode*.el \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/adoc-mode

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:C/^/${WRKSRC}\//} \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
