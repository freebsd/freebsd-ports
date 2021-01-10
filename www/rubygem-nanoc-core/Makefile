# $FreeBSD$

PORTNAME=	nanoc-core
PORTVERSION=	4.11.19
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sdalu@sdalu.com
COMMENT=	Contains the core of Nanoc

LICENSE=	MIT

RUN_DEPENDS=	rubygem-concurrent-ruby>=1.1:devel/rubygem-concurrent-ruby \
		rubygem-ddmemoize>=1.0:devel/rubygem-ddmemoize \
		rubygem-ddmetrics>=1.0:devel/rubygem-ddmetrics \
		rubygem-ddplugin>=1.0:devel/rubygem-ddplugin \
		rubygem-hamster>=3.0:devel/rubygem-hamster \
		rubygem-json_schema>=0.19:devel/rubygem-json_schema \
		rubygem-slow_enumerator_tools>=1.0:devel/rubygem-slow_enumerator_tools \
		rubygem-tomlrb1>=1.2:textproc/rubygem-tomlrb1 \
		rubygem-tty-platform>=0.2:devel/rubygem-tty-platform \
		rubygem-zeitwerk>=2.1:devel/rubygem-zeitwerk

USES=		gem
NO_ARCH=	yes
USE_RUBY=	yes

.include <bsd.port.mk>
