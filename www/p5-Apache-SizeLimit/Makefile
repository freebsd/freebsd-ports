# New ports collection makefile for:	p5-Apache-SizeLimit
# Date created:		2 August 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Apache-SizeLimit
DISTVERSION=	0.9
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Kill httpd processes if they grow too large

BUILD_DEPENDS=	mod_perl>=0:${PORTSDIR}/www/mod_perl \
		p5-Apache-Test>=0:${PORTSDIR}/www/p5-Apache-Test \
		p5-BSD-Resource>=0:${PORTSDIR}/devel/p5-BSD-Resource
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		${PORTNAME:S/-/::/g}.3

BROKEN=	conflicts with www/mod_perl

.include <bsd.port.mk>
