# ex:ts=8
# Ports collection makefile for:	glgraph
# Date created:			Jan 7, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	glgraph
PORTVERSION=	0.2.6
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://glgraph.kaosu.ch/downl/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An OpenGL based function grapher

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/OpenGL.pm:${PORTSDIR}/graphics/p5-OpenGL \
		${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes \
		import:${PORTSDIR}/graphics/ImageMagick

USE_BZIP2=	yes
USE_PERL5_RUN=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/glgraph ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/documentation.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
