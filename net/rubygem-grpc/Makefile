# $FreeBSD$

PORTNAME=	grpc
PORTVERSION=	1.4.0
PORTREVISION=	2
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	idefix@fechner.net
COMMENT=	Ruby implementation of gRPC

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss \
		grpc>=0:devel/grpc \
		rubygem-google-protobuf>=3.0:devel/rubygem-google-protobuf \
		rubygem-googleauth>=0.5.1:security/rubygem-googleauth

LIB_DEPENDS=	libcares.so:dns/c-ares

BUILD_DEPENDS=	ca_root_nss>=0:security/ca_root_nss \
		grpc>=0:devel/grpc

MAKE_JOBS_UNSAFE=yes

USE_RUBY=	yes
USES=		gem gmake pkgconfig

post-extract:
	@${RM} -r ${WRKSRC}/include ${WRKSRC}/third_party ${WRKSRC}/src/boringssl \
		${WRKSRC}/src/core ${WRKSRC}/Makefile ${WRKSRC}/.yardopts ${WRKSRC}/etc
	@${CP} ${FILESDIR}/grpc.gemspec ${WRKSRC}

.include <bsd.port.mk>
