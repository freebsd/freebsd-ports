# $FreeBSD$

PORTNAME=	metasploit_data_models
PORTVERSION=	2.0.0
PORTEPOCH=	2
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Database layer for Metasploit

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activerecord4>=4.2.6:databases/rubygem-activerecord4 \
		rubygem-activesupport4>=4.2.6:devel/rubygem-activesupport4 \
		rubygem-metasploit-concern>=0:security/rubygem-metasploit-concern \
		rubygem-metasploit-model>=0:security/rubygem-metasploit-model \
		rubygem-railties4>=4.2.6:www/rubygem-railties4 \
		rubygem-recog>=2.0:security/rubygem-recog \
		rubygem-arel-helpers>=0:databases/rubygem-arel-helpers \
		rubygem-postgres_ext>=0:databases/rubygem-postgres_ext \
		rubygem-pg>=0:databases/rubygem-pg

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem
PLIST_FILES=	bin/mdm_console

PORTSCOUT=	ignore:1

.include <bsd.port.mk>
