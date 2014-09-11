# $FreeBSD$

PORTNAME=	latex
PORTVERSION=	0.1
PORTREVISION=	4
CATEGORIES=	textproc gnustep
MASTER_SITES=	http://www.roard.com/latexservice/download/
PKGNAMESUFFIX=	-service${PKGNAMESUFFIX2}
DISTNAME=	LaTeXService-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	LaTeX service for GNUstep

LICENSE=	GPLv2

USES=		tar:tgz
USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/Local/Library/Services/LaTeX.service/LaTeX

.include <bsd.port.mk>
