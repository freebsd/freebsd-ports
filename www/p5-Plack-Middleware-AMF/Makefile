# New ports collection makefile for:	Plack::Middleware::AMF
# Date created:		22 May 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Plack-Middleware-AMF
PORTVERSION=	0.02
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to use AMF with Plack

RUN_DEPENDS=	\
	p5-Data-AMF>=0.03:${PORTSDIR}/converters/p5-Data-AMF \
	p5-Plack>0:${PORTSDIR}/www/p5-Plack \
	p5-UNIVERSAL-require>0:${PORTSDIR}/devel/p5-UNIVERSAL-require
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Plack::Middleware::AMF.3

.include <bsd.port.mk>
