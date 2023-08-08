PORTNAME=	packetgen
PORTVERSION=	3.2.2
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Network packet manipulation library
WWW=		https://github.com/sdaubert/packetgen

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-interfacez>=1.0<2:net/rubygem-interfacez \
		rubygem-pcaprub>=0.12.0:net/rubygem-pcaprub \
		rubygem-rasn1>=0.8.0<1:security/rubygem-rasn1

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/pgconsole

.include <bsd.port.mk>
