PORTNAME=	latex2html
PORTVERSION=	2016
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	TEX/obsolete/support/${PORTNAME}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Convert LaTeX documents to HTML
WWW=		https://www.latex2html.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/bin/anytopnm:graphics/netpbm
RUN_DEPENDS:=	${BUILD_DEPENDS}

CONFLICTS=	ja-latex2html

USES=		ghostscript perl5 tex
USE_TEX=	latex dvipsk texhash
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-perl=${PERL} \
		--disable-gif \
		--shlibdir=${DATADIR} \
		--with-texpath=${PREFIX}/${TEXMFDIR}/tex/latex/html \
		--without-mktexlsr
SUB_FILES=	pkg-message
TEXHASHDIRS=	${TEXMFDIR}
PORTDOCS=	FAQ INSTALL README

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_MAN} ${WRKSRC}/latex2html.1 ${STAGEDIR}${PREFIX}/share/man/man1

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
