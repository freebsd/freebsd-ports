# New ports collection makefile for: p5-PGP-Sign
# Date created:		January 2, 1998
# Whom:			Don Croyle <croyle@gelemna.org>
#
# $FreeBSD$
#

PORTNAME=	PGP-Sign
PORTVERSION=	0.19
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	PGP
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Create detached PGP signatures for data

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	PGPS=${PGPS} PGPV=${PGPV} PGPSTYLE=${PGPSTYLE}

MAN3=		PGP::Sign.3

# If DEFAULTPGP isn't defined, it gets set to PGP2.  If you don't like
# the values that this process assigns to PGP (or PGPV and PGPS) and
# PGPSTYLE, they can be predefined.
#
# Currently useful values for DEFAULTPGP are:
# PGP2 - PGP 2.6.* or a reasonable facsimile thereof
# PGP5 - PGP 5 or a work-alike
# PGP6 - PGP 6.5 (effectively the same as PGP2)
# GPG  - Gnu Privacy Guard

.ifndef DEFAULTPGP
DEFAULTPGP=	PGP2
.endif

.if (${DEFAULTPGP} == PGP2 )
RUN_DEPENDS=	pgp:${PORTSDIR}/security/pgp
PGPSTYLE?=	PGP2
.ifndef PGP
PGP!=	which pgp || ${ECHO} ${PREFIX}/bin/pgp
.endif
.elif (${DEFAULTPGP} == PGP5 )
RUN_DEPENDS=	pgps:${PORTSDIR}/security/pgp5
PGPSTYLE?=	PGP5
.ifndef PGPS
PGPS!=	which pgps || ${ECHO} ${PREFIX}/bin/pgps
.endif
.ifndef PGPV
PGPV!=	which pgpv || ${ECHO} ${PREFIX}/bin/pgpv
.endif
.elif (${DEFAULTPGP} == PGP6)
RUN_DEPENDS=	pgp:${PORTSDIR}/security/pgp6
PGPSTYLE?=	PGP6
.ifndef PGP
PGP!=	which pgp || ${ECHO} ${PREFIX}/bin/pgp
.endif
.elif (${DEFAULTPGP} == GPG)
RUN_DEPENDS=	gpg:${PORTSDIR}/security/gnupg
PGPSTYLE?=	GPG
.ifndef PGP
PGP!=	which gpg || ${ECHO} ${PREFIX}/bin/gpg
.endif
.else
.error Unsupported DEFAULTPGP value.  See the Makefile for a list of acceptable values.
.endif

.ifdef PGP
PGPS?=	${PGP}
PGPV?=	${PGP}
.endif

.include <bsd.port.mk>
