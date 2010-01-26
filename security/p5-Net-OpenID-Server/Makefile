# New ports collection makefile for:	p5-Net-OpenID-Server
# Date created:				July 25th 2005
# Whom:					Alex Kapranoff <kappa@rambler-co.ru>
#
# $FreeBSD$
#

PORTNAME=	Net-OpenID-Server
PORTVERSION=	1.02
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kappa@rambler-co.ru
COMMENT=	Reference implementation of OpenID server

BUILD_DEPENDS=	${SITE_PERL}/Crypt/DH.pm:${PORTSDIR}/security/p5-Crypt-DH \
		${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1 \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
INSTALL_TARGET=	pure_install

MAN3=		Net::OpenID::Server.3

.include <bsd.port.mk>
