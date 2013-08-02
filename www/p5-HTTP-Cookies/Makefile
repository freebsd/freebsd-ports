# Created by: Frederic Culot <culot@FreeBSD.org>
# $FreeBSD$

PORTNAME=	HTTP-Cookies
PORTVERSION=	6.01
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	HTTP Cookie jars

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-HTTP-Date>=6:${PORTSDIR}/www/p5-HTTP-Date \
		p5-HTTP-Message>=6:${PORTSDIR}/www/p5-HTTP-Message
BUILD_DEPENDS:=	${RUN_DEPENDS}

CONFLICTS=	p5-libwww-5*

USES=		perl5
USE_PERL5=	configure

MAN3=		HTTP::Cookies.3 \
		HTTP::Cookies::Microsoft.3 \
		HTTP::Cookies::Netscape.3

.include <bsd.port.mk>
