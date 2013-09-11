# $FreeBSD$

PORTNAME=	XML-AutoWriter
PORTVERSION=	0.40
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
DISTNAME=	${PORTNAME}-0.4
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl module for DOCTYPE based XML output

TEST_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser

USES=		perl5
USE_PERL5=	configure

MAN3=		XML::AutoWriter.3 \
		XML::Doctype::AttDef.3 \
		XML::ValidWriter.3 \
		XML::Doctype::ElementDecl.3 \
		XML::Doctype.3

post-patch:
	${RM} ${WRKSRC}/lib/XML/*.orig

.include <bsd.port.mk>
