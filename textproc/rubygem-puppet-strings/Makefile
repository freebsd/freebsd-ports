PORTNAME=	puppet-strings
PORTVERSION=	4.1.1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	Puppet documentation extraction and presentation tool
WWW=		https://github.com/puppetlabs/puppet-strings

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-rgen>=0:devel/rubygem-rgen \
		rubygem-yard>=0.9.5<0.10:textproc/rubygem-yard

USES=		gem

NO_ARCH=	yes

OPTIONS_SINGLE=	PUPPET
OPTIONS_SINGLE_PUPPET=PUPPET7 PUPPET8
OPTIONS_DEFAULT=PUPPET8

PUPPET7_DESC=	Depend on sysutils/puppet7
PUPPET8_DESC=	Depend on sysutils/puppet8

PUPPET7_RUN_DEPENDS=puppet:sysutils/puppet7
PUPPET8_RUN_DEPENDS=puppet:sysutils/puppet8

.include <bsd.port.mk>
