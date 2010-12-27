# New ports collection makefile for:	p5-Tatsumaki
# Date created:		2010-12-11
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Tatsumaki
PORTVERSION=	0.1011
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/M/MI/MIYAGAWA
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Non-blocking web framework based on Plack and AnyEvent

RUN_DEPENDS=	p5-Any-Moose>=0:${PORTSDIR}/devel/p5-Any-Moose \
		p5-AnyEvent>=0:${PORTSDIR}/devel/p5-AnyEvent \
		p5-AnyEvent-HTTP>=0:${PORTSDIR}/www/p5-AnyEvent-HTTP \
		p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-Mouse>=0:${PORTSDIR}/devel/p5-Mouse \
		p5-Plack>=0:${PORTSDIR}/www/p5-Plack \
		p5-Text-MicroTemplate>=0:${PORTSDIR}/textproc/p5-Text-MicroTemplate \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny \
		p5-Twiggy>=0:${PORTSDIR}/www/p5-Twiggy

PERL_CONFIGURE=	yes

MAN3=		Tatsumaki.3 \
		Tatsumaki::MessageQueue.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
RUN_DEPENDS+=	p5-parent>=0:${PORTSDIR}/devel/p5-parent
.endif

.include <bsd.port.post.mk>
