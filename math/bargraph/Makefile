# Created by: Dereckson <dereckson@gmail.com>
# $FreeBSD$

PORTNAME=	bargraph
PORTVERSION=	4.7
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	http://bargraphgen.googlecode.com/files/
DISTNAME=	bargraphgen-${PORTVERSION}

MAINTAINER=	dereckson@gmail.com
COMMENT=	Scriptable bar graph generator

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/bin/fig2dev:print/transfig \
		${LOCALBASE}/bin/gnuplot:math/gnuplot

USES=		perl5 shebangfix tar:tgz
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
SHEBANG_FILES=	bargraph.pl

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bargraph.pl ${STAGEDIR}${PREFIX}/bin/bargraph

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} ${WRKSRC}/samples/*.perf  ${WRKSRC}/samples/*.png ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
