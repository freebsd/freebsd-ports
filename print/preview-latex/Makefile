# New ports collection makefile for:	preview-latex (for emacs21)
# Date Created:		27 Jan 2002
# Whom:			Yoichi NAKAYAMA <yoichi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	preview-latex
PORTVERSION=	0.7.8
PORTREVISION=	1
CATEGORIES=	print elisp
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	LaTeX previewer on Emacs

USE_GHOSTSCRIPT=	yes

BUILD_DEPENDS=	${LOCALBASE}/${EMACS_SITE_LISPDIR}/auctex/latex.el:${PORTSDIR}/print/auctex
RUN_DEPENDS=	${LOCALBASE}/${EMACS_SITE_LISPDIR}/auctex/latex.el:${PORTSDIR}/print/auctex \
		mktexlsr:${PORTSDIR}/print/teTeX

EMACS_PORT_NAME?=	emacs21

INFO=		preview-latex

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-emacs=${EMACS_CMD} \
		--with-lispdir=${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/preview \
		--with-texmf=${PREFIX}/share/texmf
CONFIGURE_ARGS+=	--disable-8bit-test

DOCS=	ChangeLog INSTALL PROBLEMS README latex/README-preview RELEASE TODO

pre-everything::
.if !defined(WITH_GHOSTSCRIPT_AFPL) || ${WITH_GHOSTSCRIPT_AFPL} != yes
	@${ECHO_MSG} ""
	@${ECHO_MSG} "      Define WITH_GHOSTSCRIPT_AFPL=yes to use"
	@${ECHO_MSG} "      AFPL Postscript interpreter instead of GNU one"
	@${ECHO_MSG} ""
.endif

post-install:
	mktexlsr
	${INSTALL_DATA} ${WRKSRC}/preview-latex.el ${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/preview/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
