# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	XML-Parsepp
PORTVERSION=	0.06
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simplified pure Perl parser for XML

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

USE_PERL5=	5.14.0+ configure
USES=		perl5

MAN3=		XML::Parsepp.3

post-patch:
	@${REINPLACE_CMD} -e 's|lib/Acme/XMLpp.pm|lib/XML/Parsepp.pm|' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
