# New ports collection makefile for:	Business::OnlinePayment::MerchantCommerce
# Date created:				24 February 2003
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Business-OnlinePayment-MerchantCommerce
PORTVERSION=	0.01
CATEGORIES=	misc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Business
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Business::OnlinePayment backend module for MerchantCommerce authorization service

BUILD_DEPENDS=	${SITE_PERL}/Business/OnlinePayment.pm:${PORTSDIR}/misc/p5-Business-OnlinePayment
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
SITE_PERL=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

MAN3=		Business::OnlinePayment::MerchantCommerce.3

.include <bsd.port.mk>
