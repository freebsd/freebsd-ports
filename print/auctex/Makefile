PORTNAME=	auctex
DISTVERSION=	13.3
PORTREVISION=	3
CATEGORIES=	print elisp
MASTER_SITES=	GNU

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Integrated environment for writing LaTeX using GNU Emacs
WWW=		https://www.gnu.org/software/auctex/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		emacs:build ghostscript gmake tex
USE_TEX=	latex texhash

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-lispdir=${PREFIX}/${EMACS_SITE_LISPDIR} \
	--with-auto-dir=${PREFIX}/${EMACS_SITE_LISPDIR}/auctex/auto \
	--with-texmf-dir=${PREFIX}/${TEXMFDIR}

CONFLICTS_INSTALL=	auctex-emacs_*

NO_ARCH=	yes
SUB_FILES=	pkg-message

INFO=		auctex preview-latex
PORTDOCS=	tex-ref.pdf

OPTIONS_DEFINE=	DOCS
DOCS_CONFIGURE_ON=	--docdir=${DOCSDIR}
DOCS_CONFIGURE_OFF=	WITHOUT_AUCTEX_DOCSDIR=yes

TEXHASHDIRS=	${TEXMFDIR}

post-install:
	@${FIND} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/auctex \
		-name "*.elc" -delete

.include <bsd.port.mk>
