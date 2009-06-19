# New ports collection makefile for:   p5-Net-SCP-Expect
# Date created:                        27 Feb 2006
# Whom:                                Simun Mikecin <numisemis@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	Net-SCP-Expect
PORTVERSION=	0.16
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	numisemis@yahoo.com
COMMENT=	Perl5 wrapper for scp that allows passwords via Expect

RUN_DEPENDS=	p5-Expect>=1.14:${PORTSDIR}/lang/p5-Expect \
		p5-Term-ReadPassword>=0.01:${PORTSDIR}/devel/p5-Term-ReadPassword

PERL_CONFIGURE=	yes

MAN3=		Net::SCP::Expect.3

.include <bsd.port.mk>
