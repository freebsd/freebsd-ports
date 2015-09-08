# $FreeBSD$

PORTNAME=	Dancer-Session-Memcached
PORTVERSION=	0.202
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Perl extension for memcached based session backend for Dancer

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-Dancer>=1.3113:${PORTSDIR}/www/p5-Dancer \
	p5-Cache-Memcached>=0:${PORTSDIR}/databases/p5-Cache-Memcached
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=	perl5
USE_PERL5=	modbuild
NO_ARCH=	YES

.include <bsd.port.mk>
