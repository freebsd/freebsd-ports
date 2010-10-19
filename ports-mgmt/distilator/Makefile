# New ports collection makefile for:	distilator
# Date created:				19 Oct 2010
# Whom:					Emanuel Haupt <ehaupt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	distilator
PORTVERSION=	0.1
CATEGORIES=	ports-mgmt perl5
MASTER_SITES=	CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A command-line script to check the availability of a ports distfiles

RUN_DEPENDS=	p5-URI>=1.56:${PORTSDIR}/net/p5-URI \
		p5-HTTP-SimpleLinkChecker>=1.16:${PORTSDIR}/www/p5-HTTP-SimpleLinkChecker
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.0+

.include <bsd.port.mk>
