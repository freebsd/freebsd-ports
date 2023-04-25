PORTNAME=	openssl
PORTVERSION=	2.2.3
CATEGORIES=	security rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	2

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Wrap the OpenSSL library
WWW=		https://github.com/ruby/openssl

LICENSE=	BSD2CLAUSE RUBY
LICENSE_COMB=	dual
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/BSDL
LICENSE_FILE_RUBY=	${WRKSRC}/LICENSE.txt

BROKEN_SSL=	openssl30 openssl31
BROKEN_SSL_REASON=	Requires OpenSSL >= 1.0.1, < 3.0.0

RUN_DEPENDS=	rubygem-ipaddr>=0:net/rubygem-ipaddr

USES=		cpe gem ssl

CPE_VENDOR=	ruby-lang

PORTSCOUT=	limit:^2\.

.include <bsd.port.mk>
