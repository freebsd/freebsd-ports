# Created by: Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
# $FreeBSD$

PORTNAME=	Mail-OpenRelay-Simple
PORTVERSION=	0.02
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tjs@cdpa.nsysu.edu.tw
COMMENT=	Check if a mail server runs as an open relay

RUN_DEPENDS=	p5-Class-Accessor>=0.25:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Net-Telnet>=3.03:${PORTSDIR}/net/p5-Net-Telnet
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
