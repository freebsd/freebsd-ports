# New ports collection makefile for:	www/p5-Syntax-Highlight-Shell
# Date created:				01 September 2005
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Syntax-Highlight-Shell
PORTVERSION=	0.04
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Syntax
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Syntax::Highlight::Shell - Highlight shell scripts

BUILD_DEPENDS=	${SITE_PERL}/Shell/Parser.pm:${PORTSDIR}/devel/p5-Shell-Parser
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Syntax::Highlight::Shell.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		Port requires perl 5.6.0 or later. Install lang/perl5 and try again
.endif

.include <bsd.port.post.mk>
