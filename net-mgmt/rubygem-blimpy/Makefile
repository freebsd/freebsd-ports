PORTNAME=	blimpy
PORTVERSION=	0.6.7
CATEGORIES=	net-mgmt rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Tool for managing a fleet of machines in the cloud
WWW=		https://github.com/rtyler/blimpy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-fog>=0:devel/rubygem-fog \
		rubygem-minitar>=0:archivers/rubygem-minitar \
		rubygem-thor>=0:devel/rubygem-thor

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/blimpy

.include <bsd.port.mk>
