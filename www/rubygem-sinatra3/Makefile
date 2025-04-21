PORTNAME=	sinatra
PORTVERSION=	3.2.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	3

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Classy web development framework in ruby
WWW=		https://sinatrarb.com/ \
		https://github.com/sinatra/sinatra

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-mustermann>=3.0<4:devel/rubygem-mustermann \
		rubygem-rack22>=2.2,3<3,3:www/rubygem-rack22 \
		rubygem-rack-protection3>=3.2<4:www/rubygem-rack-protection3 \
		rubygem-tilt>=2.0<3:devel/rubygem-tilt

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	sinatrarb

PORTSCOUT=	limit:^3\.

.include <bsd.port.mk>
