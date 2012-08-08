# New ports collection makefile for:	p5-XML-Parsepp
# Date created:		2012-07-01
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XML-Parsepp
PORTVERSION=	0.05
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simplified pure Perl parser for XML

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

PERL_CONFIGURE=	5.14.0+

MAN3=		XML::Parsepp.3

post-patch:
	@${REINPLACE_CMD} -e 's|lib/Acme/XMLpp.pm|lib/XML/Parsepp.pm|' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
