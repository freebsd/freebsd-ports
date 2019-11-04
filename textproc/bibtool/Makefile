# Created by: Rong-En Fan <rafan@infor.org>
# $FreeBSD$

PORTNAME=	bibtool
PORTVERSION=	2.67
CATEGORIES=	textproc print
MASTER_SITES=	TEX_CTAN/biblio/bibtex/utils/${PORTNAME}
DISTNAME=	BibTool-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command line manipulation of BibTeX files

LICENSE=	GPLv2+

USE_TEX=	latex:build luatex:build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-kpathsea
CONFIGURE_ENV=	LOCALBASE=${LOCALBASE}
WRKSRC=		${WRKDIR}/BibTool

MAKEFILE=	makefile
INSTALL_TARGET=	install install.man

PORTDOCS=	bibtool.pdf ref_card.pdf c_lib.pdf

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} 's/bibtex$$/&8/' ${WRKSRC}/doc/Makefile

post-build:
	cd ${WRKSRC} && ${MAKE} doc && ${MAKE} doc

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
