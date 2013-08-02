# New ports collection makefile for:	p5-PGP
# Date created:				October 21st 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	PGP
PORTVERSION=	0.3a
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl5 module to work with PGP messages

BUILD_DEPENDS=	pgp:${PORTSDIR}/security/pgp

USES=		perl5
USE_PERL5=	configure

MAN3=		PGP::Pipe.3

pre-configure:
		@${CP} ${WRKSRC}/PGP/Pipe.pm ${WRKSRC}

.include <bsd.port.mk>
