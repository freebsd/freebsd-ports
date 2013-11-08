# $FreeBSD$

PORTNAME=	Pod-Spell
PORTVERSION=	1.13
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	A formatter for spellchecking Pod

LICENSE=	ART20

BUILD_DEPENDS=	p5-Class-Tiny>=0:${PORTSDIR}/devel/p5-Class-Tiny \
		p5-File-ShareDir-Install>=0.03:${PORTSDIR}/devel/p5-File-ShareDir-Install \
		p5-File-ShareDir-ProjectDistDir>=0:${PORTSDIR}/devel/p5-File-ShareDir-ProjectDistDir \
		p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-Lingua-EN-Inflect>=0:${PORTSDIR}/textproc/p5-Lingua-EN-Inflect \
		p5-Pod-Escapes>=1.01:${PORTSDIR}/textproc/p5-Pod-Escapes
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
