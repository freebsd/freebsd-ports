# New ports collection makefile for:	p5-Mail-Verify
# Date created:				2 August 2001
# Whom:					Pete Fritchman <petef@databits.net >
#
# $FreeBSD$
#

PORTNAME=	Mail-Verify
PORTVERSION=	0.02
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Mail
PKGNAMEPREFIX=	p5-

MAINTAINER=	petef@FreeBSD.org
COMMENT=	Perl module to verify email addresses

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Mail::Verify.3

.include <bsd.port.mk>
