# New ports collection makefile for:	p5-Email-Simple
# Date created:				August 31 2003
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$
#

PORTNAME=	Email-Simple
PORTVERSION=	1.61
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Email
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Simple, fast mail parser

PERL_CONFIGURE=	yes

MAN3=		Email::Simple.3

test:
	cd ${WRKSRC} ; make test

.include <bsd.port.mk>
