# Created by: Joseph Benden <joe@thrallingpenguin.com>
# $FreeBSD$

PORTNAME=	winrm
PORTVERSION=	1.1.3
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	joe@thrallingpenguin.com
COMMENT=	Library for Windows Remote Management

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-gssapi>=1.0.0:${PORTSDIR}/security/rubygem-gssapi \
		rubygem-httpclient>=2.3.3:${PORTSDIR}/www/rubygem-httpclient \
		rubygem-logging>=1.8.1:${PORTSDIR}/devel/rubygem-logging \
		rubygem-nokogiri>=1.6.1:${PORTSDIR}/textproc/rubygem-nokogiri \
		rubygem-rubyntlm01>=0.1.0:${PORTSDIR}/net/rubygem-rubyntlm01 \
		rubygem-savon>=0.9.5:${PORTSDIR}/www/rubygem-savon \
		rubygem-uuidtools>=2.1.4:${PORTSDIR}/devel/rubygem-uuidtools

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
