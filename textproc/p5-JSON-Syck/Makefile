# New ports collection makefile for:	p5-JSON-Syck
# Date created:		2006-07-11
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	JSON-Syck
PORTVERSION=	0.07
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	JSON
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	JSON is YAML

PERL_CONFIGURE=	yes

MAN3=		JSON::Syck.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.6 or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
