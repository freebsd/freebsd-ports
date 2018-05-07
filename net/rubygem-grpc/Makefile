# $FreeBSD$

PORTNAME=	grpc
PORTVERSION=	1.10.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	idefix@fechner.net
COMMENT=	Ruby implementation of gRPC

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libcares.so:dns/c-ares \
		libgrpc.so:devel/grpc
RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss \
		rubygem-google-protobuf>=3.1:devel/rubygem-google-protobuf \
		rubygem-googleauth>=0.5.1:security/rubygem-googleauth \
		rubygem-googleapis-common-protos-types>=1.0.0:devel/rubygem-googleapis-common-protos-types

MAKE_JOBS_UNSAFE=	yes

USES=		gem gmake pkgconfig
USE_RUBY=	yes

post-extract:
	@${RM} -r ${WRKSRC}/include ${WRKSRC}/third_party ${WRKSRC}/src/boringssl \
		${WRKSRC}/src/core ${WRKSRC}/Makefile ${WRKSRC}/.yardopts ${WRKSRC}/etc

post-patch:
	@${REINPLACE_CMD} 's,%%LOCALBASE%%,${LOCALBASE},' ${WRKSRC}/src/ruby/lib/grpc.rb
	@${REINPLACE_CMD} -E '/s\.files = /s;, "(Makefile|etc|include|third_party|src/boringssl|src/core)[^"]*"\.freeze;;g' \
		${WRKSRC}/grpc.gemspec
	@${REINPLACE_CMD} -e '/s\.files = /s;"\.yardopts"\.freeze, ;;' ${WRKSRC}/grpc.gemspec

.include <bsd.port.mk>
