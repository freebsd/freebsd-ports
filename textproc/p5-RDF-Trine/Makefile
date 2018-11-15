# Created by: Tom Judge <tj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	RDF-Trine
PORTVERSION=	1.019
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	RDF Framework for Perl

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Algorithm-Combinatorics>=0:math/p5-Algorithm-Combinatorics \
		p5-Cache-LRU>=0:devel/p5-Cache-LRU \
		p5-DBD-SQLite>=1.14:databases/p5-DBD-SQLite \
		p5-DBI>=0:databases/p5-DBI \
		p5-DBIx-Connector>=0:databases/p5-DBIx-Connector \
		p5-Data-UUID>=0:devel/p5-Data-UUID \
		p5-Error>=0:lang/p5-Error \
		p5-HTTP-Negotiate>=0:www/p5-HTTP-Negotiate \
		p5-IRI>=0:devel/p5-IRI \
		p5-JSON>=2:converters/p5-JSON \
		p5-Log-Log4perl>=0:devel/p5-Log-Log4perl \
		p5-Moose>=2:devel/p5-Moose \
		p5-MooseX-ArrayRef>=0:devel/p5-MooseX-ArrayRef \
		p5-Set-Scalar>=0:devel/p5-Set-Scalar \
		p5-Text-CSV_XS>=0:textproc/p5-Text-CSV_XS \
		p5-Text-Table>=0:textproc/p5-Text-Table \
		p5-URI>=1.52:net/p5-URI \
		p5-XML-CommonNS>=0.04:textproc/p5-XML-CommonNS \
		p5-XML-LibXML>=1.70:textproc/p5-XML-LibXML \
		p5-XML-Namespace>=0:textproc/p5-XML-Namespace \
		p5-XML-SAX>=0.96:textproc/p5-XML-SAX \
		p5-libwww>=0:www/p5-libwww

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
