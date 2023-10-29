PORTNAME=	bibtool
PORTVERSION=	2.68
CATEGORIES=	textproc print
MASTER_SITES=	TEX/biblio/bibtex/utils/${PORTNAME}
DISTNAME=	BibTool-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command line manipulation of BibTeX files
WWW=		https://ctan.org/tex-archive/biblio/bibtex/utils/bibtool/

LICENSE=	GPLv2+

DEPRECATED=	BROKEN for more than an year
EXPIRATION_DATE=	2023-11-30
BROKEN=		does not build: Failed to load "fontloader" module "basics-gen"

USES=	tex
USE_TEX=	latex:build luatex:build

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-kpathsea
CONFIGURE_ENV=	LOCALBASE=${LOCALBASE}

MAKEFILE=	makefile
INSTALL_TARGET=	install install.man

WRKSRC=		${WRKDIR}/BibTool

PORTDOCS=	bibtool.pdf ref_card.pdf c_lib.pdf

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} 's/bibtex$$/&8/' ${WRKSRC}/doc/Makefile

post-build:
	cd ${WRKSRC} && ${MAKE} doc && ${MAKE} doc

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
