# New ports collection makefile for:	p5-Net-MovableType
# Date created:				Oct 21 2003
# Whom:					clsung@dragon2.net
#
# $FreeBSD$
#

PORTNAME=	Net-MovableType
PORTVERSION=	1.74
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A lightweight MovableType client Perl module

BUILD_DEPENDS=	p5-SOAP-Lite>=0:${PORTSDIR}/net/p5-SOAP-Lite
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::MovableType.3

.include <bsd.port.mk>
