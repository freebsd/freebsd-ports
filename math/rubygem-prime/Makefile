PORTNAME=	prime
PORTVERSION=	0.1.4
CATEGORIES=	math rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Prime numbers and factorization library
WWW=		https://github.com/ruby/prime

LICENSE=	BSD2CLAUSE RUBY
LICENSE_COMB=	dual
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/BSDL
LICENSE_FILE_RUBY=	${WRKSRC}/COPYING

RUN_DEPENDS=	rubygem-forwardable>=0:devel/rubygem-forwardable \
		rubygem-singleton>=0:devel/rubygem-singleton

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
