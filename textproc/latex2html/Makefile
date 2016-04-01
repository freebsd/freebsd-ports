# Created by: brett@peloton.physics.montana.edu
# $FreeBSD$

PORTNAME=	latex2html
PORTVERSION=	2008
PORTREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	TEX_CTAN/support/${PORTNAME}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Convert LaTeX documents to HTML

BUILD_DEPENDS=	${LOCALBASE}/bin/anytopnm:graphics/netpbm
RUN_DEPENDS:=	${BUILD_DEPENDS}

CONFLICTS=	ja-latex2html-[0-9]*

USES=		ghostscript perl5
USE_TEX=	latex dvipsk texhash
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-perl=${PERL} \
		--disable-gif \
		--shlibdir=${DATADIR} \
		--with-texpath=${PREFIX}/${TEXMFDIR}/tex/latex/html \
		--without-mktexlsr
SUB_FILES=	pkg-message
PLIST_SUB=	TEXMFDIR=${TEXMFDIR}
TEXHASHDIRS=	${TEXMFDIR}
PORTDOCS=	FAQ INSTALL LICENSE README

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_MAN} ${FILESDIR}/latex2html.1 ${STAGEDIR}${MANPREFIX}/man/man1

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
