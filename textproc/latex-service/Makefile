# $FreeBSD$

PORTNAME=	latex
PORTVERSION=	0.1
PORTREVISION=	7
CATEGORIES=	textproc gnustep
MASTER_SITES=	http://www.roard.com/latexservice/download/
PKGNAMESUFFIX=	-service${PKGNAMESUFFIX2}
DISTNAME=	LaTeXService-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	LaTeX service for GNUstep

LICENSE=	GPLv2

USES=		tar:tgz gnustep
USE_GNUSTEP=	back build

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Library/Services/LaTeX.service/LaTeX

.include <bsd.port.mk>
