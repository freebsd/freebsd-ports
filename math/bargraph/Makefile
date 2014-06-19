# Created by: Dereckson <dereckson@gmail.com>
# $FreeBSD$

PORTNAME=	bargraph
PORTVERSION=	4.7
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://bargraphgen.googlecode.com/files/
DISTNAME=	bargraphgen-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	dereckson@gmail.com
COMMENT=	Scriptable bar graph generator

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/bin/fig2dev:${PORTSDIR}/print/transfig \
		${LOCALBASE}/bin/gnuplot:${PORTSDIR}/math/gnuplot

USES=		perl5 shebangfix
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
SHEBANG_FILES=	bargraph.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bargraph.pl ${STAGEDIR}${PREFIX}/bin/bargraph

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
.endif
.if !defined (NOPORTEXAMPLES)
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} ${WRKSRC}/samples/*.perf  ${WRKSRC}/samples/*.png ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
