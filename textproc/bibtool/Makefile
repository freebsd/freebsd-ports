# Created by: Rong-En Fan <rafan@infor.org>
# $FreeBSD$

PORTNAME=	bibtool
PORTVERSION=	2.48
PORTREVISION=	5
CATEGORIES=	textproc print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	biblio/bibtex/utils/${PORTNAME}
DISTNAME=	BibTool-${PORTVERSION}

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	Command line manipulation of BibTeX files

USE_TEX=	latex:build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-kpathsea
CONFIGURE_ENV=	LOCALBASE=${LOCALBASE}

MAKEFILE=	makefile
INSTALL_TARGET=	install install.man

MAN1=		bibtool.1

TXT_DOCS=	Doc/bibtool.dvi Doc/ref_card.dvi Doc/c_lib.dvi
.if !defined(NOPORTDOCS)
PORTDOCS=	${TXT_DOCS:S/^Doc\///}
.endif

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTDOCS)
	cd ${WRKSRC} && ${MAKE} doc && ${MAKE} doc
	${MKDIR} ${DOCSDIR}
	for f in ${TXT_DOCS}; do \
	  ${INSTALL_MAN} ${WRKSRC}/$$f ${DOCSDIR}; \
	done
.endif

.include <bsd.port.post.mk>
