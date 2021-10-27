# Created by: Martin Wilke <miwi@FreeBSD.org>

PORTNAME=	addressable
PORTVERSION=	2.5.2
PORTREVISION=	1
CATEGORIES=	www devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	25

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Replacement for the URI implementation

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-public_suffix>=2.0.2:dns/rubygem-public_suffix

USES=		cpe gem
CPE_VENDOR=	${PORTNAME}_project
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^2\.5

.include <bsd.port.mk>
