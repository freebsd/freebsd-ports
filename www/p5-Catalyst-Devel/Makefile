# Ports collection makefile for:	www/p5-Catalyst-Devel
# Date created:				July 11, 2006
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Devel
PORTVERSION=	1.19
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	Catalyst Development Tools

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Catalyst-Action-RenderView>=0.04:${PORTSDIR}/www/p5-Catalyst-Action-RenderView \
		p5-Catalyst-Plugin-ConfigLoader>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-ConfigLoader \
		p5-Catalyst-Plugin-Static-Simple>=0.16:${PORTSDIR}/www/p5-Catalyst-Plugin-Static-Simple \
		p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Config-General>=0:${PORTSDIR}/devel/p5-Config-General \
		p5-File-Copy-Recursive>=0:${PORTSDIR}/devel/p5-File-Copy-Recursive \
		p5-Module-Install>=0.64:${PORTSDIR}/devel/p5-Module-Install \
		p5-Path-Class>=0.09:${PORTSDIR}/devel/p5-Path-Class \
		p5-Template-Toolkit>=2.14:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-parent>=0:${PORTSDIR}/devel/p5-parent
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.1+

MAN3=	Catalyst::Helper.3 \
	Module::Install::Catalyst.3 \
	Catalyst::Devel.3 \
	Catalyst::Restarter.3 \
	Catalyst::Restarter::Forking.3 \
	Catalyst::Restarter::Win32.3

.include <bsd.port.mk>
