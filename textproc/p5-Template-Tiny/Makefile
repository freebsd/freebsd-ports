# New ports collection makefile for:	p5-Template-Tiny
# Date created:		2010-03-17
# Whom:			ports@c0decafe.net
#
# $FreeBSD$
#

PORTNAME=	Template-Tiny
PORTVERSION=	0.11
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@c0decafe.net
COMMENT=	Template Toolkit reimplemented in as little code as possible

BUILD_DEPENDS=	p5-Capture-Tiny>=0.07:${PORTSDIR}/devel/p5-Capture-Tiny
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PERL5=	yes
PERL_CONFIGURE=	yes

MAN3=		Template::Tiny.3

.include <bsd.port.mk>
