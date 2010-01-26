# New ports collection makefile for:	EasyTCP
# Date created:				24 Jan 2002
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=	EasyTCP
PORTVERSION=	0.26
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Easily create TCP/IP clients and servers

BUILD_DEPENDS=	${SITE_PERL}/Crypt/RSA.pm:${PORTSDIR}/security/p5-Crypt-RSA
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::EasyTCP.3

.include <bsd.port.mk>
