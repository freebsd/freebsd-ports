# $FreeBSD$

PORTNAME=	omniauth-twitter
PORTVERSION=	1.2.1
CATEGORIES=	net rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	12

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	OmniAuth strategy for Twitter

LICENSE=	MIT

RUN_DEPENDS=	rubygem-json1>=1.3:devel/rubygem-json1 \
		rubygem-omniauth-oauth>=1.1:net/rubygem-omniauth-oauth \
		rubygem-rack>=0:www/rubygem-rack

PORTSCOUT=	limit:1\.2

NO_ARCH=	yes
USES=		gem
USE_RUBY=	yes

.include <bsd.port.mk>
