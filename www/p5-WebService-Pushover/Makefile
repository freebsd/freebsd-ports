# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	WebService-Pushover
DISTVERSION=	v0.0.6
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Interface to Pushover API

RUN_DEPENDS=	p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-Format-Strptime>=0:${PORTSDIR}/devel/p5-DateTime-Format-Strptime \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate \
		p5-Readonly>=0:${PORTSDIR}/devel/p5-Readonly \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-WebService-Simple>=0:${PORTSDIR}/www/p5-WebService-Simple

PERL_CONFIGURE=	yes

MAN3=		WebService::Pushover.3

.include <bsd.port.mk>
