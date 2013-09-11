# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Dancer-Plugin-Passphrase
PORTVERSION=	2.0.0
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JAITKEN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Passphrases and Passwords as objects for Dancer

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Dancer>0:${PORTSDIR}/www/p5-Dancer \
		p5-Data-Entropy>=0.005:${PORTSDIR}/security/p5-Data-Entropy \
		p5-Digest-Bcrypt>0:${PORTSDIR}/security/p5-Digest-Bcrypt \
		p5-Digest-SHA>=5.008:${PORTSDIR}/security/p5-Digest-SHA
RUN_DEPENDS=	p5-Dancer>0:${PORTSDIR}/www/p5-Dancer \
		p5-Data-Entropy>=0.005:${PORTSDIR}/security/p5-Data-Entropy \
		p5-Digest-Bcrypt>0:${PORTSDIR}/security/p5-Digest-Bcrypt \
		p5-Digest-SHA>=5.008:${PORTSDIR}/security/p5-Digest-SHA

USES=		perl5
USE_PERL5=	configure

MAN3=		Dancer::Plugin::Passphrase.3

.include <bsd.port.mk>
