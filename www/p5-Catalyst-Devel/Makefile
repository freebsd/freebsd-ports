# Ports collection makefile for:	www/p5-Catalyst-Devel
# Date created:				July 11, 2006
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Devel
PORTVERSION=	1.24
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Catalyst Development Tools

RUN_DEPENDS=	p5-Catalyst-Action-RenderView>=0.10:${PORTSDIR}/www/p5-Catalyst-Action-RenderView \
		p5-Catalyst-Plugin-ConfigLoader>=0.23:${PORTSDIR}/www/p5-Catalyst-Plugin-ConfigLoader \
		p5-Catalyst-Plugin-Static-Simple>=0.21:${PORTSDIR}/www/p5-Catalyst-Plugin-Static-Simple \
		p5-Catalyst-Runtime>=5.80014:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Config-General>=2.42:${PORTSDIR}/devel/p5-Config-General \
		p5-File-ChangeNotify>=0.07:${PORTSDIR}/devel/p5-File-ChangeNotify \
		p5-File-Copy-Recursive>=0:${PORTSDIR}/devel/p5-File-Copy-Recursive \
		p5-File-ShareDir>=0:${PORTSDIR}/devel/p5-File-ShareDir \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Emulate-Class-Accessor-Fast>=0:${PORTSDIR}/devel/p5-MooseX-Emulate-Class-Accessor-Fast \
		p5-Path-Class>=0.09:${PORTSDIR}/devel/p5-Path-Class \
		p5-Proc-Background>=0:${PORTSDIR}/devel/p5-Proc-Background \
		p5-Template-Toolkit>=2.14:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean \
		p5-namespace-clean>=0:${PORTSDIR}/devel/p5-namespace-clean
BUILD_DEPENDS=	${RUN_DEPENDS}
BUILD_DEPENDS+=	p5-Test-Simple>=0.94:${PORTSDIR}/devel/p5-Test-Simple

PERL_CONFIGURE=	5.8.1+

MAN3=	Catalyst::Devel.3 \
	Catalyst::Helper.3 \
	Catalyst::Restarter.3 \
	Catalyst::Restarter::Forking.3 \
	Catalyst::Restarter::Win32.3 \
	Module::Install::Catalyst.3

.include <bsd.port.mk>
