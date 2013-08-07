# New ports collection makefile for:	www/p5-Template-Plugin-Number-Format
# Date created:				26 January 2006
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Template-Plugin-Number-Format
PORTVERSION=	1.02
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Plugin/filter interface to Number::Format

RUN_DEPENDS=	p5-Number-Format>0:${PORTSDIR}/textproc/p5-Number-Format \
		p5-Template-Toolkit>=2.07:${PORTSDIR}/www/p5-Template-Toolkit
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	Template::Plugin::Number::Format.3

.include <bsd.port.mk>
