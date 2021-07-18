PORTNAME=	puppet-strings
PORTVERSION=	2.7.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	Puppet documentation extraction and presentation tool

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-rgen>=0:devel/rubygem-rgen \
		rubygem-yard>=0:textproc/rubygem-yard

USES=		gem
USE_RUBY=	yes

OPTIONS_SINGLE=	PUPPET
OPTIONS_SINGLE_PUPPET=PUPPET5 PUPPET6 PUPPET7
OPTIONS_DEFAULT=PUPPET7

PUPPET5_DESC=	Depend on sysutils/puppet5
PUPPET6_DESC=	Depend on sysutils/puppet6
PUPPET7_DESC=	Depend on sysutils/puppet7

PUPPET5_RUN_DEPENDS=puppet:sysutils/puppet5
PUPPET6_RUN_DEPENDS=puppet:sysutils/puppet6
PUPPET7_RUN_DEPENDS=puppet:sysutils/puppet7

.include <bsd.port.mk>
