# Created by: Christopher Key <cjk32@cam.ac.uk>
# $FreeBSD$

PORTNAME=	Audio-M4P
PORTVERSION=	0.51
CATEGORIES=	multimedia perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	M4P / MP4 / m4a Quicktime audio and video tools

BUILD_DEPENDS=	p5-Crypt-Rijndael>=0:${PORTSDIR}/security/p5-Crypt-Rijndael \
		p5-Tree-Simple>=0:${PORTSDIR}/devel/p5-Tree-Simple \
		p5-Tree-Simple-View>=0:${PORTSDIR}/devel/p5-Tree-Simple-View
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

regression-test: build
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} test

.include <bsd.port.mk>
