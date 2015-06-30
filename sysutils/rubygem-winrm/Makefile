# Created by: Joseph Benden <joe@thrallingpenguin.com>
# $FreeBSD$

PORTNAME=	winrm
PORTVERSION=	1.3.3
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	joe@thrallingpenguin.com
COMMENT=	Library for Windows Remote Management

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-builder32>=2.1.2:${PORTSDIR}/devel/rubygem-builder32 \
		rubygem-gssapi>=1.2:${PORTSDIR}/security/rubygem-gssapi \
		rubygem-gyoku>=1.0:${PORTSDIR}/devel/rubygem-gyoku \
		rubygem-httpclient>=2.3.3:${PORTSDIR}/www/rubygem-httpclient \
		rubygem-logging>=1.8.1:${PORTSDIR}/devel/rubygem-logging \
		rubygem-nokogiri>=1.6.1:${PORTSDIR}/textproc/rubygem-nokogiri \
		rubygem-nori>=2.0:${PORTSDIR}/devel/rubygem-nori \
		rubygem-rubyntlm>=0.4.0:${PORTSDIR}/net/rubygem-rubyntlm \
		rubygem-uuidtools>=2.1.4:${PORTSDIR}/devel/rubygem-uuidtools

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
