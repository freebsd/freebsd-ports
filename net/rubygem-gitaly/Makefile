# $FreeBSD$

PORTNAME=	gitaly
PORTVERSION=	1.65.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Auto-generated gRPC client for gitaly

LICENSE=	MIT

#BUILD_DEPENDS=	rubygem-bundler>=1.12:sysutils/rubygem-bundler \
#		rubygem-rake>=10.0:devel/rubygem-rake
RUN_DEPENDS=	rubygem-grpc>=1.0<2.0:net/rubygem-grpc \
		gitaly>=0.82.0:devel/gitaly

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
