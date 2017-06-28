# Created by: Don Croyle <croyle@gelemna.org>
# $FreeBSD$

PORTNAME=	PGP-Sign
PORTVERSION=	0.20
PORTREVISION=	4
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Create detached PGP signatures for data

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	gpg:security/gnupg
RUN_DEPENDS=	gpg:security/gnupg

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ARGS=	PGP=${LOCALBASE}/bin/gpg PGPSTYLE=GPG
NO_ARCH=	yes

.include <bsd.port.mk>
