# New ports collection makefile for:	p5-HTTP-Cookies-w3m
# Date created:		2006-08-27
# Whom:			Masahiro Teramoto <markun@onohara.to>
#
# $FreeBSD$
#

PORTNAME=	HTTP-Cookies-w3m
PORTVERSION=	0.01
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	Cookie storage and management for w3m

BUILD_DEPENDS=	${SITE_PERL}/Module/Install.pm:${PORTSDIR}/devel/p5-Module-Install
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=		HTTP::Cookies::w3m.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
