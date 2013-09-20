# Created by: Steven Kreuzer <skreuzer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Parse-BooleanLogic
PORTVERSION=	0.09
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Parser of boolean expressions

BUILD_DEPENDS=	p5-Regexp-Common>=2.122:${PORTSDIR}/textproc/p5-Regexp-Common \
		p5-Module-Install>=0.91_1:${PORTSDIR}/devel/p5-Module-Install
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Deep>=0:${PORTSDIR}/devel/p5-Test-Deep

USES=		perl5
USE_PERL5=	configure

MAN3=	Parse::BooleanLogic.3

NO_STAGE=	yes
.include <bsd.port.mk>
