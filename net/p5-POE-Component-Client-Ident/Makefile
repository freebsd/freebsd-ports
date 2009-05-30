# New ports collection makefile for:	POE-Component-Client-Ident
# Date created:		6 May 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Client-Ident
PORTVERSION=	1.16
CATEGORIES=	net perl5 devel
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	POE component for non-blocking ident lookups

BUILD_DEPENDS=	p5-POE>=0.9999:${PORTSDIR}/devel/p5-POE
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		POE::Component::Client::Ident.3 \
		POE::Component::Client::Ident::Agent.3 \
		POE::Filter::Ident.3

.include <bsd.port.mk>
