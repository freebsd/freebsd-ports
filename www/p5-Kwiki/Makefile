# New ports collection makefile for:	p5-Kwiki
# Date created:				Sat Jul 17 16:00:09 CST 2004
# Whom:	      				Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	Kwiki
PORTVERSION=	0.32
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Kwiki
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@dragon2.net
COMMENT=	The Kwiki Wiki Building Framework

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable \
		${SITE_PERL}/Spoon.pm:${PORTSDIR}/devel/p5-Spoon
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		kwiki.1
MAN3=		Kwiki.3 \
		Kwiki::Archive.3 \
		Kwiki::Base.3 \
		Kwiki::CGI.3 \
		Kwiki::Command.3 \
		Kwiki::Config.3 \
		Kwiki::ContentObject.3 \
		Kwiki::Cookie.3 \
		Kwiki::CSS.3 \
		Kwiki::Display.3 \
		Kwiki::Edit.3 \
		Kwiki::Formatter.3 \
		Kwiki::Files.3 \
		Kwiki::Htaccess.3 \
		Kwiki::Hub.3 \
		Kwiki::Icons.3 \
		Kwiki::Installer.3 \
		Kwiki::Javascript.3 \
		Kwiki::Pages.3 \
		Kwiki::Plugin.3 \
		Kwiki::Preferences.3 \
		Kwiki::Registry.3 \
		Kwiki::Status.3 \
		Kwiki::Template.3 Kwiki::Template::TT2.3 \
		Kwiki::Theme.3 Kwiki::Theme::Basic.3 \
		Kwiki::Toolbar.3 \
		Kwiki::Users.3 \
		Kwiki::Widgets.3 \

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		This port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
