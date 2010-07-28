# New ports collection makefile for:	p5-WWW-Pastebin-PastebinCom-Create
# Date created:		2009-03-10
# Whom:			bapt <baptiste.daroussin@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	WWW-Pastebin-PastebinCom-Create
PORTVERSION=	0.003
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Paste to http://pastebin.com from Perl

RUN_DEPENDS+=	${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	yes

MAN3=		WWW::Pastebin::PastebinCom::Create.3
PLIST_FILES+=	%%SITE_PERL%%/WWW/Pastebin/PastebinCom/Create.pm \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/WWW/Pastebin/PastebinCom/Create/.packlist
PLIST_DIRS+=	%%SITE_PERL%%/WWW/Pastebin/PastebinCom \
		%%SITE_PERL%%/WWW/Pastebin \
		%%SITE_PERL%%/WWW \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/WWW/Pastebin/PastebinCom/Create \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/WWW/Pastebin/PastebinCom \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/WWW/Pastebin \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/WWW

.include <bsd.port.mk>
