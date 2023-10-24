PORTNAME=	vaultwarden
DISTVERSION=	1.29.2
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	mr@FreeBSD.org
COMMENT=	Bitwarden compatible backend server
WWW=		https://github.com/dani-garcia/vaultwarden

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS+=	libcapnp.so:devel/capnproto \
		libgmp.so:math/gmp \
		libnettle.so:security/nettle

USES=		cargo mysql:client pgsql ssl

# make makeplist > pkg-plist #One has to edit/review the generated plist
# make generate-plist && make check-plist
USE_GITHUB=	yes
GH_ACCOUNT=	dani-garcia
USE_RC_SUBR=	${PORTNAME}

USERS=		${WWWOWN}
GROUPS=		${WWWGRP}
PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

OPTIONS_DEFINE=	WEBVAULT
OPTIONS_DEFAULT=WEBVAULT

WEBVAULT_DESC=	Vaultwarden web (bw_web_builds)

WEBVAULT_RUN_DEPENDS=	${WWWDIR}/web-vault/index.html:www/vaultwarden-web_vault

# make cargo-crates > Makefile.crates

CARGO_FEATURES=	mysql postgresql sqlite #vendored_openssl
#CARGO_ENV+=	RUSTC_BOOTSTRAP=1

INSTALL_TARGET=	install-strip

SUB_LIST=	WWWGRP=${WWWGRP} \
		WWWOWN=${WWWOWN}

#post-patch:
#	${REINPLACE_CMD} 's/^rust-version = "1.60"/rust-version = "1.59"/' \
#		${WRKSRC}/Cargo.toml

post-install:
	${MKDIR} ${STAGEDIR}/${WWWDIR}/data
	${INSTALL} -m0600 ${FILESDIR}/${PORTNAME}_conf.in ${STAGEDIR}/${WWWDIR}/data/config.json.sample

.include <bsd.port.mk>
