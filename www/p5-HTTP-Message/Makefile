# Created by: Frederic Culot <culot@FreeBSD.org>
# $FreeBSD$

PORTNAME=	HTTP-Message
PORTVERSION=	6.06
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Representation of HTTP style messages

BUILD_DEPENDS=	p5-Encode-Locale>=1:${PORTSDIR}/converters/p5-Encode-Locale \
		p5-HTML-Parser>=3.33:${PORTSDIR}/www/p5-HTML-Parser \
		p5-HTTP-Date>=6:${PORTSDIR}/www/p5-HTTP-Date \
		p5-IO-HTML>0:${PORTSDIR}/devel/p5-IO-HTML \
		p5-LWP-MediaTypes>=6:${PORTSDIR}/www/p5-LWP-MediaTypes \
		p5-URI>=1.10:${PORTSDIR}/net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}

CONFLICTS=	p5-libwww-5*

USES=		perl5
USE_PERL5=	configure

post-patch:
		@${RM} ${WRKSRC}/lib/HTTP/Headers.pm.orig

.include <bsd.port.mk>
