# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Catalyst-Action-REST
PORTVERSION=	1.12
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Automated REST Method Dispatching for Catalyst

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.80030:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Class-Inspector>=1.13:${PORTSDIR}/devel/p5-Class-Inspector \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-MRO-Compat>=0.10:${PORTSDIR}/devel/p5-MRO-Compat \
		p5-Moose>=1.03:${PORTSDIR}/devel/p5-Moose \
		p5-Params-Validate>=0.76:${PORTSDIR}/devel/p5-Params-Validate \
		p5-URI-Find>=0:${PORTSDIR}/textproc/p5-URI-Find \
		p5-YAML-Syck>=0.67:${PORTSDIR}/textproc/p5-YAML-Syck \
		p5-libwww>=2.033:${PORTSDIR}/www/p5-libwww \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-JSON>=0:${PORTSDIR}/converters/p5-JSON

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ARGS=	--default

.include <bsd.port.mk>
