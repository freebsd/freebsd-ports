# Created by: Don Croyle <croyle@gelemna.org>
# $FreeBSD$

PORTNAME=	PGP-Sign
PORTVERSION=	0.20
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Create detached PGP signatures for data

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ARGS=	PGPS=${PGPS} PGPV=${PGPV} PGPSTYLE=${PGPSTYLE}

# If DEFAULTPGP isn't defined, it gets set to PGP2.  If you don't like
# the values that this process assigns to PGP (or PGPV and PGPS) and
# PGPSTYLE, they can be predefined.
#
# Currently useful values for DEFAULTPGP are:
# PGP2 - PGP 2.6.* or a reasonable facsimile thereof
# PGP5 - PGP 5 or a work-alike
# GPG  - Gnu Privacy Guard

.ifndef DEFAULTPGP
DEFAULTPGP=	GPG
.endif

.if (${DEFAULTPGP} == PGP2 )
BUILD_DEPENDS=	pgp:${PORTSDIR}/security/pgp
RUN_DEPENDS=	pgp:${PORTSDIR}/security/pgp
PGPSTYLE?=	PGP2
.ifndef PGP
PGP!=	which pgp || ${ECHO} ${PREFIX}/bin/pgp
.endif
.elif (${DEFAULTPGP} == PGP5 )
BUILD_DEPENDS=	pgps:${PORTSDIR}/security/pgp5
RUN_DEPENDS=	pgps:${PORTSDIR}/security/pgp5
PGPSTYLE?=	PGP5
.ifndef PGPS
PGPS!=	which pgps || ${ECHO} ${PREFIX}/bin/pgps
.endif
.ifndef PGPV
PGPV!=	which pgpv || ${ECHO} ${PREFIX}/bin/pgpv
.endif
.ifndef PGP
PGP!=	which pgp || ${ECHO} ${PREFIX}/bin/pgp
.endif
.elif (${DEFAULTPGP} == GPG)
BUILD_DEPENDS=	gpg:${PORTSDIR}/security/gnupg
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
