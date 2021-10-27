PORTNAME=	openssl
PORTVERSION=	2.2.1
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby gem that wraps around the OpenSSL library

LICENSE=	BSD2CLAUSE RUBY
LICENSE_COMB=	dual
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/BSDL
LICENSE_FILE_RUBY=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-ipaddr>=0:net/rubygem-ipaddr

USES=		cpe gem ssl
USE_RUBY=	yes

CPE_VENDOR=	ruby-lang

.include <bsd.port.mk>
