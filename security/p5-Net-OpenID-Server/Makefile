# New ports collection makefile for:	p5-Net-OpenID-Server
# Date created:				July 25th 2005
# Whom:					Alex Kapranoff <kappa@rambler-co.ru>
#
# $FreeBSD$
#

PORTNAME=	Net-OpenID-Server
PORTVERSION=	0.09
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	kappa@freebsd.org.ua
COMMENT=	Reference implementation of OpenID server

BUILD_DEPENDS=	${SITE_PERL}/Crypt/DH.pm:${PORTSDIR}/security/p5-Crypt-DH
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
INSTALL_TARGET=	pure_install

MAN3=		Net::OpenID::Server.3

.include <bsd.port.mk>
