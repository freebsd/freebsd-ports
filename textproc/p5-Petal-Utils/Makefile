# New ports collection makefile for:	p5-Petal-Utils
# Date created:				26 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Petal-Utils
PORTVERSION=	0.06
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/W/WM/WMCKEE
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Useful template modifiers for Petal

RUN_DEPENDS=	${SITE_PERL}/Petal.pm:${PORTSDIR}/textproc/p5-Petal \
		${SITE_PERL}/Date/Format.pm:${PORTSDIR}/devel/p5-TimeDate \
		${SITE_PERL}/URI/Escape.pm:${PORTSDIR}/net/p5-URI

MAN3=	Petal::Utils.3

PERL_MODBUILD=	yes

.include <bsd.port.mk>
