# New ports collection makefile for:	p5-Dancer-Plugin-Passphrase
# Date created:				2012-01-24
# Whom:					Grzegorz Blach <magik@roorback.net>
#
# $FreeBSD$
#

PORTNAME=	Dancer-Plugin-Passphrase
PORTVERSION=	1.0.0
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JAITKEN
PKGNAMEPREFIX=	p5-

MAINTAINER=	magik@roorback.net
COMMENT=	Passphrases and Passwords as objects for Dancer

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Crypt-Eksblowfish>0:${PORTSDIR}/security/p5-Crypt-Eksblowfish \
		p5-Dancer>0:${PORTSDIR}/www/p5-Dancer \
		p5-Data-Entropy>0:${PORTSDIR}/security/p5-Data-Entropy
RUN_DEPENDS=	p5-Crypt-Eksblowfish>0:${PORTSDIR}/security/p5-Crypt-Eksblowfish \
		p5-Dancer>0:${PORTSDIR}/www/p5-Dancer \
		p5-Data-Entropy>0:${PORTSDIR}/security/p5-Data-Entropy

PERL_CONFIGURE=	yes

MAN3=		Dancer::Plugin::Passphrase.3

.include <bsd.port.mk>
