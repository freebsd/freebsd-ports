# Created by: TERAMOTO Masahiro <markun@onohara.to>
# $FreeBSD$

PORTNAME=	YAML-LibYAML
PORTVERSION=	0.82
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl YAML Serialization using XS and libyaml

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	p5-Filter>=0:devel/p5-Filter \
		p5-Test-Base>=0:devel/p5-Test-Base

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/YAML/XS/LibYAML/LibYAML.so

.include <bsd.port.mk>
