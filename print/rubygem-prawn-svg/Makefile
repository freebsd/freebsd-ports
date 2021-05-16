PORTNAME=	prawn-svg
PORTVERSION=	0.32.0
CATEGORIES=	print rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	SVG renderer for Prawn PDF library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-css_parser>=1.6<2:textproc/rubygem-css_parser \
		rubygem-prawn>=0.11.1<3:print/rubygem-prawn \
		rubygem-rexml>=3.2<4:textproc/rubygem-rexml

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
