# New ports collection makefile for:	p5-Net-VNC
# Date created:		2006-07-29
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Net-VNC
PORTVERSION=	0.35
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	A simple VNC client

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Crypt/DES.pm:${PORTSDIR}/security/p5-Crypt-DES \
		${SITE_PERL}/Class/Accessor/Fast.pm:${PORTSDIR}/devel/p5-Class-Accessor \
		${SITE_PERL}/${PERL_ARCH}/Image/Imlib2.pm:${PORTSDIR}/graphics/p5-Image-Imlib2
#BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		vnccapture.1
MAN3=		Net::VNC.3

.include <bsd.port.mk>
