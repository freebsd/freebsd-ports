# Created by: Stephen Montgomery-Smith
# $FreeBSD$

PORTNAME=	naturalmath
PORTVERSION=	0.5
PORTREVISION=	6
CATEGORIES=	math
MASTER_SITES=	http://www.math.missouri.edu/~stephen/naturalmath/

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Script to turn intuitively written math into latex

BROKEN=		unfetchable

USE_TEX=	latex:build dvipsk:build
USES=		shebangfix perl5
SHEBANG_FILES=	naturalmath

OPTIONS_DEFINE=	DOCS

do-build:
	(cd ${WRKSRC}; ./naturalmath tutor.nat; \
		${LOCALBASE}/bin/latex tutor; ${LOCALBASE}/bin/latex tutor; \
		${LOCALBASE}/bin/dvips tutor -o tutor.ps)

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/naturalmath ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/install.html ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/tutor.nat ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/tutor.tex ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/tutor.dvi ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/tutor.ps ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/naturalmath.cgi ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
