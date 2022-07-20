PORTNAME=	pgpgpg
PORTVERSION=	0.13
PORTREVISION=	5
CATEGORIES=	security
MASTER_SITES=	https://mroth.net/pgpgpg/ \
		https://BSDforge.com/projects/source/security/pgpgpg/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Wrapper for GnuPG to simulate PGP 2.6.x

LICENSE=	GPLv2

BUILD_DEPENDS=	gnupg1>=0:security/gnupg1
RUN_DEPENDS=	gnupg1>=0:security/gnupg1

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gpg-path=${LOCALBASE}/bin/gpg
PLIST_FILES=	bin/pgpgpg

.include <bsd.port.mk>
