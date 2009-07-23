# New ports collection makefile for:	www/p5-Catalyst-Model-Xapian
# Date created:				22 Feb 2006
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Model-Xapian
PORTVERSION=	0.04
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/M/MR/MRAMBERG
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	Catalyst model for Search::Xapian

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Catalyst-Devel>=1.00:${PORTSDIR}/www/p5-Catalyst-Devel \
		p5-Data-Page>=0:${PORTSDIR}/databases/p5-Data-Page \
		p5-Search-Xapian>=0.9.2.4:${PORTSDIR}/databases/p5-Search-Xapian \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	5.8.1+

MAN3=	Catalyst::Model::Xapian.3 \
	Catalyst::Helper::Model::Xapian.3

.include <bsd.port.mk>
