# New ports collection makefile for:	p5-Text-Hatena
# Date created:		2006-07-11
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Text-Hatena
PORTVERSION=	0.16
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Text
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Perl extension for formatting text with Hatena Style

RUN_DEPENDS=	p5-HTML-Parser>=3.26:${PORTSDIR}/www/p5-HTML-Parser \
		p5-Class-Data-Inheritable>=0.04:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		p5-Net-Amazon>=0.34:${PORTSDIR}/net/p5-Net-Amazon \
		p5-Template-Toolkit>=2.14:${PORTSDIR}/www/p5-Template-Toolkit \
		${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		p5-Text-VimColor>=0.11:${PORTSDIR}/textproc/p5-Text-VimColor
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Text::Hatena.3 Text::Hatena::AutoLink.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601	# inherited from net/p5-Amazon
IGNORE=		requires perl 5.6.x or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
