# $FreeBSD$

PORTNAME=	hiera-eyaml
PORTVERSION=	2.1.0
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	freebsd@rig.rain.com
COMMENT=	Backend for Hiera that provides encryption/decryption for properties

LICENSE=	MIT

RUN_DEPENDS=	rubygem-trollop>=2.0:devel/rubygem-trollop \
		rubygem-highline>=1.7:devel/rubygem-highline

PLIST_FILES=	bin/eyaml

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
