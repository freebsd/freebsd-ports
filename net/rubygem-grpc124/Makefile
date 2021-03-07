# $FreeBSD$

PORTNAME=	grpc
PORTVERSION=	1.24.0
PORTREVISION=	3
CATEGORIES=	net rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	124

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby implementation of gRPC

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libcares.so:dns/c-ares \
		libgrpc.so:devel/grpc
RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss \
		rubygem-google-protobuf38>=3.8<4:devel/rubygem-google-protobuf38 \
		rubygem-googleapis-common-protos-types104>=1.0<2:devel/rubygem-googleapis-common-protos-types104

USES=		gem gmake pkgconfig
USE_RUBY=	yes

MAKE_JOBS_UNSAFE=	yes

PORTSCOUT=	limit:^1\.24\.

post-extract:
	@${RM} ${WRKSRC}/Makefile ${WRKSRC}/.yardopts
	@${RM} -r ${WRKSRC}/etc ${WRKSRC}/include ${WRKSRC}/third_party ${WRKSRC}/src/boringssl ${WRKSRC}/src/core

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/src/ruby/lib/grpc.rb
	@${REINPLACE_CMD} -Ee '/s\.files = /s;, "(Makefile|etc|include|third_party|src/boringssl|src/core)[^"]*"\.freeze;;g' ${WRKSRC}/${GEMSPEC}
	@${REINPLACE_CMD} -e '/s\.files = /s|"\.yardopts"\.freeze, ||' ${WRKSRC}/${GEMSPEC}

.include <bsd.port.mk>
