# New ports collection makefile for:	preview-latex (for emacs21)
# Date Created:		27 Jan 2002
# Whom:			Yoichi NAKAYAMA <yoichi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	preview-latex
PORTVERSION=	0.7.7
CATEGORIES=	print elisp
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR= ${PORTNAME}
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	yoichi@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/${EMACS_SITE_LISPDIR}/auctex/latex.el:${PORTSDIR}/print/auctex \
		gs:${PORTSDIR}/print/ghostscript-gnu
RUN_DEPENDS=	${LOCALBASE}/${EMACS_SITE_LISPDIR}/auctex/latex.el:${PORTSDIR}/print/auctex \
		gs:${PORTSDIR}/print/ghostscript-gnu \
		mktexlsr:${PORTSDIR}/print/teTeX

EMACS_PORT_NAME?=	emacs21

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-emacs=${EMACS_CMD} \
		--with-lispdir=${PREFIX}/${EMACS_VERSION_SITE_LISPDIR} \
		--with-texmf=${PREFIX}/share/texmf
CONFIGURE_ARGS+=	--disable-8bit-test

DOCS=	ChangeLog INSTALL PROBLEMS README latex/README-preview RELEASE TODO

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
