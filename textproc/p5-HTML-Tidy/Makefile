# New ports collection makefile for:	p5-HTML-Tidy
# Date Created:				8 june 2004
# Whom:					mat
#
# $FreeBSD$
#

PORTNAME=	HTML-Tidy
PORTVERSION=	1.04
CATEGORIES=	textproc www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTML
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Web validation in a Perl object using tidy

BUILD_DEPENDS=	${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww
LIB_DEPENDS=	tidy:${PORTSDIR}/www/tidy-lib
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		HTML::Tidy.3 HTML::Tidy::Message.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		Needs perl 5.6 or higher, install lang/perl5 or lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
