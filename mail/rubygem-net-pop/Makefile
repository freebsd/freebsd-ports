# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	net-pop
PORTVERSION=	0.1.1
PORTREVISION=	1
CATEGORIES=	mail rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby client library for POP3

LICENSE=	BSD2CLAUSE RUBY
LICENSE_COMB=	dual
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-digest>=0:security/rubygem-digest \
		rubygem-net-protocol>=0:net/rubygem-net-protocol \
		rubygem-timeout>=0:devel/rubygem-timeout

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
