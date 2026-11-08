PORTNAME=	metasploit_data_models
PORTVERSION=	6.0.18
PORTEPOCH=	2
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Database layer for Metasploit
WWW=		https://github.com/rapid7/metasploit_data_models

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activerecord80>=8.0:databases/rubygem-activerecord80 \
		rubygem-activesupport80>=8.0:devel/rubygem-activesupport80 \
		rubygem-arel-helpers>=0:databases/rubygem-arel-helpers \
		rubygem-bigdecimal>=0:math/rubygem-bigdecimal \
		rubygem-drb>=0:devel/rubygem-drb \
		rubygem-metasploit-concern>=0:security/rubygem-metasploit-concern \
		rubygem-metasploit-model>=5.0.4:security/rubygem-metasploit-model \
		rubygem-mutex_m>=0:devel/rubygem-mutex_m \
		rubygem-pg>=0:databases/rubygem-pg \
		rubygem-railties80>=8.0:www/rubygem-railties80 \
		rubygem-recog>=0:security/rubygem-recog \
		rubygem-webrick>=0:www/rubygem-webrick

NO_ARCH=	yes
USES=		gem

.include <bsd.port.mk>
