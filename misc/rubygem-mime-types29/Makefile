# $FreeBSD$

PORTNAME=	mime-types
PORTVERSION=	2.99.3
CATEGORIES=	misc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	29

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby gem which provides a mailcap-like MIME Content-Type lookup

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/Licence.rdoc

DEPRECATED=	Use misc/rubygem-mime-types instead
EXPIRATION_DATE=2019-03-31

RUN_DEPENDS=	rubygem-mime-types-data>=3.2015:misc/rubygem-mime-types-data

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
