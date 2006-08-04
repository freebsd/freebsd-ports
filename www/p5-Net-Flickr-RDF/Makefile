# New ports collection makefile for:	p5-Net-Flickr-RDF
# Date created:		2006-07-29
# Whom:			Tsung-Han Yeh <snowfly@yuntech.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Net-Flickr-RDF
PORTVERSION=	1.8
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	snowfly@yuntech.edu.tw
COMMENT=	Describe Flickr photos as RDF

BUILD_DEPENDS=	${SITE_PERL}/Net/Flickr/API.pm:${PORTSDIR}/www/p5-Net-Flickr-API \
		${SITE_PERL}/RDF/Simple.pm:${PORTSDIR}/textproc/p5-RDF-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Net::Flickr::RDF.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	requires at least Perl 5.6 due to dependencies.  Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
