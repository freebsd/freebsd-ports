# New ports collection makefile for:	preview-latex (for emacs21)
# Date Created:		27 Jan 2002
# Whom:			Yoichi NAKAYAMA <yoichi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	preview-latex
PORTVERSION=	0.7.8
PORTREVISION=	2
CATEGORIES=	print elisp
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	LaTeX previewer on Emacs

BUILD_DEPENDS=	${LOCALBASE}/${EMACS_SITE_LISPDIR}/auctex/latex.el:${PORTSDIR}/print/auctex \
		${MKTEXLSR}:${PORTSDIR}/print/teTeX-base
RUN_DEPENDS=	${LOCALBASE}/${EMACS_SITE_LISPDIR}/auctex/latex.el:${PORTSDIR}/print/auctex \
		${MKTEXLSR}:${PORTSDIR}/print/teTeX-base

EMACS_PORT_NAME?=	emacs21

INFO=		preview-latex

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-emacs=${EMACS_CMD} \
		--with-lispdir=${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/preview \
		--with-texmf-dir=${PREFIX}/${TEXMFLOCAL} \
		--disable-8bit-test
USE_GHOSTSCRIPT=	yes
PLIST_SUB=	TEXMFLOCAL=${TEXMFLOCAL} MKTEXLSR=${MKTEXLSR}

INFO=	preview-latex
DOCS=	ChangeLog INSTALL PROBLEMS README latex/README-preview RELEASE TODO

TEXMFLOCAL=	share/texmf-local
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
EMACS_PORT_NAME?=	emacs21

pre-everything::
.if !defined(WITH_GHOSTSCRIPT_AFPL) || ${WITH_GHOSTSCRIPT_AFPL} != yes
	@${ECHO_MSG} ""
	@${ECHO_MSG} "      Define WITH_GHOSTSCRIPT_AFPL=yes to use"
	@${ECHO_MSG} "      AFPL Postscript interpreter instead of GNU one"
	@${ECHO_MSG} ""
.endif

post-install:
	${MKTEXLSR}
	${INSTALL_DATA} ${WRKSRC}/preview-latex.el ${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/preview/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
