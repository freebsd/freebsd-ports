# New ports collection makefile for:	p5-Catalyst-Plugin-CookiedSession
# Date created:	   21 Nov 2008
# Whom:		   Denis Pokataev <catone@cpan.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-CookiedSession
PORTVERSION=	0.35
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	catone@cpan.org
COMMENT=	Catalyst Plugin for storing sessions in a browser cookie

BUILD_DEPENDS=	${SITE_PERL}/Class/Accessor/Fast.pm:${PORTSDIR}/devel/p5-Class-Accessor \
		${SITE_PERL}/Crypt/CBC.pm:${PORTSDIR}/security/p5-Crypt-CBC \
		${SITE_PERL}/${PERL_ARCH}/Crypt/Rijndael.pm:${PORTSDIR}/security/p5-Crypt-Rijndael \
		${SITE_PERL}/JSON/XS/VersionOneAndTwo.pm:${PORTSDIR}/converters/p5-JSON-XS-VersionOneAndTwo \
		${SITE_PERL}/Catalyst.pm:${PORTSDIR}/www/p5-Catalyst-Runtime
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Catalyst::Plugin::CookiedSession.3

.include <bsd.port.mk>
