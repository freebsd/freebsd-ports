# $FreeBSD$

PORTNAME=	twitter-text
DISTVERSION=	1.14.7
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	1

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby gem for handling of Twitter texts

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-unf>=0.1.0:textproc/rubygem-unf

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes
PORTSCOUT=	limit:^1\.

.include <bsd.port.mk>
