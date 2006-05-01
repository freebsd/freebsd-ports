# New ports collection makefile for:	www/p5-Catalyst-Model-Xapian
# Date created:				22 Feb 2006
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Model-Xapian
PORTVERSION=	0.02
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/M/MR/MRAMBERG
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	Catalyst model for Search::Xapian

BUILD_DEPENDS=	p5-Catalyst>=5.30:${PORTSDIR}/www/p5-Catalyst \
		p5-Data-Page>=0:${PORTSDIR}/databases/p5-Data-Page \
		p5-Search-Xapian>=0.9.2.4:${PORTSDIR}/databases/p5-Search-Xapian
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=	Catalyst::Model::Xapian.3 \
	Catalyst::Helper::Model::Xapian.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} <= 500800
IGNORE=	requires Perl 5.8. Install lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
