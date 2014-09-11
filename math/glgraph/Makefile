# Created by: ijliao
# $FreeBSD$

PORTNAME=	glgraph
PORTVERSION=	0.2.6
PORTREVISION=	9
CATEGORIES=	math
MASTER_SITES=	http://glgraph.kaosu.ch/downl/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenGL based function grapher

RUN_DEPENDS=	p5-OpenGL>=0:${PORTSDIR}/graphics/p5-OpenGL \
		import:${PORTSDIR}/graphics/ImageMagick

USES=		perl5 shebangfix tar:bzip2
USE_PERL5=	run
SHEBANG_FILES=	${PORTNAME}
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/glgraph
PORTDOCS=	documentation.html

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/glgraph ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/documentation.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
