# $FreeBSD$

PORTNAME=	sanitize
PORTVERSION=	2.0.6
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	20

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Whitelist based HTML sanitizer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-nokogiri>=1.4.4:textproc/rubygem-nokogiri

PORTSCOUT=	limit:^2\.0

NO_ARCH=	yes
USES=		gem
USE_RUBY=	yes

.include <bsd.port.mk>
