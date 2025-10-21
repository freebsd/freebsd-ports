PORTNAME=	openvox-strings
PORTVERSION=	6.0.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	Puppet documentation extraction and presentation tool
WWW=		https://github.com/voxpupuli/openvox-strings

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	openvox-agent8>=7:sysutils/openvox-agent8 \
		rubygem-rgen>=0:devel/rubygem-rgen \
		rubygem-yard>=0.9.5<0.10:textproc/rubygem-yard

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
