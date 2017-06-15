# $FreeBSD$

PORTNAME=	rex-rop_builder
PORTVERSION=	0.1.1
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Ruby Exploitation(Rex) library for building ROP chains

RUN_DEPENDS=	rubygem-metasm>=0:devel/rubygem-metasm \
		rubygem-rex-core>=0:security/rubygem-rex-core \
		rubygem-rex-text>=0:security/rubygem-rex-text

NO_ARCH=	yes

USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/msfrop

.include <bsd.port.mk>
