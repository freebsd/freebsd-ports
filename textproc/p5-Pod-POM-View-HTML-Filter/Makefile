# New ports collection makefile for:	textproc/p5-Pod-POM-View-HTML-Filter
# Date created:				01 September 2005
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Pod-POM-View-HTML-Filter
PORTVERSION=	0.05
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Pod
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Use filters on sections of your pod documents

BUILD_DEPENDS=	${SITE_PERL}/Pod/POM.pm:${PORTSDIR}/textproc/p5-Pod-POM \
		${SITE_PERL}/Syntax/Highlight/Shell.pm:${PORTSDIR}/www/p5-Syntax-Highlight-Shell \
		${SITE_PERL}/Perl/Tidy.pm:${PORTSDIR}/devel/p5-Perl-Tidy \
		${SITE_PERL}/Syntax/Highlight/HTML.pm:${PORTSDIR}/www/p5-Syntax-Highlight-HTML
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Pod::POM::View::HTML::Filter.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		Port requires perl 5.6.0 or later. Install lang/perl5 and try again
.endif

.include <bsd.port.post.mk>
