# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-OpenID-Common
PORTVERSION=	1.19
CATEGORIES=	security net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Libraries shared between Net::OpenID::Consumer and Net::OpenID::Server

BUILD_DEPENDS=	p5-Crypt-DH-GMP>=0:${PORTSDIR}/net/p5-Crypt-DH-GMP \
		p5-Email-MIME-ContentType>=0:${PORTSDIR}/mail/p5-Email-MIME-ContentType \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-HTTP-Message>=0:${PORTSDIR}/www/p5-HTTP-Message \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
