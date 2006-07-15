# New ports collection makefile for:	p5-Spread
# Date created:				12 Jun 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Spread
PORTVERSION=	3.17.3.1.07
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/J/JE/JESUS
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-3.17.3-1.07

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Perl extension for the Spread group communication system

BROKEN=		fails to deinstall cleanly

LIB_DEPENDS=	spread.1:${PORTSDIR}/net/spread

MAN3=	Spread.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
