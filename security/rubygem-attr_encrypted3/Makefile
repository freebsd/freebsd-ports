PORTNAME=	attr_encrypted
PORTVERSION=	3.1.0
CATEGORIES=	security rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	3

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Generates attr_accessors that encrypt and decrypt attributes
WWW=		https://github.com/attr-encrypted/attr_encrypted

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-encryptor>=3.0.0<3.1:security/rubygem-encryptor

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^3\.1

.include <bsd.port.mk>
