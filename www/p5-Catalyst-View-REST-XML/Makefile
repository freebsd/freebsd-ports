# $FreeBSD$

PORTNAME=	Catalyst-View-REST-XML
PORTVERSION=	0.02
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for Catalyst XML View Class

RUN_DEPENDS=	\
	p5-Catalyst-Runtime>0:${PORTSDIR}/www/p5-Catalyst-Runtime \
	p5-XML-Simple>0:${PORTSDIR}/textproc/p5-XML-Simple
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
