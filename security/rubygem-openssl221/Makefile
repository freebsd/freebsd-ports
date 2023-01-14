PORTNAME=	openssl
PORTVERSION=	2.2.1
CATEGORIES=	security rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	221

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Wrap the OpenSSL library
WWW=		https://github.com/ruby/openssl

LICENSE=	BSD2CLAUSE RUBY
LICENSE_COMB=	dual
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/BSDL
LICENSE_FILE_RUBY=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-ipaddr122>=0:net/rubygem-ipaddr122

USES=		cpe gem ssl

CPE_VENDOR=	ruby-lang

PORTSCOUT=	limit:^2\.2\.1

.include <bsd.port.mk>
