# New ports collection makefile for: p5-PGP-Sign
# Date created:		January 2, 1998
# Whom:			Don Croyle <croyle@gelemna.ft-wayne.in.us>
#
# $FreeBSD$
#

PORTNAME=	p5-PGP-Sign
PORTVERSION=	0.16
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	PGP
DISTNAME=	PGP-Sign-0.16

MAINTAINER=	croyle@gelemna.ft-wayne.in.us

USE_PERL5=	yes

MAN3=		PGP::Sign.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

# You can either define one of these on the command line or accept the
# default (WITH_PGP2).  You can also predefine the values for PGP (or
# PGPS and PGPV) and PGPSTYLE if you don't like what this makefile
# would assign.
# WITH_PGP2 - use PGP 2.6.* or a reasonable facsimile thereof
# WITH_PGP5 - use PGP 5 or a work-alike
# WITH_GPG  - use Gnu Privacy Guard

.if !defined(WITH_PGP5) && !defined(WITH_GPG)
WITH_PGP2?=	yes
RUN_DEPENDS=	pgp:${PORTSDIR}/security/pgp
.ifndef PGP
PGP!=	which pgp || ${ECHO} ${PREFIX}/bin/pgp
.endif
PGPSTYLE?=	PGP2
.else
.ifdef WITH_PGP5
RUN_DEPENDS=	pgps:${PORTSDIR}/security/pgp5
.ifndef PGPS
PGPS!=	which pgps || ${ECHO} ${PREFIX}/bin/pgps
.endif
.ifndef PGPV
PGPV!=	which pgpv || ${ECHO} ${PREFIX}/bin/pgpv
.endif
PGPSTYLE?=	PGP5
.endif
.ifdef WITH_GPG
RUN_DEPENDS=	gpg:${PORTSDIR}/security/gnupg
.ifndef PGP
PGP!=	which gpg || ${ECHO} ${PREFIX}/bin/gpg
.endif
PGPSTYLE?=	GPG
.endif
.endif

.ifdef PGP
PGPS=	${PGP}
PGPV=	${PGP}
.endif
CONFIG_ARGS=	PGPS=${PGPS} PGPV=${PGPV} PGPSTYLE=${PGPSTYLE}

do-configure:
	@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL ${CONFIG_ARGS}

.include <bsd.port.mk>
