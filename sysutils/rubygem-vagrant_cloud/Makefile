# $FreeBSD$

PORTNAME=	vagrant_cloud
PORTVERSION=	3.0.2
PORTREVISION=	1
CATEGORIES=	sysutils rubygems devel
MASTER_SITES=	RG

MAINTAINER=	cmt@FreeBSD.org
COMMENT=	Vagrant Cloud API wrapper for Ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	rubygem-rest-client>=2.0.2:www/rubygem-rest-client
RUN_DEPENDS=	rubygem-excon>=0.73<1.0:devel/rubygem-excon \
		rubygem-log4r>=1.1.10<1.2:sysutils/rubygem-log4r

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
