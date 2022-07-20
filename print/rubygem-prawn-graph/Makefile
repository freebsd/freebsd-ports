PORTNAME=	prawn-graph
PORTVERSION=	1.0.6
CATEGORIES=	print rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Draw basic graphs and charts natively in your PDFs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-prawn>=0.11.1:print/rubygem-prawn \
		rubygem-prawn_shapes>=1.2:print/rubygem-prawn_shapes

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
