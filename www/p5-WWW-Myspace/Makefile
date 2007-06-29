# New ports collection makefile for:	p5-WWW-Myspace
# Date created:		2006-08-09
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	WWW-Myspace
PORTVERSION=	0.65
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	WWW
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Access MySpace.com profile information from Perl

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DateTime.pm:${PORTSDIR}/devel/p5-DateTime \
		${SITE_PERL}/${PERL_ARCH}/Params/Validate.pm:${PORTSDIR}/devel/p5-Params-Validate \
		${SITE_PERL}/Class/DBI.pm:${PORTSDIR}/databases/p5-Class-DBI \
		${SITE_PERL}/Class/DBI/AbstractSearch.pm:${PORTSDIR}/databases/p5-Class-DBI-AbstractSearch \
		${SITE_PERL}/Class/DBI/Loader.pm:${PORTSDIR}/databases/p5-Class-DBI-Loader \
		${SITE_PERL}/Config/General.pm:${PORTSDIR}/devel/p5-Config-General \
		${SITE_PERL}/Contextual/Return.pm:${PORTSDIR}/devel/p5-Contextual-Return \
		${SITE_PERL}/DateTime/Format/MySQL.pm:${PORTSDIR}/devel/p5-DateTime-Format-MySQL \
		${SITE_PERL}/IO/Prompt.pm:${PORTSDIR}/devel/p5-IO-Prompt \
		${SITE_PERL}/List/Compare.pm:${PORTSDIR}/misc/p5-List-Compare \
		${SITE_PERL}/Locale/SubCountry.pm:${PORTSDIR}/misc/p5-Locale-SubCountry \
		${SITE_PERL}/Math/Round.pm:${PORTSDIR}/math/p5-Math-Round \
		${SITE_PERL}/WWW/Mechanize.pm:${PORTSDIR}/www/p5-WWW-Mechanize \
		p5-Class-Factory-Util>=1.3:${PORTSDIR}/devel/p5-Class-Factory-Util \
		p5-Spiffy>=0.24:${PORTSDIR}/devel/p5-Spiffy \
		p5-YAML>=0.39:${PORTSDIR}/textproc/p5-YAML
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		add_friends.1 approve_friends.1 comment_myspace.1 \
		message_group.1
MAN3=		WWW::Myspace.3 WWW::Myspace::Comment.3 WWW::Myspace::Data.3 \
		WWW::Myspace::FriendAdder.3 WWW::Myspace::FriendChanges.3 \
		WWW::Myspace::Message.3 WWW::Myspace::MyBase.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500804	# Locale::SubCountry needs Perl 5.8.4
IGNORE=		requires Perl 5.8.4 or newer. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
