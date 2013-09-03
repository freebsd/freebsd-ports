# New ports collection makefile for:	p5-Template-Simple
# Date created:		02 December 2011
# Whom:			Ken McGlothlen <ken.mcglothlen@gmail.com>
#
# $FreeBSD$

PORTNAME=	Template-Simple
PORTVERSION=	0.06
CATEGORIES=	www textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ken.mcglothlen@gmail.com
COMMENT=	Template::Simple (a very fast templating module)

LICENSE=	ART20

BUILD_DEPENDS=	p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Template::Simple.3

.include <bsd.port.mk>
