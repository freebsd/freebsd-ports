# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-HTTPS-Any
PORTVERSION=	0.10
CATEGORIES=	net perl5 www
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Simple HTTPS class using whichever underlying SSL module is available

BUILD_DEPENDS=	p5-Tie-IxHash>=0:${PORTSDIR}/devel/p5-Tie-IxHash \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-Net-SSLeay>=1.30:${PORTSDIR}/security/p5-Net-SSLeay
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Net::HTTPS::Any.3

.include <bsd.port.mk>
