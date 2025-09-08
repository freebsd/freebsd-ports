PORTNAME=	packetgen
PORTVERSION=	4.1.1
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Network packet manipulation library
WWW=		https://github.com/lemontree55/packetgen

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-bin_struct>=0.5.0<0.6:devel/rubygem-bin_struct \
		rubygem-digest-crc>=0<1:security/rubygem-digest-crc \
		rubygem-interfacez>=1.0<2:net/rubygem-interfacez \
		rubygem-pcaprub>=0.13.0<0.14:net/rubygem-pcaprub \
		rubygem-rasn1>=0.14<1:security/rubygem-rasn1

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/pgconsole

.include <bsd.port.mk>
