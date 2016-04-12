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

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	p5-OpenGL>=0:graphics/p5-OpenGL \
		import:graphics/ImageMagick

USES=		perl5 shebangfix tar:bzip2
USE_PERL5=	run
SHEBANG_FILES=	${PORTNAME}
NO_BUILD=	yes
NO_ARCH=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/glgraph
PORTDOCS=	documentation.html

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/glgraph ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/documentation.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
