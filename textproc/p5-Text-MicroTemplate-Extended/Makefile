# $FreeBSD$

PORTNAME=	Text-MicroTemplate-Extended
PORTVERSION=	0.17
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for extended MicroTemplate

RUN_DEPENDS=	\
	p5-Text-MicroTemplate>=0.18:${PORTSDIR}/textproc/p5-Text-MicroTemplate
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Text::MicroTemplate::Extended.3 \
	Text::MicroTemplate::Extended.ja.3

.include <bsd.port.mk>
