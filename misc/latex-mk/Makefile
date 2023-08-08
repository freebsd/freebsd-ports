PORTNAME=	latex-mk
PORTVERSION=	2.1
PORTREVISION=	5
CATEGORIES=	misc print
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Collection of makefile and scripts for LaTeX documents
WWW=		http://latex-mk.sourceforge.net/

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	texi2dvi:print/texinfo

USES=		gmake tex
USE_TEX=	latex
GNU_CONFIGURE=	yes

INFO=		latex-mk

NO_ARCH=	yes

.include <bsd.port.mk>
