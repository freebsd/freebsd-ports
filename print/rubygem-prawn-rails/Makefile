PORTNAME=	prawn-rails
PORTVERSION=	1.5.0
CATEGORIES=	print rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Prawn Handler for Rails
WWW=		https://github.com/cortiz/prawn-rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-actionview72>=3.1.0:devel/rubygem-actionview72 \
		rubygem-activesupport72>=3.1.0:devel/rubygem-activesupport72 \
		rubygem-prawn>=0:print/rubygem-prawn \
		rubygem-prawn-table>=0:print/rubygem-prawn-table

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
