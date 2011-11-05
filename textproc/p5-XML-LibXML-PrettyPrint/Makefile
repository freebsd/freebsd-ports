# New ports collection makefile for:	p5-XML-LibXML-PrettyPrint
# Date created:		2011-10-21
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XML-LibXML-PrettyPrint
PORTVERSION=	0.002
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Add pleasant whitespace to a DOM tree

BUILD_DEPENDS=	p5-Pragmatic>=0:${PORTSDIR}/devel/p5-Pragmatic \
		p5-XML-LibXML>=1.62:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-common-sense>=0:${PORTSDIR}/devel/p5-common-sense
RUN_DEPENDS=	p5-Pragmatic>=0:${PORTSDIR}/devel/p5-Pragmatic \
		p5-XML-LibXML>=1.62:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-common-sense>=0:${PORTSDIR}/devel/p5-common-sense

PERL_CONFIGURE=	5.10.0+

MAN3=		XML::LibXML::PrettyPrint.3

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
