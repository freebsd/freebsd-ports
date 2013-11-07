# Created by: Aaron Straup Cope <ascope@cpan.org>
# $FreeBSD$

PORTNAME=	RDF-Simple
PORTVERSION=	0.41.5
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Read and write RDF without complication

RUN_DEPENDS=	p5-Class-MakeMethods>=0:${PORTSDIR}/devel/p5-Class-MakeMethods \
		p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-Regexp-Common>=0:${PORTSDIR}/textproc/p5-Regexp-Common \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-XML-SAX>=0:${PORTSDIR}/textproc/p5-XML-SAX \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-IO-CaptureOutput>0:${PORTSDIR}/devel/p5-IO-CaptureOutput \
		p5-Test-File>=0:${PORTSDIR}/devel/p5-Test-File

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
