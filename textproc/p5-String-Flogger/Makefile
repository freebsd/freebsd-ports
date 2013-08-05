# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	String-Flogger
PORTVERSION=	1.101243
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RJBS
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	String munging for loggers

BUILD_DEPENDS=	p5-Params-Util>0:${PORTSDIR}/devel/p5-Params-Util \
		p5-Sub-Exporter>0:${PORTSDIR}/devel/p5-Sub-Exporter \
		p5-JSON>0:${PORTSDIR}/converters/p5-JSON
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Simple>=0.82:${PORTSDIR}/devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	configure

MAN3=	String::Flogger.3

.include <bsd.port.mk>
