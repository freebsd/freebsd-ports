# New ports collection makefile for:   p5-Net-SCP-Expect
# Date created:                        27 Feb 2006
# Whom:                                Simun Mikecin <numisemis@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	Net-SCP-Expect
PORTVERSION=	0.12
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	numisemis@yahoo.com
COMMENT=	Perl5 wrapper for scp that allows passwords via Expect

BUILD_DEPENDS=	${SITE_PERL}/Expect.pm:${PORTSDIR}/lang/p5-Expect
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::SCP::Expect.3

.include <bsd.port.mk>
