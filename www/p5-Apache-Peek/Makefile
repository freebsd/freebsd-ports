# New ports collection makefile for:	p5-Apache-Peek
# Date created:		24-Jul-2000
# Whom:			Leo Kim <leo@florida.sarang.net>
#
# $FreeBSD$
#

PORTNAME=	Apache-Peek
PORTVERSION=	0.9501
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	leo@florida.sarang.net

USE_PERL5=	YES
MAN3=		Apache::Peek.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL \
		CC="${CC}" CCFLAGS="${CFLAGS}"

.include <bsd.port.mk>
