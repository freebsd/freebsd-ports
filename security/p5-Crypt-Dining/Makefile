# New ports collection makefile for:	p5-Crypt-Dining
# Date created:				25 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Crypt-Dining
PORTVERSION=	1.01
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	The Dining Cryptographers' Protocol

BUILD_DEPENDS=	p5-Crypt-Random>=0:${PORTSDIR}/security/p5-Crypt-Random \
		p5-Net-Address-IPv4-Local>=0:${PORTSDIR}/net/p5-Net-Address-IPv4-Local
RUN_DEPENDS:=	${BUILD_DEPENDS}

MAN3=	Crypt::Dining.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
