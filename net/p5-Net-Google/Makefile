# New ports collection makefile for:	Net-Google
# Date created:	   04 June 2002
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Net-Google
PORTVERSION=	0.62
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Simple OOP-ish interface to the Google SOAP API

BUILD_DEPENDS=	${SITE_PERL}/SOAP/Lite.pm:${PORTSDIR}/net/p5-SOAP-Lite
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::Google.3 Net::Google::Cache.3 Net::Google::Response.3 \
		Net::Google::Search.3 Net::Google::Service.3 \
		Net::Google::Spelling.3 Net::Google::tool.3

post-patch:
	@${PERL} -pi -e 's/CPAN/ExtUtils/' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
