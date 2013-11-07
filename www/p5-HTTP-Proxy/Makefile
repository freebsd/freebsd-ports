# Created by: mat
# $FreeBSD$

PORTNAME=	HTTP-Proxy
PORTVERSION=	0.300
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Pure Perl HTTP proxy

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-HTTP-Daemon>=1.25:${PORTSDIR}/www/p5-HTTP-Daemon \
		p5-libwww>=6:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
