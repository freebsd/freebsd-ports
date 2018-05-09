# $FreeBSD$

PORTNAME=	asset_sync
PORTVERSION=	2.2.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	220

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Synchronizes Assets between Rails and S3

LICENSE=	MIT

RUN_DEPENDS=	rubygem-activemodel4>=4.1.0:databases/rubygem-activemodel4 \
		rubygem-fog-core>=0:devel/rubygem-fog-core \
		rubygem-mime-types>=2.99:misc/rubygem-mime-types \
		rubygem-unf>=0:textproc/rubygem-unf

CONFLICTS_INSTALL=	asset_sync

PORTSCOUT=	limit:^2\.2\.

USES=		gem
NO_ARCH=	yes
USE_RUBY=	yes

.include <bsd.port.mk>
