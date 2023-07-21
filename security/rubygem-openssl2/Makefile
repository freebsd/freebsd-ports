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

RUN_DEPENDS=	rubygem-ipaddr>=0:net/rubygem-ipaddr

USES=		cpe gem ssl

CPE_VENDOR=	ruby-lang

PORTSCOUT=	limit:^2\.

.include <bsd.port.options.mk>

.if ( ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400092 && ${SSL_DEFAULT} == base ) || ${SSL_DEFAULT:Mopenssl3*}
IGNORE_SSL=	base openssl30 openssl31
IGNORE_SSL_REASON=	Missing upstream support for OpenSSL 3.0.0 and later in this version
.endif

.include <bsd.port.mk>
