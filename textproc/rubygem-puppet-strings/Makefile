# $FreeBSD$

PORTNAME=	puppet-strings
PORTVERSION=	2.4.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	Puppet documentation extraction and presentation tool

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	puppet:sysutils/puppet6 \
		rubygem-rgen>=0:devel/rubygem-rgen \
		rubygem-yard>=0:textproc/rubygem-yard

USES=		gem
USE_RUBY=	yes

.include <bsd.port.mk>
