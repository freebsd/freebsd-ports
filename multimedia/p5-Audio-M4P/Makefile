# New ports collection makefile for:	p5-Audio-M4P
# Date created:		2009-01-19
# Whom:			Christopher Key <cjk32@cam.ac.uk>
#
# $FreeBSD$
#

PORTNAME=	Audio-M4P
PORTVERSION=	0.51
CATEGORIES=	multimedia perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	cjk32@cam.ac.uk
COMMENT=	M4P / MP4 / m4a Quicktime audio and video tools

BUILD_DEPENDS=	p5-Crypt-Rijndael>=0:${PORTSDIR}/security/p5-Crypt-Rijndael \
		p5-Tree-Simple>=0:${PORTSDIR}/devel/p5-Tree-Simple \
		p5-Tree-Simple-View>=0:${PORTSDIR}/devel/p5-Tree-Simple-View

RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Audio::M4P.3 \
		Audio::M4P::Atom.3 \
		Audio::M4P::Decrypt.3 \
		Audio::M4P::QuickTime.3

regression-test: build
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} test

.include <bsd.port.mk>
