# New ports collection makefile for:	POE::Component::Server::PSGI
# Date created:		02 Apr 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Server-PSGI
PORTVERSION=	0.5
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to PSGI Server implementation for POE

RUN_DEPENDS=	\
	p5-Plack>0:${PORTSDIR}/www/p5-Plack \
	p5-libwww>0:${PORTSDIR}/www/p5-libwww \
	p5-POE>0:${PORTSDIR}/devel/p5-POE \
	p5-POE-Filter-HTTP-Parser>0:${PORTSDIR}/www/p5-POE-Filter-HTTP-Parser \
	p5-namespace-autoclean>0:${PORTSDIR}/devel/p5-namespace-autoclean
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	POE::Component::Server::PSGI.3 \
	Plack::Server::POE.3

.include <bsd.port.mk>
