# New ports collection makefile for:	p5-File-Mork
# Date created:		2007-11-06
# Whom:			Masahiro Teramoto <markun@onohara.to>
#
# $FreeBSD$
#

PORTNAME=	File-Mork
PORTVERSION=	0.3
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SIMONW
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	A module to read Mozilla URL history files

BUILD_DEPENDS=	p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser
RUN_DEPENDS=	p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser

USES=		perl5
USE_PERL5=	configure

MAN1=		mork.1
MAN3=		File::Mork.3

.include <bsd.port.mk>
