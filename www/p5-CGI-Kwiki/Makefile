# New ports collection makefile for:		p5-CGI-Kwiki
# Date created:					14th October 2003
# Whom:	      					clsung@dragon2.net
#
# $FreeBSD$
#

PORTNAME=	CGI-Kwiki
PORTVERSION=	0.18
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A Quickie Wiki Package that's not too Tricky

BUILD_DEPENDS=	${SITE_PERL}/CGI.pm:${PORTSDIR}/www/p5-CGI.pm
RUN_DEPENDS=	${BUILD_DEPENDS} \
		${SITE_PERL}/Locale/Maketext.pm:${PORTSDIR}/devel/p5-Locale-Maketext

PERL_CONFIGURE=	yes

MAN1=		kwiki-install.1
MAN3=		CGI::Kwiki.3 \
		CGI::Kwiki::Blog.3 CGI::Kwiki::CGI.3 CGI::Kwiki::Changes.3 \
		CGI::Kwiki::Config.3 CGI::Kwiki::Config_yaml.3 \
		CGI::Kwiki::Cookie.3 CGI::Kwiki::Database.3 \
		CGI::Kwiki::Display.3 CGI::Kwiki::Driver.3 CGI::Kwiki::Edit.3 \
		CGI::Kwiki::Formatter.3 CGI::Kwiki::Import.3 \
		CGI::Kwiki::Javascript.3 CGI::Kwiki::Metadata.3 \
		CGI::Kwiki::New.3 CGI::Kwiki::Pages.3 \
		CGI::Kwiki::Pages::zh_cn.3 CGI::Kwiki::Pages::zh_tw.3 \
		CGI::Kwiki::Plugin.3 CGI::Kwiki::Plugin::Diff.3 \
		CGI::Kwiki::Prefs.3 CGI::Kwiki::Privacy.3 \
		CGI::Kwiki::Scripts.3 CGI::Kwiki::Search.3 \
		CGI::Kwiki::Slides.3 CGI::Kwiki::Style.3 \
		CGI::Kwiki::Template.3

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
