# Created by: Tom Judge <tj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	RDF-Trine
PORTVERSION=	1.014
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tj@FreeBSD.org
COMMENT=	RDF Framework for Perl

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Algorithm-Combinatorics>=0:math/p5-Algorithm-Combinatorics \
		p5-Cache-LRU>=0.04:devel/p5-Cache-LRU \
		p5-DBD-SQLite>=1.14:databases/p5-DBD-SQLite \
		p5-DBI>=0:databases/p5-DBI \
		p5-DBIx-Connector>=0:databases/p5-DBIx-Connector \
		p5-Data-UUID>=0:devel/p5-Data-UUID \
		p5-Digest-MD5>=0:security/p5-Digest-MD5 \
		p5-Digest-SHA>=0:security/p5-Digest-SHA \
		p5-Error>=0:lang/p5-Error \
		p5-HTTP-Negotiate>=0:www/p5-HTTP-Negotiate \
		p5-JSON>=2.0:converters/p5-JSON \
		p5-List-MoreUtils>=0.413:lang/p5-List-MoreUtils \
		p5-Log-Log4perl>=0:devel/p5-Log-Log4perl \
		p5-Math-BigInt>=0:math/p5-Math-BigInt \
		p5-Module-Load-Conditional>=0.38:devel/p5-Module-Load-Conditional \
		p5-Moose>=0:devel/p5-Moose \
		p5-MooseX-ArrayRef>=0:devel/p5-MooseX-ArrayRef \
		p5-Set-Scalar>=0:devel/p5-Set-Scalar \
		p5-Storable>=0:devel/p5-Storable \
		p5-Text-CSV>=0:textproc/p5-Text-CSV \
		p5-Text-Table>=0:textproc/p5-Text-Table \
		p5-Time-HiRes>=1.9726:devel/p5-Time-HiRes \
		p5-URI>=1.30:net/p5-URI \
		p5-Unicode-Escape>=0.0.2:textproc/p5-Unicode-Escape \
		p5-Unicode-String>=2.09:converters/p5-Unicode-String \
		p5-XML-CommonNS>=0.04:textproc/p5-XML-CommonNS \
		p5-XML-LibXML>=2.0124:textproc/p5-XML-LibXML \
		p5-XML-Namespace>=0:textproc/p5-XML-Namespace \
		p5-XML-SAX>=0.96:textproc/p5-XML-SAX \
		p5-libwww>=0:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502000
BUILD_DEPENDS+=      p5-Scalar-List-Utils>=1.33:lang/p5-Scalar-List-Utils
RUN_DEPENDS+=        p5-Scalar-List-Utils>=1.33:lang/p5-Scalar-List-Utils
.endif

.include <bsd.port.post.mk>
