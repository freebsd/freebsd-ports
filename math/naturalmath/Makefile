# Created by: Stephen Montgomery-Smith
# $FreeBSD$

PORTNAME=	naturalmath
PORTVERSION=	0.5
PORTREVISION=	6
CATEGORIES=	math
MASTER_SITES=	http://www.math.missouri.edu/~stephen/naturalmath/

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Script to turn intuitively written math into latex

USE_PERL5=	yes
USE_TEX=	latex:build dvipsk:build
USES=		shebangfix
SHEBANG_FILES=	naturalmath

do-build:
	(cd ${WRKSRC}; ./naturalmath tutor.nat; \
		${LOCALBASE}/bin/latex tutor; ${LOCALBASE}/bin/latex tutor; \
		${LOCALBASE}/bin/dvips tutor -o tutor.ps)

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/naturalmath ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/install.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/tutor.nat ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/tutor.tex ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/tutor.dvi ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/tutor.ps ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/naturalmath.cgi ${DOCSDIR}
.endif

.include <bsd.port.mk>
