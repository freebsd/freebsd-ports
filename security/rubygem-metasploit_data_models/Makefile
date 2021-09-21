PORTNAME=	metasploit_data_models
PORTVERSION=	5.0.4
PORTEPOCH=	2
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Database layer for Metasploit

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activerecord60>=6.0:databases/rubygem-activerecord60 \
		rubygem-activesupport60>=6.0:devel/rubygem-activesupport60 \
		rubygem-arel-helpers>=0:databases/rubygem-arel-helpers \
		rubygem-metasploit-concern>=0:security/rubygem-metasploit-concern \
		rubygem-metasploit-model>=3.1:security/rubygem-metasploit-model \
		rubygem-pg>=0:databases/rubygem-pg \
		rubygem-railties60>=6.0:www/rubygem-railties60 \
		rubygem-recog>=2.0:security/rubygem-recog \
		rubygem-webrick>=0:www/rubygem-webrick

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
