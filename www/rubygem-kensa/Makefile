# $FreeBSD$

PORTNAME=	kensa
PORTVERSION=	3.0.2
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Heroku Add-On provider tool

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-colored>=1.2:textproc/rubygem-colored \
		rubygem-launchy22>=2.2.0:devel/rubygem-launchy22 \
		rubygem-mechanize>=2.7.5:www/rubygem-mechanize \
		rubygem-netrc>=0.10.3:net/rubygem-netrc \
		rubygem-rest-client>=1.8:www/rubygem-rest-client

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/kensa

.include <bsd.port.mk>
