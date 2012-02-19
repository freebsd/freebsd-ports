# New ports collection makefile for:	p5-HTTP-Negotiate
# Date created:				2011-04-15
# Whom:					Frederic Culot <culot@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	HTTP-Negotiate
PORTVERSION=	6.01
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Implementation of the HTTP content negotiation algorithm

BUILD_DEPENDS=	p5-HTTP-Message>=6:${PORTSDIR}/www/p5-HTTP-Message
RUN_DEPENDS=	p5-HTTP-Message>=6:${PORTSDIR}/www/p5-HTTP-Message

CONFLICTS=	p5-libwww-5*

PERL_CONFIGURE=	yes

MAN3=		HTTP::Negotiate.3

.include <bsd.port.mk>
