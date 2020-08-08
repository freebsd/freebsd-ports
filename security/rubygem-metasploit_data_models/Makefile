# $FreeBSD$

PORTNAME=	metasploit_data_models
PORTVERSION=	4.0.2
PORTEPOCH=	2
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Database layer for Metasploit

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activerecord52>=5.2.2:databases/rubygem-activerecord52 \
		rubygem-activesupport52>=5.2.2:devel/rubygem-activesupport52 \
		rubygem-arel-helpers>=0:databases/rubygem-arel-helpers \
		rubygem-metasploit-concern>=0:security/rubygem-metasploit-concern \
		rubygem-metasploit-model>=0:security/rubygem-metasploit-model \
		rubygem-pg>=0:databases/rubygem-pg \
		rubygem-railties52>=5.2.2:www/rubygem-railties52 \
		rubygem-recog>=2.0:security/rubygem-recog

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
