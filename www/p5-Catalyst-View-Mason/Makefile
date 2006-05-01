# New ports collection makefile for:	www/p5-Catalyst-View-Mason
# Date created:				07 Dec 2005
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-View-Mason
PORTVERSION=	0.08
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Catalyst
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	Mason view class for Catalyst

BUILD_DEPENDS=	p5-Catalyst>=5.0:${PORTSDIR}/www/p5-Catalyst \
		p5-HTML-Mason>=0:${PORTSDIR}/www/p5-HTML-Mason
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=	Catalyst::Helper::View::Mason.3 \
	Catalyst::View::Mason.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} <= 500801
IGNORE=	requires Perl 5.8. Install lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
