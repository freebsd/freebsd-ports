# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Data-Phrasebook-Loader-YAML
PORTVERSION=	0.12
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A loader class for phrasebook implementations using YAML

LICENSE=	ART20

BUILD_DEPENDS=	p5-Data-Phrasebook>=0.24:${PORTSDIR}/textproc/p5-Data-Phrasebook \
		p5-YAML>=0.35:${PORTSDIR}/textproc/p5-YAML
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Distribution>=0:${PORTSDIR}/devel/p5-Test-Distribution

PERL_CONFIGURE=	yes

MAN3=		Data::Phrasebook::Loader::YAML.3

.include <bsd.port.mk>
