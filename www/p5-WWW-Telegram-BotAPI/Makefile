# $FreeBSD$

PORTNAME=	WWW-Telegram-BotAPI
PORTVERSION=	0.10
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ROBERTOF
PKGNAMEPREFIX=	p5-

MAINTAINER=	gehm@physik.tu-berlin.de
COMMENT=	Perl implementation of the Telegram Bot API

LICENSE=	ART20 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-JSON-MaybeXS>=0:converters/p5-JSON-MaybeXS \
		p5-LWP-Protocol-https>=0:www/p5-LWP-Protocol-https \
		p5-URI-Encode>0:www/p5-URI-Encode

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
