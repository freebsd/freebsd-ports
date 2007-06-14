# New ports collection makefile for:	p5-Net-Flickr-RDF
# Date created:		2006-07-29
# Whom:			Tsung-Han Yeh <snowfly@yuntech.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Net-Flickr-RDF
PORTVERSION=	2.0
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	snowfly@yuntech.edu.tw
COMMENT=	Describe Flickr photos as RDF

RUN_DEPENDS=	${SITE_PERL}/Net/Flickr/API.pm:${PORTSDIR}/www/p5-Net-Flickr-API \
		${SITE_PERL}/RDF/Simple.pm:${PORTSDIR}/textproc/p5-RDF-Simple
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Net::Flickr::RDF.3

.include <bsd.port.mk>
