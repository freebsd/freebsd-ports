# $FreeBSD$

PORTNAME=	gitaly-proto
PORTVERSION=	0.84.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	084

MAINTAINER=	idefix@fechner.net
COMMENT=	Protobuf specifications and client libraries for Gitaly

LICENSE=	MIT

RUN_DEPENDS=	rubygem-google-protobuf>=3.1:devel/rubygem-google-protobuf \
		rubygem-grpc>=1.0:net/rubygem-grpc

CONFLICTS_INSTALL=	rubygem-gitaly-proto

PORTSCOUT=	limit:^0\.84\.

NO_ARCH=	yes
USES=		gem
USE_RUBY=	yes

.include <bsd.port.mk>
