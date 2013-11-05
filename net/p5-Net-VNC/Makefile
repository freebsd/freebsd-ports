# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Net-VNC
PORTVERSION=	0.40
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple VNC client

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Crypt-DES>=0:${PORTSDIR}/security/p5-Crypt-DES \
		p5-Image-Imlib2>=0:${PORTSDIR}/graphics/p5-Image-Imlib2 \
		p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
