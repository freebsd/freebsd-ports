PORTNAME=	openpgp-card-ssh-agent
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.8
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
RUN_DEPENDS=	git:devel/git

USES=		cargo pkgconfig
USE_FORGEJO=	yes
FJ_ACCOUNT=	openpgp-card
FJ_PROJECT=	ssh-agent
FJ_TAGNAME=	e92466566a407fc4f21ee9754d55cc72ac92434b

PLIST_FILES=	bin/openpgp-card-ssh-agent

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/openpgp-card-ssh-agent

.include <bsd.port.mk>
