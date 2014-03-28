# Created by: Tom Judge <tj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	RDF-Trine
PORTVERSION=	1.007
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tj@FreeBSD.org
COMMENT=	RDF Framework for Perl

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Algorithm-Combinatorics>=0:${PORTSDIR}/math/p5-Algorithm-Combinatorics \
		p5-DBD-SQLite>=1.14:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-DBIx-Connector>=0:${PORTSDIR}/databases/p5-DBIx-Connector \
		p5-Data-UUID>=0:${PORTSDIR}/devel/p5-Data-UUID \
		p5-Digest-MD5>=0:${PORTSDIR}/security/p5-Digest-MD5 \
		p5-Digest-SHA>=0:${PORTSDIR}/security/p5-Digest-SHA \
		p5-Error>=0:${PORTSDIR}/lang/p5-Error \
		p5-HTTP-Negotiate>=0:${PORTSDIR}/www/p5-HTTP-Negotiate \
		p5-JSON>=2.0:${PORTSDIR}/converters/p5-JSON \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Scalar-List-Utils>=0:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		p5-Log-Log4perl>=0:${PORTSDIR}/devel/p5-Log-Log4perl \
		p5-Math-BigInt>=0:${PORTSDIR}/math/p5-Math-BigInt \
		p5-Module-Load-Conditional>=0.38:${PORTSDIR}/devel/p5-Module-Load-Conditional \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-ArrayRef>=0:${PORTSDIR}/devel/p5-MooseX-ArrayRef \
		p5-Set-Scalar>=0:${PORTSDIR}/devel/p5-Set-Scalar \
		p5-Storable>=0:${PORTSDIR}/devel/p5-Storable \
		p5-Text-CSV>=0:${PORTSDIR}/textproc/p5-Text-CSV \
		p5-Text-Table>=0:${PORTSDIR}/textproc/p5-Text-Table \
		p5-URI>=1.30:${PORTSDIR}/net/p5-URI \
		p5-XML-CommonNS>=0.04:${PORTSDIR}/textproc/p5-XML-CommonNS \
		p5-XML-Namespace>=0:${PORTSDIR}/textproc/p5-XML-Namespace \
		p5-XML-SAX>=0.96:${PORTSDIR}/textproc/p5-XML-SAX
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
