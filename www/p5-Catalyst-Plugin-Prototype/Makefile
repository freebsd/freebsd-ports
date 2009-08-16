# New ports collection makefile for:	www/p5-Catalyst-Plugin-Prototype
# Date created:				07 May 2005
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-Prototype
PORTVERSION=	1.33
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/M/MR/MRAMBERG
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Catalyst plugin for Prototype

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.7006:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Catalyst-Devel>=1.00:${PORTSDIR}/www/p5-Catalyst-Devel \
		p5-Class-Data-Inheritable>=0:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		p5-HTML-Prototype>=1.48:${PORTSDIR}/www/p5-HTML-Prototype
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.1+

MAN3=	Catalyst::Helper::Prototype.3 \
	Catalyst::Plugin::Prototype.3

post-extract:
	${RM} ${WRKSRC}/lib/Catalyst/Plugin/._Prototype.pm

.include <bsd.port.mk>
