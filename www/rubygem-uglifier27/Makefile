# $FreeBSD$

PORTNAME=	uglifier
PORTVERSION=	2.7.2
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	27

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Ruby wrapper for UglifyJS JavaScript compressor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-execjs>=0.3.0:devel/rubygem-execjs \
		rubygem-json1>=1.8.0:devel/rubygem-json1

PORTSCOUT=	limit:^2\.7\.

NO_ARCH=	yes
USES=		gem
USE_RUBY=	yes

.include <bsd.port.mk>
