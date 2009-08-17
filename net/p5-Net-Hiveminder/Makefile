# New ports collection makefile for:	p5-Net-Hiveminder
# Date created:		2008-03-24
# Whom:			Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Hiveminder
PORTVERSION=	0.08
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Perl interface to hiveminder.com

RUN_DEPENDS=	${SITE_PERL}/Email/Simple/Creator.pm:${PORTSDIR}/mail/p5-Email-Simple-Creator \
		${SITE_PERL}/Moose.pm:${PORTSDIR}/devel/p5-Moose \
		${SITE_PERL}/Term/Encoding.pm:${PORTSDIR}/devel/p5-Term-Encoding \
		${SITE_PERL}/Net/Jifty.pm:${PORTSDIR}/net/p5-Net-Jifty \
		${SITE_PERL}/Number/RecordLocator.pm:${PORTSDIR}/converters/p5-Number-RecordLocator
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::Hiveminder.3

.include <bsd.port.mk>
