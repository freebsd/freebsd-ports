# New ports collection makefile for:	www/p5-Catalyst-Plugin-Session-Store-DBI
# Date created:				2 Jan 2006
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-Session-Store-DBI
PORTVERSION=	0.07
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Catalyst
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	Store your sessions in a database

BUILD_DEPENDS=	p5-Catalyst>=5.49:${PORTSDIR}/www/p5-Catalyst \
		p5-Catalyst-Plugin-Session>=0.05:${PORTSDIR}/www/p5-Catalyst-Plugin-Session \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-MIME-Base64>=0:${PORTSDIR}/converters/p5-MIME-Base64 \
		p5-Storable>=0:${PORTSDIR}/devel/p5-Storable
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=	Catalyst::Plugin::Session::Store::DBI.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} <= 500801
IGNORE=	requires Perl 5.8.1. Install lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
