# Created by: Joseph Benden <joe@thrallingpenguin.com>
# $FreeBSD$

PORTNAME=	winrm
PORTVERSION=	2.2.3
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	joe@thrallingpenguin.com
COMMENT=	Library for Windows Remote Management

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-builder>=2.1.2:devel/rubygem-builder \
		rubygem-erubis>=2.7:www/rubygem-erubis \
		rubygem-gssapi>=1.2:security/rubygem-gssapi \
		rubygem-gyoku>=1.0:devel/rubygem-gyoku \
		rubygem-httpclient>=2.2.0.2:www/rubygem-httpclient \
		rubygem-logging>=1.6.1:devel/rubygem-logging \
		rubygem-nokogiri>=1.6.1:textproc/rubygem-nokogiri \
		rubygem-nori>=2.0:devel/rubygem-nori \
		rubygem-rubyntlm>=0.6.1:net/rubygem-rubyntlm

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/rwinrm

.include <bsd.port.mk>
