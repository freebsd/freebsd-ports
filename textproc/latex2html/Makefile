# New ports collection makefile for:	 latex2html
# Date created:		3 May 1998
# Whom:			brett@peloton.physics.montana.edu
#
# $FreeBSD$
#

PORTNAME=	latex2html
PORTVERSION=	2008
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	support/${PORTNAME}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Convert LaTeX documents to HTML

BUILD_DEPENDS=	${LOCALBASE}/bin/latex:${PORTSDIR}/print/teTeX-base \
		${LOCALBASE}/bin/dvips:${PORTSDIR}/print/dvipsk-tetex \
		${LOCALBASE}/bin/anytopnm:${PORTSDIR}/graphics/netpbm
RUN_DEPENDS=	${BUILD_DEPENDS}

CONFLICTS=	ja-latex2html-[0-9]*

USE_PERL5=		yes
USE_GHOSTSCRIPT=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=	--with-perl=${PERL} \
		--disable-gif \
		--shlibdir=${DATADIR} \
		--with-texpath=${PREFIX}/${TEXMFDIR}/tex/latex/html
SUB_FILES=	pkg-message
PLIST_SUB=	TEXMFDIR=${TEXMFDIR} MKTEXLSR=${MKTEXLSR}

MAN1=	latex2html.1

TEXMFDIR=	share/texmf
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
PORTDOCS=	FAQ INSTALL LICENSE README

.include <bsd.port.pre.mk>

post-install:
	${INSTALL_MAN} ${FILESDIR}/latex2html.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
	@${MKTEXLSR} ${PREFIX}/${TEXMFDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
