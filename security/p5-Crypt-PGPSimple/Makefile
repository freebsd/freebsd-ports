# New ports collection makefile for:	p5-Crypt-PGPSimple
# Date created:				May 25th 2002
# Whom:	      				Matjaz Prelog <rachek@si.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	Crypt-PGPSimple
PORTVERSION=	0.13
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Crypt
PKGNAMEPREFIX=	p5-

MAINTAINER=	rachek@si.FreeBSD.org
COMMENT=	Crypt::PGPSimple provides a simple object-oriented interface to PGP

RUN_DEPENDS=	${LOCALBASE}/bin/pgp:${PORTSDIR}/security/pgp

PERL_CONFIGURE=	yes

MAN3=		Crypt::PGPSimple.3

.include <bsd.port.mk>
