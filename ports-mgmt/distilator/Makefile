# New ports collection makefile for:	distilator
# Date created:				19 Oct 2010
# Whom:					Emanuel Haupt <ehaupt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	distilator
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	ports-mgmt perl5
MASTER_SITES=	CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A command-line script to check the availability of a ports distfiles

RUN_DEPENDS=	p5-URI>=1.56:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/HTTP/Request.pm:${PORTSDIR}/www/p5-libwww
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.10.1+

.include <bsd.port.mk>
