PORTNAME=	adoc-mode.el
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.0
PORTREVISION=	7
CATEGORIES=	textproc elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	yasu@FreeBSD.org
COMMENT=	Major-mode for editing AsciiDoc files in Emacs
WWW=		https://github.com/bbatsov/adoc-mode

LICENSE=	GPLv2+

USES=		emacs
USE_GITHUB=	yes
GH_ACCOUNT=	bbatsov
GH_PROJECT=	adoc-mode

NO_ARCH=	yes

PLIST_FILES=	${EMACS_VERSION_SITE_LISPDIR}/adoc-mode.el \
		${EMACS_VERSION_SITE_LISPDIR}/adoc-mode.elc
PORTDOCS=	CHANGELOG.md CONTRIBUTING.md README.adoc

OPTIONS_DEFINE=	DOCS

do-build:
	(cd ${WRKSRC} \
	&& ${EMACS_CMD} -Q -batch -L . -f batch-byte-compile adoc-mode.el)

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/adoc-mode.el* \
		${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:C/^/${WRKSRC}\//} \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
