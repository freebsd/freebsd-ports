# New ports collection makefile for:	p5-Template-Toolkit
# Date Created:				3 Mar, 2001
# Whom:					clive
#
# $FreeBSD$
#

PORTNAME=	Template-Toolkit
PORTVERSION=	2.00
CATEGORIES=	www textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Template
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

PERL_CONFIGURE=	yes

MAN1=	ttree.1 tpage.1
MAN3=	Template::Provider.3 Template::Plugin::XML::RSS.3 \
	Template::Plugin::Autoformat.3 Template::Filters.3 \
	Template::Plugin::Date.3 Template::Test.3 \
	Template::Plugin::Iterator.3 Template::Parser.3 Template::Base.3 \
	Template::Document.3 Template::Tutorial.3 Template::Exception.3 \
	Template::Plugins.3 Template::Plugin::URL.3 \
	Template::Plugin::Format.3 Template::Constants.3 \
	Template::Plugin::Table.3 Template::Iterator.3 \
	Template::Plugin::XML::XPath.3 Template::Service.3 \
	Template::Plugin::CGI.3 Template::Config.3 Template.3 \
	Template::Stash.3 Template::Plugin::Datafile.3 \
	Template::Plugin::Dumper.3 Template::Plugin.3 Template::Context.3 \
	Template::Plugin::DBI.3 Template::Plugin::Wrap.3 \
	Template::Plugin::XML::DOM.3

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
