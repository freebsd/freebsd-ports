# New ports collection makefile for:	p5-Mail-Field-Received
# Date created:				July 12 2004
# Whom:	      				Andrea Venturoli <freebsd@netfence.it>
#
# $FreeBSD$
#

PORTNAME=	Mail-Field-Received
PORTVERSION=	0.24
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Mail
PKGNAMEPREFIX=	p5-

MAINTAINER=	freebsd@netfence.it
COMMENT=	Perl5 modules for parsing of `Received' headers in e-mails.

BUILD_DEPENDS=	${SITE_PERL}/Mail/Field.pm:${PORTSDIR}/mail/p5-Mail-Tools
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Mail::Field::Received.3

.include <bsd.port.mk>
