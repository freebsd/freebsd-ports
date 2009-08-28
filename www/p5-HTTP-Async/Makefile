# New ports collection makefile for:	p5-HTTP-Async
# Date created:				2007/02/14
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	HTTP-Async
PORTVERSION=	0.09
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Process multiple HTTP requests in parallel without blocking

BUILD_DEPENDS=	p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-HTTP-Server-Simple>=0:${PORTSDIR}/www/p5-HTTP-Server-Simple \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Test-HTTP-Server-Simple>=0:${PORTSDIR}/www/p5-Test-HTTP-Server-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=		HTTP::Async.3 HTTP::Async::Polite.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
