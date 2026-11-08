PORTNAME=	openpgp-card-ssh-agent
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.7
CATEGORIES=	security

MAINTAINER=	christian@hofstede.de
COMMENT=	SSH agent backed by OpenPGP card authentication keys
WWW=		https://codeberg.org/openpgp-card/ssh-agent

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSES/Apache-2.0.txt
LICENSE_FILE_MIT=	${WRKSRC}/LICENSES/MIT.txt

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libpcsclite.so:devel/pcsc-lite

USES=		cargo pkgconfig
USE_FORGEJO=	yes
FJ_ACCOUNT=	openpgp-card
FJ_PROJECT=	ssh-agent

PLIST_FILES=	bin/openpgp-card-ssh-agent

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/openpgp-card-ssh-agent

.include <bsd.port.mk>
