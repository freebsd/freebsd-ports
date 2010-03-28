# New ports collection makefile for:	p5-Net-VNC
# Date created:		2006-07-29
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Net-VNC
PORTVERSION=	0.37
PORTREVISION=	2
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A simple VNC client

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Crypt/DES.pm:${PORTSDIR}/security/p5-Crypt-DES \
		${SITE_PERL}/${PERL_ARCH}/Image/Imlib2.pm:${PORTSDIR}/graphics/p5-Image-Imlib2 \
		${SITE_PERL}/Class/Accessor/Fast.pm:${PORTSDIR}/devel/p5-Class-Accessor
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		vnccapture.1
MAN3=		Net::VNC.3

.include <bsd.port.mk>
