PORTNAME=	gladtex
DISTVERSION=	1.4.2
CATEGORIES=	textproc math www
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	alven@FreeBSD.org
COMMENT=	Program to replace LaTeX formulas in HTML files with images
WWW=		https://gladtex.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgif.so:graphics/giflib \
		libpng.so:graphics/png

USES=		cmake perl5 shebangfix tex
USE_TEX=	dvipsk:run latex:run

SHEBANG_FILES=	gladtex

CONFLICTS_INSTALL=	py-gladtex

.include <bsd.port.mk>
