# $FreeBSD$

PORTNAME=	metasploit-credential
PORTVERSION=	0.14.5
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Credential models for metasploit-framework and Metasploit Pro

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-metasploit-concern>=0.4.0:security/rubygem-metasploit-concern \
		rubygem-metasploit_data_models>=0.24.0,2:security/rubygem-metasploit_data_models \
		rubygem-metasploit-model>=0.29.0:security/rubygem-metasploit-model \
		rubygem-pg>=0:databases/rubygem-pg \
		rubygem-railties>=3.0.0:www/rubygem-railties \
		rubygem-rubyntlm>=0:net/rubygem-rubyntlm \
		rubygem-rubyzip>=1.1:archivers/rubygem-rubyzip

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PORTSCOUT=	ignore:1

.include <bsd.port.mk>
