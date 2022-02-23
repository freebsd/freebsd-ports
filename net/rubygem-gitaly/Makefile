PORTNAME=	gitaly
PORTVERSION=	14.8.0.pre.rc1
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Auto-generated gRPC client for gitaly

LICENSE=	MIT

RUN_DEPENDS=	rubygem-grpc142>=1.0<2.0:net/rubygem-grpc142 \
		gitaly>=14.8:devel/gitaly

USES=		cpe gem
USE_RUBY=	yes

NO_ARCH=	yes

CPE_VENDOR=	gitlab

.include <bsd.port.mk>
