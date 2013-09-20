# $FreeBSD$

PORTNAME=	WWW-Shorten
PORTVERSION=	3.04
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Abstract interface to URL shortening sites

BUILD_DEPENDS=	p5-libwww>=5.75:${PORTSDIR}/www/p5-libwww \
		p5-Config-Auto>=0:${PORTSDIR}/devel/p5-Config-Auto \
		p5-URI>=1.27:${PORTSDIR}/net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN1=		shorten.1
MAN3=		WWW::Shorten.3 \
		WWW::Shorten::LinkToolbot.3 \
		WWW::Shorten::Linkz.3 \
		WWW::Shorten::MakeAShorterLink.3 \
		WWW::Shorten::Metamark.3 \
		WWW::Shorten::TinyClick.3 \
		WWW::Shorten::TinyURL.3 \
		WWW::Shorten::Tinylink.3 \
		WWW::Shorten::UserAgent.3 \
		WWW::Shorten::_dead.3 \
		WWW::Shorten::generic.3

regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} test

NO_STAGE=	yes
.include <bsd.port.mk>
