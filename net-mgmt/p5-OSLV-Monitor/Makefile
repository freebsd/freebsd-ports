PORTNAME=	OSLV-Monitor
PORTVERSION=	1.0.2
CATEGORIES=	net-mgmt
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	OS level virtualization monitoring extend
WWW=		https://github.com/VVelox/OSLV-Monitor

LICENSE=	GPLv3

RUN_DEPENDS=	jq>0:textproc/jq \
		p5-Clone>0:devel/p5-Clone \
		p5-ExtUtils-MakeMaker>0:devel/p5-ExtUtils-MakeMaker \
		p5-File-Slurp>0:devel/p5-File-Slurp \
		p5-IO-Interface>0:net/p5-IO-Interface \
		p5-JSON>0:converters/p5-JSON \
		p5-MIME-Base64>0:converters/p5-MIME-Base64

USES=		perl5
USE_PERL5=	configure
NO_BUILD=	YES

SUB_FILES=	pkg-message

.include <bsd.port.mk>
