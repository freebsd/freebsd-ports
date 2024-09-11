PORTNAME=	OSLV-Monitor
PORTVERSION=	0.0.1
CATEGORIES=	net-mgmt
MASTER_SITES=	#
PKGNAMEPREFIX=	p5-

MAINTAINER=	dan@langille.org
COMMENT=	OS level virtualization monitoring extend
WWW=		https://github.com/VVelox/OSLV-Monitor

LICENSE=	GPLv3

RUN_DEPENDS=	p5-Clone>0:devel/p5-Clone \
		p5-ExtUtils-MakeMaker>0:devel/p5-ExtUtils-MakeMaker \
		p5-File-Slurp>0:devel/p5-File-Slurp \
		p5-JSON>0:converters/p5-JSON \
		p5-MIME-Base64>0:converters/p5-MIME-Base64

USES=		perl5
USE_PERL5=	configure
USE_GITHUB=	yes
GH_ACCOUNT=	VVelox
NO_BUILD=	YES

SUB_FILES=	pkg-message

.include <bsd.port.mk>
