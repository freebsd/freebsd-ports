PORTNAME=	prime
PORTVERSION=	0.1.2
CATEGORIES=	math rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Prime numbers and factorization library

LICENSE=	BSD2CLAUSE RUBY
LICENSE_COMB=	dual
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-forwardable>=0:devel/rubygem-forwardable \
		rubygem-singleton>=0:devel/rubygem-singleton

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
