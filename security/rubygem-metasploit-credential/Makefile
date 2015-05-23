# $FreeBSD$

PORTNAME=	metasploit-credential
PORTVERSION=	0.14.5
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Credential models for metasploit-framework and Metasploit Pro

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-metasploit-concern>=0.4.0:${PORTSDIR}/security/rubygem-metasploit-concern \
		rubygem-metasploit_data_models>=0.24.0,2:${PORTSDIR}/security/rubygem-metasploit_data_models \
		rubygem-metasploit-model>=0.29.0:${PORTSDIR}/security/rubygem-metasploit-model \
		rubygem-pg>=0:${PORTSDIR}/databases/rubygem-pg \
		rubygem-railties>=3.0.0:${PORTSDIR}/www/rubygem-railties \
		rubygem-rubyntlm>=0:${PORTSDIR}/net/rubygem-rubyntlm \
		rubygem-rubyzip>=1.1:${PORTSDIR}/archivers/rubygem-rubyzip

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PORTSCOUT=	ignore:1

.include <bsd.port.mk>
