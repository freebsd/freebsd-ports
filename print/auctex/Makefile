PORTNAME=	auctex
DISTVERSION=	14.2.0
CATEGORIES=	print elisp
MASTER_SITES=	https://elpa.gnu.org/packages/

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Integrated environment for writing LaTeX using GNU Emacs
WWW=		https://www.gnu.org/software/auctex/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		emacs:build ghostscript:run tar:lz tex
USE_TEX=	latex:run

CONFLICTS_INSTALL=	auctex-emacs_*

NO_ARCH=	yes

INFO=		auctex preview-latex
PORTDOCS=	NEWS.org README tex-ref.pdf

OPTIONS_DEFINE=	DOCS

ELISPDIR=	${EMACS_SITE_LISPDIR}/${PORTNAME}

do-build:
	${EMACS_CMD} -q --batch -f loaddefs-generate-batch \
		${WRKSRC}/auctex-autoloads.el ${WRKSRC}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${ELISPDIR}/latex \
		${STAGEDIR}${PREFIX}/${INFO_PATH}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "*.el etc images style" \
		${STAGEDIR}${PREFIX}/${ELISPDIR})
	${INSTALL_DATA} ${WRKSRC}/latex/*.cfg ${WRKSRC}/latex/*.def \
		${WRKSRC}/latex/*.sty ${STAGEDIR}${PREFIX}/${ELISPDIR}/latex
	${INSTALL_DATA} ${WRKSRC}/*.info ${STAGEDIR}${PREFIX}/${INFO_PATH}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS.org ${WRKSRC}/README \
		${WRKSRC}/doc/tex-ref.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
