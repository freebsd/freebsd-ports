PORTNAME=	pgp
PORTREVISION=	1

COMMENT=	PGP plugins for Claws Mail
WWW=		https://www.claws-mail.org/plugin.php?plugin=gpg

LIB_DEPENDS=	libgpg-error.so:security/libgpg-error \
		libgpgme.so:security/gpgme

CLAWS_PLUGINS_BUILD=	pgpcore pgpinline pgpmime smime

.include "../claws-mail/Makefile.claws"
.include <bsd.port.mk>
