# $FreeBSD$

PORTNAME=	hipchat
PORTVERSION=	1.5.4
CATEGORIES=	net-im rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	15

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Ruby library to interact with HipChat

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-httparty>=0:www/rubygem-httparty \
		rubygem-mimemagic>=0:misc/rubygem-mimemagic

PORTSCOUT=	limit:^1\.5

NO_ARCH=	yes
USES=		gem
USE_RUBY=	yes

.include <bsd.port.mk>
