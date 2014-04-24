# Created by: TERAMOTO Masahiro <markun@onohara.to>
# $FreeBSD$

PORTNAME=	WWW-Tumblr
PORTVERSION=	5.00
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	Perl interface for the Tumblr API

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-HTTP-Message>0:${PORTSDIR}/www/p5-HTTP-Message \
		p5-JSON>0:${PORTSDIR}/converters/p5-JSON \
		p5-Moose>0:${PORTSDIR}/devel/p5-Moose \
		p5-Net-OAuth>0:${PORTSDIR}/net/p5-Net-OAuth \
		p5-libwww>0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
