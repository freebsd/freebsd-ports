# New ports collection makefile for:	Plack::Middleware::JSConcat
# Date created:		07 Apr 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Plack-Middleware-JSConcat
PORTVERSION=	0.29
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to concatenate JavaScripts

RUN_DEPENDS=	\
	p5-IPC-Run3>0:${PORTSDIR}/devel/p5-IPC-Run3 \
	p5-Plack>0:${PORTSDIR}/www/p5-Plack
BUILD_DEPENDS:=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Plack::Middleware::JSConcat.3

.include <bsd.port.mk>
