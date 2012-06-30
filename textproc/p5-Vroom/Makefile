# New ports collection makefile for:	p5-Vroom
# Date created:		2010-04-24
# Whom:			Li-Wen Hsu <lwhsu@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Vroom
PORTVERSION=	0.25
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:INGY
PKGNAMEPREFIX=	p5-

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Slide Shows in Vim

BUILD_DEPENDS=	p5-IO-All>=0:${PORTSDIR}/devel/p5-IO-All \
		p5-YAML-LibYAML>=0:${PORTSDIR}/textproc/p5-YAML-LibYAML \
		p5-Class-Field>=0:${PORTSDIR}/devel/p5-Class-Field \
		p5-File-HomeDir>=0:${PORTSDIR}/devel/p5-File-HomeDir \
		p5-Template-Toolkit-Simple>=0:${PORTSDIR}/www/p5-Template-Toolkit-Simple
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Vroom.3 Vroom::Vroom.3

.include <bsd.port.mk>
