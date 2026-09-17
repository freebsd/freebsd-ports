PORTNAME=	grpc_reflection
PORTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	GRPC Server Reflection Protocol for Ruby
WWW=		https://github.com/y-yagi/grpc_reflection

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-google-protobuf-gitlab>=4.31.0:devel/rubygem-google-protobuf-gitlab \
		rubygem-grpc-gitlab>=0:net/rubygem-grpc-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
