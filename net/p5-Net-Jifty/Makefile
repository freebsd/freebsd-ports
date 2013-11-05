# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-Jifty
PORTVERSION=	0.14
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to online Jifty applications

RUN_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Term-ReadKey>=0:${PORTSDIR}/devel/p5-Term-ReadKey \
		p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML \
		p5-Email-Address>=0:${PORTSDIR}/mail/p5-Email-Address \
		p5-Hash-Merge>=0:${PORTSDIR}/textproc/p5-Hash-Merge \
		p5-Path-Class>=0:${PORTSDIR}/devel/p5-Path-Class \
		p5-Any-Moose>=0.04:${PORTSDIR}/devel/p5-Any-Moose
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-MockObject>=0:${PORTSDIR}/devel/p5-Test-MockObject

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
RUN_DEPENDS+=	p5-Encode>=2.41:${PORTSDIR}/converters/p5-Encode
BUILD_DEPENDS+=	p5-Encode>=2.41:${PORTSDIR}/converters/p5-Encode
.endif

.include <bsd.port.post.mk>
