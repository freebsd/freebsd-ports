# New ports collection makefile for:	Finance::Quote
# Date created:		26 Dec 2000
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Finance-Quote
PORTVERSION=	1.04
CATEGORIES=	misc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Finance
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@protey.ru

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/HTML/TableExtract.pm:${PORTSDIR}/www/p5-HTML-TableExtract \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/HTTP/Request/Common.pm:${PORTSDIR}/www/p5-libwww
BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/HTML/TableExtract.pm:${PORTSDIR}/www/p5-HTML-TableExtract \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/HTTP/Request/Common.pm:${PORTSDIR}/www/p5-libwww

USE_PERL5=	yes

MAN3=		Finance::Quote::Tiaacref.3 Finance::Quote::Yahoo::Europe.3\
		Finance::Quote.3 Finance::Quote::VWD.3\
		Finance::Quote::Troweprice.3 Finance::Quote::Yahoo::Australia.3\
		Finance::Quote::Yahoo::USA.3 Finance::Quote::Trustnet.3\
		Finance::Quote::Yahoo::Base.3 Finance::Quote::Fidelity.3\
		Finance::Quote::ASX.3 Finance::Quote::DWS.3

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
	@cd ${WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL PREFIX=${PREFIX}

.include <bsd.port.mk>
