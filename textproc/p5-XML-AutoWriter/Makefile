# $FreeBSD$

PORTNAME=	XML-AutoWriter
PORTVERSION=	0.40
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-0.4

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl module for DOCTYPE based XML output

LICENSE=	ART10 GPLv1 BSD4CLAUSE
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-XML-Parser>=0:textproc/p5-XML-Parser

USES=		perl5
USE_PERL5=	configure

post-patch:
	${RM} ${WRKSRC}/lib/XML/*.orig

.include <bsd.port.mk>
