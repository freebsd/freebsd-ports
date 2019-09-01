# Created by: Martin Kammerhofer
# $FreeBSD$

PORTNAME=	auctex
PORTVERSION=	11.90
PORTREVISION=	7
CATEGORIES=	print elisp
MASTER_SITES=	GNU
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Integrated environment for writing LaTeX using GNU Emacs

LICENSE=	GPLv3

.if ${FLAVOR:U} == devel_full || ${FLAVOR:U} == devel_nox
BROKEN=		tex.el:0:0: error: wrong-type-argument: (stringp nil)
.endif

USES=		emacs ghostscript gmake
USE_TEX=	latex texhash
TEXHASHDIRS=	${TEXMFDIR}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-lispdir=${PREFIX}/${EMACS_VERSION_SITE_LISPDIR} \
	--with-auto-dir=${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/auctex/auto \
	--with-texmf-dir=${PREFIX}/${TEXMFDIR}
PORTDOCS=	tex-ref.pdf
INFO=		auctex preview-latex
PLIST_SUB=	TEXMFDIR=${TEXMFDIR}
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS
DOCS_CONFIGURE_ON=	--docdir=${DOCSDIR}
DOCS_CONFIGURE_OFF=	WITHOUT_AUCTEX_DOCSDIR=yes

.include <bsd.port.mk>
