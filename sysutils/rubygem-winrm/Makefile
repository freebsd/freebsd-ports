# Created by: Joseph Benden <joe@thrallingpenguin.com>
# $FreeBSD$

PORTNAME=	winrm
PORTVERSION=	1.3.3
PORTREVISION=	1
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	joe@thrallingpenguin.com
COMMENT=	Library for Windows Remote Management

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-builder32>=2.1.2:devel/rubygem-builder32 \
		rubygem-gssapi>=1.2:security/rubygem-gssapi \
		rubygem-gyoku>=1.0:devel/rubygem-gyoku \
		rubygem-httpclient>=2.3.3:www/rubygem-httpclient \
		rubygem-logging>=1.8.1:devel/rubygem-logging \
		rubygem-nokogiri>=1.6.1:textproc/rubygem-nokogiri \
		rubygem-nori>=2.0:devel/rubygem-nori \
		rubygem-rubyntlm>=0.4.0:net/rubygem-rubyntlm \
		rubygem-uuidtools>=2.1.4:devel/rubygem-uuidtools

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/rwinrm

.include <bsd.port.mk>
