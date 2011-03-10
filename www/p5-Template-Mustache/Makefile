# New ports collection makefile for:	p5-Template-Moustache
# Date created:		2011-01-13
# Whom:			Kurt Lidl <kurt.lidl@cello.com>
#
# $FreeBSD$
#

PORTNAME=	Template-Mustache
PORTVERSION=	v0.5.1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN/../../authors/id/P/PV/PVANDE
PKGNAMEPREFIX=	p5-

MAINTAINER=	kurt.lidl@cello.com
COMMENT=	Perl version of the fabulous Mustache template language

BUILD_DEPENDS=	p5-YAML-Syck>=1.15:${PORTSDIR}/textproc/p5-YAML-Syck \
		p5-Test-Mini-Unit>=v1.0.3:${PORTSDIR}/devel/p5-Test-Mini-Unit

PERL_CONFIGURE=	yes

MAN3=	Template::Mustache.3

.include <bsd.port.mk>
