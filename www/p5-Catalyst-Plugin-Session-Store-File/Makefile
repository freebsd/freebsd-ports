# New ports collection makefile for:	www/p5-Catalyst-Plugin-Session-Store-File
# Date created:				16 Nov 2005
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-Session-Store-File
PORTVERSION=	0.17
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	File storage backend for session data

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Module-Build>=0:${PORTSDIR}/devel/p5-Module-Build \
		p5-Cache-Cache>=1.02:${PORTSDIR}/devel/p5-Cache-Cache \
		p5-Catalyst-Plugin-Session>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-Session \
		p5-Class-Data-Inheritable>=0.04:${PORTSDIR}/devel/p5-Class-Data-Inheritable
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.1+

MAN3=	Catalyst::Plugin::Session::Store::File.3

.include <bsd.port.mk>
