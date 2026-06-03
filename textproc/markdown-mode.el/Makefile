PORTNAME=	markdown-mode.el
DISTVERSIONPREFIX=	v
DISTVERSION=	2.8
CATEGORIES=	textproc elisp

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Emacs major mode for editing Markdown-formatted text
WWW=		https://jblevins.org/projects/markdown-mode/

LICENSE=	GPLv3+

USES=		emacs gmake

USE_GITHUB=	yes
GH_ACCOUNT=	jrblevin
GH_PROJECT=	markdown-mode

CONFLICTS_INSTALL=	markdown-mode.el-emacs_*

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${EMACS_SITE_LISPDIR}/markdown-mode.el
PORTDOCS=	CHANGES.md CONTRIBUTING.md README.md

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/*.el \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
