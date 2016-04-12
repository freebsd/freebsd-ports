# Created by: Alex Bakhtin <Alex.Bakhtin@gmail.com>
# $FreeBSD$

PORTNAME=	Net-MQTT
PORTVERSION=	1.143260
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	Alex.Bakhtin@gmail.com
COMMENT=	Net::MQTT - Perl modules for MQTT Protocol (http://mqtt.org/)

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Module-Pluggable>=0:devel/p5-Module-Pluggable \
		p5-Net-Pcap>=0:net/p5-Net-Pcap

RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Pod-Usage>=0:devel/p5-Pod-Usage

USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Changes ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."

.include <bsd.port.mk>
