# New ports collection makefile for:	p5-WWW-Plurk
# Date created:		2008-08-04
# Whom:			Yi-Hsuan Hsin <mhsin@mhsin.org>
#
# $FreeBSD$
#

PORTNAME=	WWW-Plurk
PORTVERSION=	0.02
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	mhsin@mhsin.org
COMMENT=	Unofficial plurk.com API

BUILD_DEPENDS=	p5-Time-Piece>=0:${PORTSDIR}/devel/p5-Time-Piece \
		p5-DateTime-Format-Mail>=0:${PORTSDIR}/devel/p5-DateTime-Format-Mail \
		${SITE_PERL}/HTTP/Cookies.pm:${PORTSDIR}/www/p5-libwww \
		p5-JSON>=2.00:${PORTSDIR}/converters/p5-JSON \
		p5-Test-Deep>=0:${PORTSDIR}/devel/p5-Test-Deep \
		p5-HTML-Tiny>=0:${PORTSDIR}/textproc/p5-HTML-Tiny \
		p5-Math-Base36>=0:${PORTSDIR}/math/p5-Math-Base36
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		WWW::Plurk.3 WWW::Plurk::Friend.3 WWW::Plurk::Message.3

.include <bsd.port.mk>
