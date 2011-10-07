# New ports collection makefile for:	Catalyst-Plugin-ErrorCatcher
# Date created:				17 November 2010
# Whom:					andrey@kostenko.name
#
# $FreeBSD$

PORTNAME=	Catalyst-Plugin-ErrorCatcher
PORTVERSION=	0.0.8.9
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CHISEL
PKGNAMEPREFIX=	p5-

MAINTAINER=	andrey@kostenko.name
COMMENT=	Catch application errors and emit them somewhere

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Catalyst-Runtime>=5.80000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Catalyst-Plugin-Authentication>=0.10010:${PORTSDIR}/www/p5-Catalyst-Plugin-Authentication \
		p5-Catalyst-Plugin-ConfigLoader>=0.22:${PORTSDIR}/www/p5-Catalyst-Plugin-ConfigLoader \
		p5-Catalyst-Plugin-Session>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-Session \
		p5-Catalyst-Plugin-Session-State-Cookie>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-Session-State-Cookie \
		p5-Catalyst-Plugin-Session-Store-File>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-Session-Store-File \
		p5-Catalyst-Plugin-StackTrace>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-StackTrace \
		p5-Config-General>0:${PORTSDIR}/devel/p5-Config-General \
		p5-Data-Dump>=0:${PORTSDIR}/devel/p5-Data-Dump \
		p5-DateTime>0:${PORTSDIR}/devel/p5-DateTime \
		p5-File-Find-Rule>0:${PORTSDIR}/devel/p5-File-Find-Rule \
		p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-FindBin-libs>0:${PORTSDIR}/devel/p5-FindBin-libs \
		p5-MIME-Lite>0:${PORTSDIR}/mail/p5-MIME-Lite \
		p5-MRO-Compat>=0:${PORTSDIR}/devel/p5-MRO-Compat \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-Path-Class>=0:${PORTSDIR}/devel/p5-Path-Class \
		p5-Module-Pluggable>0:${PORTSDIR}/devel/p5-Module-Pluggable \
		p5-namespace-autoclean>0:${PORTSDIR}/devel/p5-namespace-autoclean

BUILD_DEPENDS:=	${RUN_DEPENDS}

TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception

PERL_CONFIGURE=	yes

MAN3=	\
	Catalyst::Plugin::ErrorCatcher.3 \
	Catalyst::Plugin::ErrorCatcher::Email.3 \
	Catalyst::Plugin::ErrorCatcher::File.3 \
	Catalyst::Plugin::ErrorCatcher::Plugin::CleanUp::CaughtException.3 \
	Catalyst::Plugin::ErrorCatcher::Plugin::CleanUp::Pg::MissingColumn.3 \
	Catalyst::Plugin::ErrorCatcher::Plugin::CleanUp::TxnDo.3

.include <bsd.port.mk>
