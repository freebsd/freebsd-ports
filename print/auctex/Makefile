PORTNAME=	auctex
DISTVERSION=	13.3
PORTREVISION=	2
CATEGORIES=	print elisp
MASTER_SITES=	GNU
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Integrated environment for writing LaTeX using GNU Emacs
WWW=		https://www.gnu.org/software/auctex/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		emacs ghostscript gmake tex
USE_TEX=	latex texhash

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-lispdir=${PREFIX}/${EMACS_VERSION_SITE_LISPDIR} \
	--with-auto-dir=${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/auctex/auto \
	--with-texmf-dir=${PREFIX}/${TEXMFDIR}

NO_ARCH=	yes
SUB_FILES=	pkg-message

INFO=		auctex preview-latex
PORTDOCS=	tex-ref.pdf

OPTIONS_DEFINE=	DOCS
DOCS_CONFIGURE_ON=	--docdir=${DOCSDIR}
DOCS_CONFIGURE_OFF=	WITHOUT_AUCTEX_DOCSDIR=yes

TEXHASHDIRS=	${TEXMFDIR}

.include <bsd.port.mk>
