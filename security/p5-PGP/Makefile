# New ports collection makefile for:	p5-PGP
# Date created:				October 21st 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	PGP
PORTVERSION=	0.3a
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	PGP
PKGNAMEPREFIX=	p5-

MAINTAINER=	jfitz@FreeBSD.org

BUILD_DEPENDS=	pgp:${PORTSDIR}/security/pgp

USE_PERL5=	yes

MAN3=		PGP::Pipe.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

pre-configure:
		@${CP} ${WRKSRC}/PGP/Pipe.pm ${WRKSRC}

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
