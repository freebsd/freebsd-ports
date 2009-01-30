# New ports collection makefile for:	p5-Mail-Address-MobileJp
# Date created:				2004/08/04
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	Mail-Address-MobileJp
PORTVERSION=	0.09
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	An utility to detect an e-mail is mobile one or not

BUILD_DEPENDS=	${SITE_PERL}/Mail/Address.pm:${PORTSDIR}/mail/p5-Mail-Tools
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Mail::Address::MobileJp.3

.include <bsd.port.mk>
