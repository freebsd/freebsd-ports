# New ports collection makefile for:    p5-Crypt-Blowfish
# Date created:				2000/09/18
# Whom:					patrick@mindstep.com
#
# $FreeBSD$
#

PORTNAME=	Crypt-Blowfish
PORTVERSION=	2.06
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Crypt
PKGNAMEPREFIX=	p5-

MAINTAINER=	patrick@mindstep.com

USE_PERL5=	yes

MAN3=		Crypt::Blowfish.3

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL \
		CC="${CC}" CCFLAGS="${CFLAGS}"

.include <bsd.port.mk>
