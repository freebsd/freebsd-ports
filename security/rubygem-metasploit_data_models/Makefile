# $FreeBSD$

PORTNAME=	metasploit_data_models
PORTVERSION=	0.24.0
PORTEPOCH=	2
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Database layer for Metasploit

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activerecord>=3.2.13:databases/rubygem-activerecord \
		rubygem-activesupport>=0:devel/rubygem-activesupport \
		rubygem-arel-helpers>=0:databases/rubygem-arel-helpers \
		rubygem-metasploit-concern>=0.4.0:security/rubygem-metasploit-concern \
		rubygem-metasploit-model>=0.29.0:security/rubygem-metasploit-model \
		rubygem-pg>=0:databases/rubygem-pg \
		rubygem-railties>=3.0.0:www/rubygem-railties \
		rubygem-recog>=1.0:security/rubygem-recog

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem
PLIST_FILES=	bin/mdm_console

PORTSCOUT=	ignore:1

.include <bsd.port.mk>
