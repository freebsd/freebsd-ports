# New ports collection makefile for:	Finance::Quote
# Date created:		26 Dec 2000
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Finance-Quote
PORTVERSION=	1.07
CATEGORIES=	misc perl5 finance
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Finance
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Get stock and mutual fund quotes from various exchanges

BUILD_DEPENDS=	${SITE_PERL}/HTML/TableExtract.pm:${PORTSDIR}/www/p5-HTML-TableExtract \
		${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Finance::Quote.3 Finance::Quote::AEX.3 Finance::Quote::ASX.3 \
		Finance::Quote::Cdnfundlibrary.3 Finance::Quote::DWS.3 \
		Finance::Quote::Fidelity.3 Finance::Quote::Fool.3 \
		Finance::Quote::Tdwaterhouse.3 Finance::Quote::Tiaacref.3 \
		Finance::Quote::Troweprice.3 Finance::Quote::Trustnet.3 \
		Finance::Quote::VWD.3 Finance::Quote::Yahoo::Asia.3 \
		Finance::Quote::Yahoo::Australia.3 \
		Finance::Quote::Yahoo::Base.3 Finance::Quote::Yahoo::Europe.3 \
		Finance::Quote::Yahoo::USA.3

.include <bsd.port.mk>
