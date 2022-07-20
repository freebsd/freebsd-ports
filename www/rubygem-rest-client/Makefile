PORTNAME=	rest-client
PORTVERSION=	2.1.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Simple Simple HTTP and REST client for Ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-http-accept>=1.7.0:www/rubygem-http-accept \
		rubygem-http-cookie>=1.0.2<2.0:www/rubygem-http-cookie \
		rubygem-mime-types>=1.16<4.0:misc/rubygem-mime-types \
		rubygem-netrc>=0.8<1:net/rubygem-netrc

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/restclient

.include <bsd.port.mk>
