# ex:ts=8
# Ports collection makefile for:	glgraph
# Date created:			Jan 7, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	glgraph
PORTVERSION=	0.2.6
PORTREVISION=	7
CATEGORIES=	math
MASTER_SITES=	http://glgraph.kaosu.ch/downl/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An OpenGL based function grapher

RUN_DEPENDS=	p5-OpenGL>=0:${PORTSDIR}/graphics/p5-OpenGL \
		import:${PORTSDIR}/graphics/ImageMagick

USES=		perl5
USE_BZIP2=	yes
USE_PERL5=	run
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/glgraph ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/documentation.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
