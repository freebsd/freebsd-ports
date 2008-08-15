# New ports collection makefile for:	p5-Net-Flickr-RDF
# Date created:		2006-07-29
# Whom:			Tsung-Han Yeh <snowfly@yuntech.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Net-Flickr-RDF
PORTVERSION=	2.1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	snowfly@yuntech.edu.tw
COMMENT=	Describe Flickr photos as RDF

RUN_DEPENDS=	${SITE_PERL}/RDF/Simple.pm:${PORTSDIR}/textproc/p5-RDF-Simple \
		p5-TimeDate>=1.16:${PORTSDIR}/devel/p5-TimeDate \
		p5-Net-Flickr-API>=1.68:${PORTSDIR}/www/p5-Net-Flickr-API
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	5.8.0+

MAN3=		Net::Flickr::RDF.3

.include <bsd.port.mk>
