# New ports collection makefile for:	p5-WWW-Pastebin-RafbNet-Create
# Date created:		2009-03-10
# Whom:			bapt <baptiste.daroussin@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	WWW-Pastebin-RafbNet-Create
PORTVERSION=	0.001
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	baptiste.daroussin@gmail.com
COMMENT=	Paste to http://rafb.net/ from Perl

RUN_DEPENDS+=	${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/Class/Data/Accessor.pm:${PORTSDIR}/devel/p5-Class-Data-Accessor

PERL_CONFIGURE=	yes

MAN3=		WWW::Pastebin::RafbNet::Create.3
PLIST_FILES+=	%%SITE_PERL%%/WWW/Pastebin/RafbNet/Create.pm \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/WWW/Pastebin/RafbNet/Create/.packlist
PLIST_DIRS+=	%%SITE_PERL%%/WWW/Pastebin/RafbNet \
		%%SITE_PERL%%/WWW/Pastebin \
		%%SITE_PERL%%/WWW \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/WWW/Pastebin/RafbNet/Create \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/WWW/Pastebin/RafbNet \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/WWW/Pastebin \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/WWW

.include <bsd.port.mk>
