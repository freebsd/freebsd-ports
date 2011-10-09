# New ports collection makefile for:	Dancer::Plugin::ValidationClass
# Date created:		27 Jul 2011
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Dancer-Plugin-ValidationClass
PORTVERSION=	0.112570
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for centralized input validation for Dancer

RUN_DEPENDS=	\
	p5-Dancer>0:${PORTSDIR}/www/p5-Dancer \
	p5-Validation-Class>0:${PORTSDIR}/devel/p5-Validation-Class
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Dancer::Plugin::ValidationClass.3

.include <bsd.port.mk>
