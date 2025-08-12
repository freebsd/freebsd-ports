PORTNAME=	grpc
PORTVERSION=	1.74.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby implementation of gRPC
WWW=		https://github.com/grpc/grpc/tree/master/src/ruby

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libgrpc.so:devel/grpc
RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss \
		rubygem-google-protobuf>=3.25<5.0:devel/rubygem-google-protobuf \
		rubygem-googleapis-common-protos-types>=1.0<2:devel/rubygem-googleapis-common-protos-types

USES=		cpe gem gmake pkgconfig

MAKE_JOBS_UNSAFE=	yes

post-patch:
	@${RM} ${WRKSRC}/Makefile ${WRKSRC}/.yardopts
	@${RM} -r ${WRKSRC}/etc ${WRKSRC}/include ${WRKSRC}/third_party ${WRKSRC}/src/boringssl ${WRKSRC}/src/core
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/src/ruby/lib/grpc.rb
	@${REINPLACE_CMD} -Ee '/s\.files = /s;, "(Makefile|etc|include|third_party|src/boringssl|src/core)[^"]*"\.freeze;;g' ${WRKSRC}/${GEMSPEC}
	@${REINPLACE_CMD} -e '/s\.files = /s|"\.yardopts"\.freeze, ||' ${WRKSRC}/${GEMSPEC}

.include <bsd.port.mk>
