# Created by: brett@peloton.physics.montana.edu
# $FreeBSD$

PORTNAME=	latex2html
PORTVERSION=	2008
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	support/${PORTNAME}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Convert LaTeX documents to HTML

BUILD_DEPENDS=	${LOCALBASE}/bin/anytopnm:${PORTSDIR}/graphics/netpbm
RUN_DEPENDS:=	${BUILD_DEPENDS}

CONFLICTS=	ja-latex2html-[0-9]*

USES=		perl5
USE_GHOSTSCRIPT=yes
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

.include <bsd.port.options.mk>

post-install:
	${INSTALL_MAN} ${FILESDIR}/latex2html.1 ${STAGEDIR}${MANPREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
