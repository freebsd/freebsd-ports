# New ports collection makefile for:	textproc/p5-JSON-Syck
# Date created:				10 January 2006
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	JSON-Syck
PORTVERSION=	0.06
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/M/MI/MIYAGAWA
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Fast, lightweight JSON loader and dumper

BUILD_DEPENDS=	\
	p5-Storable>0:${PORTSDIR}/devel/p5-Storable
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		JSON::Syck.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		requires perl 5.6.1 or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
