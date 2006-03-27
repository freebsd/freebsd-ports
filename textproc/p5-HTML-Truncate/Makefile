# New ports collection makefile for:	textproc/p5-HTML-Truncate
# Date created:				23 December 2005
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	HTML-Truncate
PORTVERSION=	0.10
CATEGORIES=	textproc www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTML
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	truncate HTML by character count while preserving well-formedness

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/HTML/TokeParser.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/${PERL_ARCH}/HTML/Entities.pm:${PORTSDIR}/www/p5-HTML-Parser
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	HTML::Truncate.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		requires perl 5.8.0 or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
