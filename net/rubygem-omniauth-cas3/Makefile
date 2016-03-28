# Created by: Torsten Zuehlsdorff <ports@toco-domains.de>
# $FreeBSD$

PORTNAME=	omniauth-cas3
PORTVERSION=	1.1.3
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	CAS 3.0 Strategy for OmniAuth

LICENSE=	MIT

RUN_DEPENDS=	rubygem-addressable>=2.3:${PORTSDIR}/www/rubygem-addressable \
		rubygem-nokogiri>=1.6.6:${PORTSDIR}/textproc/rubygem-nokogiri \
		rubygem-omniauth>=1.2:${PORTSDIR}/security/rubygem-omniauth

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
