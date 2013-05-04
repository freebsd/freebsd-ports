# Created by: Rick van der Zwet <info@rickvanderzwet.nl>
# $FreeBSD$

PORTNAME=	XML-TinyXML
PORTVERSION=	0.30
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	info@rickvanderzwet.nl
COMMENT=	Little and efficient Perl module to manage xml data

USES=		iconv

MAKE_ARGS+=	LIBS='-L${LOCALBASE}/lib' INC='-I. -I${LOCALBASE}/include'
PERL_CONFIGURE=	yes

MAN3=		XML::TinyXML.3 \
		XML::TinyXML::Node.3 \
		XML::TinyXML::NodeAttribute.3 \
		XML::TinyXML::Selector.3 \
		XML::TinyXML::Selector::XPath.3

.include <bsd.port.mk>
