# $FreeBSD$

PORTNAME=	WWW-Shorten
PORTVERSION=	3.06
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Abstract interface to URL shortening sites

BUILD_DEPENDS=	p5-libwww>=5.75:${PORTSDIR}/www/p5-libwww \
		p5-Config-Auto>=0:${PORTSDIR}/devel/p5-Config-Auto \
		p5-URI>=1.27:${PORTSDIR}/net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
