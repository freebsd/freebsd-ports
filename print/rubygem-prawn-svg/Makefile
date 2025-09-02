PORTNAME=	prawn-svg
PORTVERSION=	0.38.0
CATEGORIES=	print rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	SVG renderer for Prawn PDF library
WWW=		https://github.com/mogest/prawn-svg

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-css_parser>=1.6<2:textproc/rubygem-css_parser \
		rubygem-matrix>=0.4.2<0.5:math/rubygem-matrix \
		rubygem-prawn>=0.11.1<3:print/rubygem-prawn \
		rubygem-rexml>=3.3.9<4:textproc/rubygem-rexml

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
