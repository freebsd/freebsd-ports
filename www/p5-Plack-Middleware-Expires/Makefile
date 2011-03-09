# New ports collection makefile for:	p5-Plack-Middleware-Expires
# Date created:		2011-02-03
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Plack-Middleware-Expires
PORTVERSION=	0.03
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Perl module mod_expires for Plack

RUN_DEPENDS=	p5-Plack>=0.9937:${PORTSDIR}/www/p5-Plack \
		p5-Try-Tiny>=0.06:${PORTSDIR}/lang/p5-Try-Tiny \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	yes

MAN3=		Plack::Middleware::Expires.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
RUN_DEPENDS+=	p5-parent>=0:${PORTSDIR}/devel/p5-parent
.endif

.include <bsd.port.post.mk>
