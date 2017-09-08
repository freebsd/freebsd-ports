# Created by: Torsten Zuehlsdorff <tz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	azure
PORTVERSION=	0.7.10
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Microsoft Azure Client Library for Ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-addressable>=2.3:www/rubygem-addressable \
		rubygem-azure-core>=0.1:net/rubygem-azure-core \
		rubygem-faraday>=0.9:www/rubygem-faraday \
		rubygem-faraday_middleware>=0.10:www/rubygem-faraday_middleware \
		rubygem-mime-types>=1:misc/rubygem-mime-types \
		rubygem-nokogiri>=1.6:textproc/rubygem-nokogiri \
		rubygem-systemu>=2.6:devel/rubygem-systemu \
		rubygem-thor>=0.19:devel/rubygem-thor

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/pfxer

.include <bsd.port.mk>
