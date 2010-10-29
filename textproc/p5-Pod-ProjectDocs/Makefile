# New ports collection makefile for:	Pod-ProjectDocs
# Date created:	   31 August 2005
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Pod-ProjectDocs
PORTVERSION=	0.39
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Generates CPAN like pod pages

RUN_DEPENDS=	p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Class-Data-Inheritable>=0:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		p5-JSON>=0.991:${PORTSDIR}/converters/p5-JSON \
		p5-Readonly>=0:${PORTSDIR}/devel/p5-Readonly \
		p5-Template-Toolkit>=0:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-URI>=0:${PORTSDIR}/net/p5-URI
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		pod2projdocs.1
MAN3=		Pod::ProjectDocs.3

.include <bsd.port.mk>
