# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	thin
PORTVERSION=	1.7.2
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Fast and simple Ruby web server

LICENSE=	BSD2CLAUSE RUBY
LICENSE_COMB=	dual

RUN_DEPENDS=	rubygem-daemons>=1.0.9<2:devel/rubygem-daemons \
		rubygem-eventmachine>=1.0.4<2:devel/rubygem-eventmachine \
		rubygem-rack16>=1<3:www/rubygem-rack16

USES=		gem
USE_RUBY=	yes

PLIST_FILES=	bin/thin

.include <bsd.port.mk>
