# Created by: Alex Bakhtin <Alex.Bakhtin@gmail.com>
# $FreeBSD$

PORTNAME=	AnyEvent-MQTT
PORTVERSION=	1.142640
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	Alex.Bakhtin@gmail.com
COMMENT=	AnyEvent Perl module for MQTT client

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Net-MQTT>=0:net/p5-Net-MQTT \
		p5-AnyEvent>=0:devel/p5-AnyEvent \
		p5-Module-Pluggable>=0:devel/p5-Module-Pluggable \
		p5-Sub-Name>=0:devel/p5-Sub-Name

TEST_DEPENDS=	p5-Pod-Usage>=0:devel/p5-Pod-Usage

USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/Changes ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."

.include <bsd.port.mk>
