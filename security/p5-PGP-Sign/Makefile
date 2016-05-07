# Created by: Don Croyle <croyle@gelemna.org>
# $FreeBSD$

PORTNAME=	PGP-Sign
PORTVERSION=	0.20
PORTREVISION=	3
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Create detached PGP signatures for data

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ARGS=	PGP=${PGP} PGPSTYLE=${PGPSTYLE}

# Currently useful values for DEFAULTPGP are:
# PGP2 - PGP 2.6.* or a reasonable facsimile thereof
# GPG  - Gnu Privacy Guard

OPTIONS_SINGLE=	DEFAULTPGP
OPTIONS_SINGLE_DEFAULTPGP=	GNUPG PGP2
OPTIONS_DEFAULT=	GNUPG
PGP2_DESC=	PGP2 support
GNUPG_BUILD_DEPENDS=	gpg:security/gnupg
GNUPG_CONFIGURE_ON=	PGP=${LOCALBASE}/bin/gpg PGPSTYLE=GPG
GNUPG_RUN_DEPENDS=	gpg:security/gnupg
PGP2_BUILD_DEPENDS=	pgp:security/pgp
PGP2_CONFIGURE_ON=	PGP=${LOCALBASE}/bin/pgp PGPSTYLE=PGP2
PGP2_RUN_DEPENDS=	pgp:security/pgp

.include <bsd.port.mk>
