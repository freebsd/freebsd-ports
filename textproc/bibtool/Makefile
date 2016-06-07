# Created by: Rong-En Fan <rafan@infor.org>
# $FreeBSD$

PORTNAME=	bibtool
PORTVERSION=	2.64
CATEGORIES=	textproc print
MASTER_SITES=	TEX_CTAN/biblio/bibtex/utils/${PORTNAME}
DISTNAME=	BibTool-${PORTVERSION}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Command line manipulation of BibTeX files

USE_TEX=	latex:build luatex:build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-kpathsea
CONFIGURE_ENV=	LOCALBASE=${LOCALBASE}
WRKSRC=		${WRKDIR}/BibTool

MAKEFILE=	makefile
INSTALL_TARGET=	install install.man

PORTDOCS=	bibtool.pdf ref_card.pdf c_lib.pdf

post-patch:
	${REINPLACE_CMD} 's/bibtex$$/&8/' ${WRKSRC}/doc/Makefile

post-build:
	cd ${WRKSRC} && ${MAKE} doc && ${MAKE} doc

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_MAN} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
