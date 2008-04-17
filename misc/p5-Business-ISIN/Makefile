# New ports collection makefile for:	Business::ISIN
# Date created:				24 Jan 2002
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=	Business-ISIN
PORTVERSION=	0.20
CATEGORIES=	misc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Validate International Securities Identification Numbers

BUILD_DEPENDS=	${SITE_PERL}/Locale/Country.pm:${PORTSDIR}/misc/p5-Locale-Codes
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Business::ISIN.3

.include <bsd.port.mk>
