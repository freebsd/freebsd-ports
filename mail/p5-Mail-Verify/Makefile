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

BUILD_DEPENDS=	${SITE_PERL}/Net/DNS.pm:${PORTSDIR}/net/p5-Net-DNS
RUN_DEPENDS=	${BUILD_DEPENDS}

SITE_PERL=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Mail::Verify.3

.include <bsd.port.mk>
