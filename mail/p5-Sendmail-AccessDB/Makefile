# New ports collection makefile for:	p5-Sendmail-AccessDB
# Date created:				29 Jun 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	Sendmail-AccessDB
PORTVERSION=	0.09
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Perl5 interface to the Sendmail access.db list

BUILD_DEPENDS=	${SITE_PERL}/mach/BerkeleyDB.pm:${PORTSDIR}/databases/p5-BerkeleyDB
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.6+
MAKE_JOBS_SAFE=	yes

MAN3=		Sendmail::AccessDB.3

.include <bsd.port.mk>
