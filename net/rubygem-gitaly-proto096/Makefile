# $FreeBSD$

PORTNAME=	gitaly-proto
PORTVERSION=	0.96.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	096

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Protobuf specifications and client libraries for Gitaly

LICENSE=	MIT

DEPRECATED=	Obsoleted by update of www/gitlab-ce. Please use net/rubygem-gitaly-proto instead.
EXPIRATION_DATE=	2018-07-31

RUN_DEPENDS=	rubygem-google-protobuf>=3.1:devel/rubygem-google-protobuf \
		rubygem-grpc>=1.10:net/rubygem-grpc

NO_ARCH=	yes
USES=		gem
USE_RUBY=	yes

PORTSCOUT=	limit:^0\.96\.

.include <bsd.port.mk>
