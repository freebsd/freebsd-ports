# New ports collection makefile for:	Template-Magic
# Date created:				July 23 2004
# Whom:	      				Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	Template-Magic
PORTVERSION=	1.31
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Template
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A Perl Module with magic merger of runtime values with templates

BUILD_DEPENDS=	${SITE_PERL}/IO/Util.pm:${PORTSDIR}/devel/p5-IO-Util \
		${SITE_PERL}/Class/constr.pm:${PORTSDIR}/devel/p5-OOTools
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		Template::Magic.3 \
		Bundle::Template::Magic.3 \
		Template::Magic::HTML.3 \
		Template::Magic::Zone.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		This port requires perl 5.6.1 or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
