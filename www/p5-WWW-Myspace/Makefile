# New ports collection makefile for:	p5-WWW-Myspace
# Date created:		2006-08-09
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	WWW-Myspace
PORTVERSION=	0.78
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Access MySpace.com profile information from Perl

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Params/Validate.pm:${PORTSDIR}/devel/p5-Params-Validate \
		${SITE_PERL}/Config/General.pm:${PORTSDIR}/devel/p5-Config-General \
		${SITE_PERL}/Contextual/Return.pm:${PORTSDIR}/devel/p5-Contextual-Return \
		${SITE_PERL}/Locale/SubCountry.pm:${PORTSDIR}/misc/p5-Locale-SubCountry \
		${SITE_PERL}/Time/ParseDate.pm:${PORTSDIR}/devel/p5-Time-modules \
		${SITE_PERL}/WWW/Mechanize.pm:${PORTSDIR}/www/p5-WWW-Mechanize \
		p5-Crypt-SSLeay>=0.53:${PORTSDIR}/security/p5-Crypt-SSLeay \
		p5-Spiffy>=0.24:${PORTSDIR}/devel/p5-Spiffy \
		p5-YAML>=0.39:${PORTSDIR}/textproc/p5-YAML
BUILD_DEPENDS=	${RUN_DEPENDS}

# inherited from p5-Locale-SubCountry
PERL_CONFIGURE=	5.8.4+

MAN1=		approve_friends.1 comment_myspace.1 \
		message_group.1
MAN3=		WWW::Myspace.3 WWW::Myspace::Comment.3 \
		WWW::Myspace::FriendChanges.3 \
		WWW::Myspace::Message.3 WWW::Myspace::MyBase.3

.include <bsd.port.mk>
