# $FreeBSD$

PORTNAME=	carrierwave
PORTVERSION=	0.10.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Upload files, map them to a range of ORMs, store on different backends

LICENSE=	MIT

RUN_DEPENDS=	rubygem-activemodel>=3.2.0:${PORTSDIR}/databases/rubygem-activemodel \
		rubygem-activesupport>=3.2.0:${PORTSDIR}/devel/rubygem-activesupport \
		rubygem-json>=1.7:${PORTSDIR}/devel/rubygem-json \
		rubygem-mime-types>=1.16:${PORTSDIR}/misc/rubygem-mime-types

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
