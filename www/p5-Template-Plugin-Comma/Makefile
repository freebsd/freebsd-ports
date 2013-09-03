# New ports collection makefile for:	p5-Template-Plugin-Comma
# Date created:		19 August 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	Template-Plugin-Comma
PORTVERSION=	0.04
CATEGORIES=	www textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	TT Plugin to commify numbers

BUILD_DEPENDS=	p5-Template-Toolkit>=0:${PORTSDIR}/www/p5-Template-Toolkit
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Template::Plugin::Comma.3

.include <bsd.port.mk>
