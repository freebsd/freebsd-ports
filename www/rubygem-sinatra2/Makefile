PORTNAME=	sinatra
PORTVERSION=	2.2.2
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	2

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Classy web development framework in ruby
WWW=		http://www.sinatrarb.com/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-mustermann>=2.0:devel/rubygem-mustermann \
		rubygem-rack22>=2.2,3<3,3:www/rubygem-rack22 \
		rubygem-rack-protection2>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-rack-protection2 \
		rubygem-tilt>=2.0<3:devel/rubygem-tilt

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	sinatrarb

PORTSCOUT=	limit:^2\.

.include <bsd.port.mk>
