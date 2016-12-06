# Created by: Jonathan Weiss (<jw@innerewut.de>)
# $FreeBSD$

PORTNAME=	actionpack
PORTVERSION=	3.2.22.2
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Action Controller and Action View of Rails MVC Framework

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activemodel>=${PORTVERSION}:databases/rubygem-activemodel \
		rubygem-activesupport>=${PORTVERSION}:devel/rubygem-activesupport \
		rubygem-builder>=3.0.0:devel/rubygem-builder \
		rubygem-erubis>=2.7.0:www/rubygem-erubis \
		rubygem-journey>=1.0.4:www/rubygem-journey \
		rubygem-rack-cache>=1.2:www/rubygem-rack-cache \
		rubygem-rack-test>=0.6.1:www/rubygem-rack-test \
		rubygem-rack14>=1.4.5:www/rubygem-rack14 \
		rubygem-sprockets22>=2.2.1:devel/rubygem-sprockets22

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

DEPRECATED=	Upstream support ended
EXPIRATION_DATE=	2017-01-07

.include <bsd.port.mk>
