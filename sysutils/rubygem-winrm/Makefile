# Created by: Joseph Benden <joe@thrallingpenguin.com>
# $FreeBSD$

PORTNAME=	winrm
PORTVERSION=	2.3.4
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	joe@thrallingpenguin.com
COMMENT=	Library for Windows Remote Management

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-builder>=2.1.2:devel/rubygem-builder \
		rubygem-erubi>=1.8<2:www/rubygem-erubi \
		rubygem-gssapi>=1.2<2:security/rubygem-gssapi \
		rubygem-gyoku>=1.0<2:devel/rubygem-gyoku \
		rubygem-httpclient>=2.2.0.2<3:www/rubygem-httpclient \
		rubygem-logging>=1.6.1<3.0:devel/rubygem-logging \
		rubygem-nori>=2.0<3:devel/rubygem-nori \
		rubygem-rubyntlm>=0.6.1<0.7:net/rubygem-rubyntlm

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/rwinrm

.include <bsd.port.mk>
