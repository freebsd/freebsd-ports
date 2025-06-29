PORTNAME=	rdf
PORTVERSION=	3.3.3
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Pure-Ruby library for working with RDF data
WWW=		https://ruby-rdf.github.io/rdf/ \
		https://github.com/ruby-rdf/rdf

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/UNLICENSE

RUN_DEPENDS=	rubygem-bcp47_spec>=0.2<1:devel/rubygem-bcp47_spec \
		rubygem-bigdecimal>=3.1.5<4:math/rubygem-bigdecimal \
		rubygem-link_header>=0.0.8<1:www/rubygem-link_header \
		rubygem-logger>=1.5<2:devel/rubygem-logger \
		rubygem-ostruct>=0.6<1:devel/rubygem-ostruct

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/rdf

.include <bsd.port.mk>
