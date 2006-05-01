# New ports collection makefile for:	www/p5-Catalyst-Model-DBIC
# Date created:				16 Nov 2005
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Model-DBIC
PORTVERSION=	0.14
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Catalyst
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	DBIx::Class model class for Catalyst

BUILD_DEPENDS=	p5-Catalyst>=5.00:${PORTSDIR}/www/p5-Catalyst \
		p5-DBIx-Class>=0:${PORTSDIR}/databases/p5-DBIx-Class \
		p5-DBIx-Class-Loader>=0:${PORTSDIR}/databases/p5-DBIx-Class-Loader
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

DEPRECATED=	This module is obsoleted by www/p5-Catalyst-Model-DBIC-Schema

MAN3=	Catalyst::Helper::Model::DBIC.3 \
	Catalyst::Model::DBIC.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} <= 500800
IGNORE=	requires Perl 5.8. Install lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
