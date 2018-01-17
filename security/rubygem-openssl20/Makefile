# $FreeBSD$

PORTNAME=	openssl
PORTVERSION=	2.0.7
CATEGORIES=	security rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	20

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby gem that wraps around the OpenSSL library

LICENSE=	BSD2CLAUSE RUBY
LICENSE_COMB=	dual
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/BSDL
LICENSE_FILE_RUBY=	${WRKSRC}/LICENSE.txt

DEPRECATED=	Use security/rubygem-openssl instead
EXPIRATION_DATE=2018-01-31

PORTSCOUT=	limit:^2\.0\.

USE_RUBY=	yes
USES=		gem ssl

.include <bsd.port.mk>
