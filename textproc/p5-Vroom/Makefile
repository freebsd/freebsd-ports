# New ports collection makefile for:	p5-Vroom
# Date created:		2010-04-24
# Whom:			Li-Wen Hsu <lwhsu@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Vroom
PORTVERSION=	0.22
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN/../../authors/id/I/IN/INGY
PKGNAMEPREFIX=	p5-

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Slide Shows in Vim

BUILD_DEPENDS=	${SITE_PERL}/IO/All.pm:${PORTSDIR}/devel/p5-IO-All \
		${SITE_PERL}/${PERL_ARCH}/YAML/XS.pm:${PORTSDIR}/textproc/p5-YAML-LibYAML \
		${SITE_PERL}/Class/Field.pm:${PORTSDIR}/devel/p5-Class-Field \
		${SITE_PERL}/File/HomeDir.pm:${PORTSDIR}/devel/p5-File-HomeDir \
		${SITE_PERL}/Template/Toolkit/Simple.pm:${PORTSDIR}/www/p5-Template-Toolkit-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Vroom.3 Vroom::Vroom.3

.include <bsd.port.mk>
