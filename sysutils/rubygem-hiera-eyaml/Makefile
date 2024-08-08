PORTNAME=	hiera-eyaml
PORTVERSION=	4.1.0
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	Backend for Hiera that provides encryption/decryption for properties
WWW=		https://github.com/voxpupuli/hiera-eyaml

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-highline>=0:devel/rubygem-highline \
		rubygem-optimist>=0:devel/rubygem-optimist

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/eyaml

.include <bsd.port.mk>
