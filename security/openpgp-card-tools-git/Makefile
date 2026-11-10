PORTNAME=	openpgp-card-tools-git
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.9
CATEGORIES=	security

MAINTAINER=	christian@hofstede.de
COMMENT=	Git signing and verification with a focus on OpenPGP cards
WWW=		https://codeberg.org/openpgp-card/oct-git

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSES/Apache-2.0.txt
LICENSE_FILE_MIT=	${WRKSRC}/LICENSES/MIT.txt

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libpcsclite.so:devel/pcsc-lite
RUN_DEPENDS=	git:devel/git

USES=		cargo pkgconfig sqlite
USE_FORGEJO=	yes
FJ_ACCOUNT=	openpgp-card
FJ_PROJECT=	oct-git

PLIST_FILES=	bin/oct-git

.include <bsd.port.mk>
