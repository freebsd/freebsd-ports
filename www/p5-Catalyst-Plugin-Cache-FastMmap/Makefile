# Ports collection makefile for:	p5-Catalyst-Plugin-Cache-FastMmap
# Date created:				Dec 19, 2005
# Whom:					Lars Balker Rasmussen <lars@balker.dk>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-Cache-FastMmap
PORTVERSION=	0.6
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Catalyst
PKGNAMEPREFIX=	p5-

MAINTAINER=	lars@balker.dk
COMMENT=	Mmap cache for Catalyst

BUILD_DEPENDS=	p5-Catalyst>=0:${PORTSDIR}/www/p5-Catalyst \
		p5-Cache-FastMmap>=0:${PORTSDIR}/devel/p5-Cache-FastMmap
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=	Catalyst::Plugin::Cache::FastMmap.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500801
IGNORE=	requires at least Perl 5.8.1. Install lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
