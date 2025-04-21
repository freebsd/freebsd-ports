PORTNAME=	metasploit_data_models
PORTVERSION=	6.0.9
PORTEPOCH=	2
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Database layer for Metasploit
WWW=		https://github.com/rapid7/metasploit_data_models

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activerecord71>=7.1:databases/rubygem-activerecord71 \
		rubygem-activesupport71>=7.1:devel/rubygem-activesupport71 \
		rubygem-arel-helpers>=0:databases/rubygem-arel-helpers \
		rubygem-metasploit-concern>=0:security/rubygem-metasploit-concern \
		rubygem-metasploit-model>=3.1:security/rubygem-metasploit-model \
		rubygem-pg>=0:databases/rubygem-pg \
		rubygem-railties71>=7.1:www/rubygem-railties71 \
		rubygem-recog>=0:security/rubygem-recog \
		rubygem-webrick>=0:www/rubygem-webrick

NO_ARCH=	yes
USES=		gem

.include <bsd.port.mk>
