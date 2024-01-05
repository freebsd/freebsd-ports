PORTNAME=	metasploit_data_models
PORTVERSION=	6.0.3
PORTEPOCH=	2
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Database layer for Metasploit
WWW=		https://github.com/rapid7/metasploit_data_models

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activerecord70>=7.0:databases/rubygem-activerecord70 \
		rubygem-activesupport70>=7.0:devel/rubygem-activesupport70 \
		rubygem-arel-helpers>=0:databases/rubygem-arel-helpers \
		rubygem-metasploit-concern>=0:security/rubygem-metasploit-concern \
		rubygem-metasploit-model>=3.1:security/rubygem-metasploit-model \
		rubygem-pg>=0:databases/rubygem-pg \
		rubygem-railties70>=7.0:www/rubygem-railties70 \
		rubygem-recog>=0:security/rubygem-recog \
		rubygem-webrick>=0:www/rubygem-webrick

NO_ARCH=	yes
USES=		gem

.include <bsd.port.mk>
