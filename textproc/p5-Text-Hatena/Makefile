# New ports collection makefile for:	p5-Text-Hatena
# Date created:		2006-07-11
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Text-Hatena
PORTVERSION=	0.14
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Text
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Perl extension for formatting text with Hatena Style

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/HTML/Parser.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/${PERL_ARCH}/Template.pm:${PORTSDIR}/www/p5-Template-Toolkit \
		${SITE_PERL}/Class/Data/Inheritable.pm:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/Net/Amazon.pm:${PORTSDIR}/net/p5-Net-Amazon
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Text::Hatena.3 Text::Hatena::AutoLink.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601	# inherited from net/p5-Amazon
IGNORE=		requires perl 5.6.x or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
