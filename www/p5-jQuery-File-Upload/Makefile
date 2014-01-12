# $FreeBSD$

PORTNAME=	jQuery-File-Upload
PORTVERSION=	0.20
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for jQuery File Upload plugin

RUN_DEPENDS=	\
	convert:${PORTSDIR}/graphics/ImageMagick \
	p5-JSON-XS>0:${PORTSDIR}/converters/p5-JSON-XS \
	p5-Net-SSH2>0:${PORTSDIR}/net/p5-Net-SSH2 \
	p5-URI>0:${PORTSDIR}/net/p5-URI
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
