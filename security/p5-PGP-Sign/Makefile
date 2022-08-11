PORTNAME=	PGP-Sign
PORTVERSION=	1.04
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Create detached PGP signatures for data

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	gpg:security/gnupg
RUN_DEPENDS=	gpg:security/gnupg

USES=		perl5
USE_PERL5=	modbuild
CONFIGURE_ARGS=	PGP=${LOCALBASE}/bin/gpg PGPSTYLE=GPG
NO_ARCH=	yes

.include <bsd.port.mk>
