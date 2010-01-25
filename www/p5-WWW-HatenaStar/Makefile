# New ports collection makefile for:	p5-WWW-HatenaStar
# Date created:		2009-04-07
# Whom:			Masahiro Teramoto <markun@onohara.to>
#
# $FreeBSD$
#

PORTNAME=	WWW-HatenaStar
PORTVERSION=	0.04
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	perl interface to Hatena::Star

BUILD_DEPENDS=	p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-YAML-Syck>=0:${PORTSDIR}/textproc/p5-YAML-Syck \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-WWW-HatenaLogin>=0:${PORTSDIR}/www/p5-WWW-HatenaLogin \
		p5-WWW-Mechanize>=0:${PORTSDIR}/www/p5-WWW-Mechanize
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=		WWW::HatenaStar.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
