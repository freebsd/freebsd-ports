# New ports collection makefile for:	p5-Plack-Middleware-XForwardedFor
# Date created:		2010-12-13
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Plack-Middleware-XForwardedFor
PORTVERSION=	0.103060
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Plack middleware to handle X-Forwarded-For headers

RUN_DEPENDS=	p5-Net-Netmask>=1.9015:${PORTSDIR}/net-mgmt/p5-Net-Netmask \
		p5-Plack>=0.9913:${PORTSDIR}/www/p5-Plack \
		p5-Regexp-Common>=2010010201:${PORTSDIR}/textproc/p5-Regexp-Common

PERL_CONFIGURE=	yes

MAN3=		Plack::Middleware::XForwardedFor.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 508009
BUILD_DEPENDS+=	p5-ExtUtils-MakeMaker>=6.31:${PORTSDIR}/devel/p5-ExtUtils-MakeMaker
.endif

.if ${PERL_LEVEL} < 501100
RUN_DEPENDS+=	p5-parent>=0.223:${PORTSDIR}/devel/p5-parent
.endif

.include <bsd.port.post.mk>
