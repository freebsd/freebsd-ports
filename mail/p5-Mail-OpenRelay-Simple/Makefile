# Created by: Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
# $FreeBSD$

PORTNAME=	Mail-OpenRelay-Simple
PORTVERSION=	0.02
PORTREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Check if a mail server runs as an open relay

LICENSE=	ART10

BUILD_DEPENDS=	p5-Class-Accessor>=0.25:devel/p5-Class-Accessor \
		p5-Net-Telnet>=3.03:net/p5-Net-Telnet
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
