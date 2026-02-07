PORTNAME=	thin
PORTVERSION=	2.0.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Fast and simple Ruby web server
WWW=		https://github.com/macournoyer/thin

LICENSE=	GPLv2+ RUBY
LICENSE_COMB=	dual

RUN_DEPENDS=	rubygem-daemons>=1.0.9<2:devel/rubygem-daemons \
		rubygem-eventmachine>=1.0.4<2:devel/rubygem-eventmachine \
		rubygem-logger>=0:devel/rubygem-logger \
		rubygem-rack>=1,3<4,3:www/rubygem-rack

USES=		gem

PLIST_FILES=	bin/thin

.include <bsd.port.mk>
