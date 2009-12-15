# New ports collection makefile for:	www/p5-Catalyst-Model-DBIC
# Date created:				16 Nov 2005
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Model-DBIC
PORTVERSION=	0.17
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	DBIx::Class model class for Catalyst

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Catalyst-Devel>=1.00:${PORTSDIR}/www/p5-Catalyst-Devel \
		p5-DBIx-Class>=0:${PORTSDIR}/databases/p5-DBIx-Class \
		p5-DBIx-Class-Loader>=0:${PORTSDIR}/databases/p5-DBIx-Class-Loader
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.1+

DEPRECATED=	This module is obsoleted by www/p5-Catalyst-Model-DBIC-Schema

MAN3=	Catalyst::Helper::Model::DBIC.3 \
	Catalyst::Model::DBIC.3

.include <bsd.port.mk>
