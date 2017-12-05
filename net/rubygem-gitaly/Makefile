# $FreeBSD$

PORTNAME=	gitaly
PORTVERSION=	0.14.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	idefix@fechner.net
COMMENT=	Auto-generated gRPC client for gitaly

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/ruby/LICENSE.txt

BUILD_DEPENDS=	rubygem-bundler>=1.12:sysutils/rubygem-bundler \
		rubygem-rake>=10.0:devel/rubygem-rake
RUN_DEPENDS=	rubygem-google-protobuf>=3.4.0.2:devel/rubygem-google-protobuf \
		rubygem-grpc>=1.0:net/rubygem-grpc \
		gitaly>=0.11.2:devel/gitaly

NO_ARCH=	yes
USES=		gem
USE_RUBY=	yes

.include <bsd.port.mk>
