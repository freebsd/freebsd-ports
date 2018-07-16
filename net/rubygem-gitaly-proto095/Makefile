# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gitaly-proto
PORTVERSION=	0.95.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	095

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Protobuf specifications and client libraries for Gitaly

LICENSE=	MIT

DEPRECATED=	Obsoleted by update of www/gitlab-ce. Please use net/rubygem-gitaly-proto instead.
EXPIRATION_DATE=	2018-07-31

RUN_DEPENDS=	rubygem-google-protobuf>=3.1:devel/rubygem-google-protobuf \
		rubygem-grpc>=1.10:net/rubygem-grpc

PORTSCOUT=	limit:^0\.95\.

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
