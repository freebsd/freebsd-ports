# $FreeBSD$

PORTNAME=	prawn-svg
PORTVERSION=	0.26.0
CATEGORIES=	print rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	SVG renderer for Prawn PDF library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-css_parser>=1.3:textproc/rubygem-css_parser \
		rubygem-prawn>=0.11.1:print/rubygem-prawn

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
