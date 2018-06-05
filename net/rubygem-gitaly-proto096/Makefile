# $FreeBSD$

PORTNAME=	gitaly-proto
PORTVERSION=	0.96.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	096

MAINTAINER=	mfechner@freebsd.org
COMMENT=	Protobuf specifications and client libraries for Gitaly

LICENSE=	MIT

RUN_DEPENDS=	rubygem-google-protobuf>=3.1:devel/rubygem-google-protobuf \
		rubygem-grpc>=1.10:net/rubygem-grpc

NO_ARCH=	yes
USES=		gem
USE_RUBY=	yes

PORTSCOUT=	limit:^0\.96\.

.include <bsd.port.mk>
