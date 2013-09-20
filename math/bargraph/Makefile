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

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bargraph.pl ${PREFIX}/bin/bargraph

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
.endif
.if !defined (NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${CP} ${WRKSRC}/samples/*.perf  ${WRKSRC}/samples/*.png ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
