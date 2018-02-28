# $FreeBSD$

PORTNAME=	metasploit-credential
PORTVERSION=	2.0.13
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Credential models for metasploit-framework and Metasploit Pro

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-metasploit-concern>=0:security/rubygem-metasploit-concern \
		rubygem-metasploit_data_models>=0:security/rubygem-metasploit_data_models \
		rubygem-metasploit-model>=0:security/rubygem-metasploit-model \
		rubygem-pg>=0:databases/rubygem-pg \
		rubygem-railties4>=0:www/rubygem-railties4 \
		rubygem-rex-socket>=0:security/rubygem-rex-socket \
		rubygem-rubyntlm>=0:net/rubygem-rubyntlm \
		rubygem-rubyzip>=0:archivers/rubygem-rubyzip

NO_ARCH=	yes
USES=		gem
USE_RUBY=	yes

.include <bsd.port.mk>
