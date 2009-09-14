# New ports collection makefile for:	p5-WWW-Plurk
# Date created:		2008-08-04
# Whom:			Yi-Hsuan Hsin <mhsin@mhsin.org>
#
# $FreeBSD$
#

PORTNAME=	WWW-Plurk
PORTVERSION=	0.02
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	mhsin@mhsin.org
COMMENT=	Unofficial plurk.com API

RUN_DEPENDS=	p5-DateTime-Format-Mail>=0:${PORTSDIR}/devel/p5-DateTime-Format-Mail \
		p5-HTML-Tiny>=0:${PORTSDIR}/textproc/p5-HTML-Tiny \
		p5-JSON>=2.00:${PORTSDIR}/converters/p5-JSON1 \
		p5-Math-Base36>=0:${PORTSDIR}/math/p5-Math-Base36 \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
BUILD_DEPENDS=	${RUN_DEPENDS}
BUILD_DEPENDS+=	p5-Test-Deep>=0:${PORTSDIR}/devel/p5-Test-Deep

PERL_CONFIGURE=	yes

MAN3=		WWW::Plurk.3 WWW::Plurk::Friend.3 WWW::Plurk::Message.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500905
RUN_DEPENDS+=	p5-Time-Piece>=0:${PORTSDIR}/devel/p5-Time-Piece
.endif

.include <bsd.port.post.mk>
