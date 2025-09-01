PORTNAME=	vaultwarden
DISTVERSION=	1.34.3
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	mr@FreeBSD.org
COMMENT=	Bitwarden compatible backend server
WWW=		https://github.com/dani-garcia/vaultwarden

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_i386=    doesn't buld on pkg builder

LIB_DEPENDS+=	libcapnp.so:devel/capnproto \
		libgmp.so:math/gmp \
		libnettle.so:security/nettle

USES=		cargo ssl

# make makeplist > pkg-plist #One has to edit/review the generated plist
# make generate-plist && make check-plist
USE_GITHUB=	yes
GH_ACCOUNT=	dani-garcia
USE_RC_SUBR=	${PORTNAME}

USERS=		${WWWOWN}
GROUPS=		${WWWGRP}
PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

OPTIONS_DEFINE=	WEBVAULT S3
OPTIONS_MULTI=	DATABASE
OPTIONS_MULTI_DATABASE=	MYSQL PGSQL SQLITE
OPTIONS_DEFAULT= WEBVAULT ${OPTIONS_MULTI_DATABASE}

DATABASE_DESC=	Database support
WEBVAULT_DESC=	Vaultwarden web (bw_web_builds)
S3_DESC=        S3 storage backend support (experimental)

MYSQL_USES=	mysql:client
MYSQL_VARS=	cargo_features+=mysql
PGSQL_USES=	pgsql
PGSQL_VARS=	cargo_features+=postgresql
SQLITE_VARS=	cargo_features+=sqlite
WEBVAULT_RUN_DEPENDS=	${WWWDIR}/web-vault/index.html:www/vaultwarden-web_vault
S3_VARS=        cargo_features+=s3

# make cargo-crates > Makefile.crates

CARGO_FEATURES=	--no-default-features
#CARGO_ENV+=	RUSTC_BOOTSTRAP=1

INSTALL_TARGET=	install-strip

SUB_LIST=	WWWGRP=${WWWGRP} \
 		WWWOWN=${WWWOWN}

.include <bsd.port.pre.mk>

# avoid LTO-induced address space exhaustion
.if ${ARCH:Marmv?} || ${ARCH} == i386
LTO_UNSAFE=	yes
CARGO_ENV+=	CARGO_PROFILE_RELEASE_LTO=false
.endif

#post-patch:
#	${REINPLACE_CMD} 's/^rust-version = "1.60"/rust-version = "1.59"/' \
#		${WRKSRC}/Cargo.toml

pre-install:
	${MKDIR} ${STAGEDIR}/${WWWDIR}/data
	# @${ECHO_CMD} "@owner ${WWWOWN}" >> ${PLIST}
	# @${ECHO_CMD} "@group ${WWWGRP}" >> ${PLIST}
	# @${ECHO_CMD} "@mode 755" >> ${PLIST}
	# @${ECHO_CMD} "${STAGEDIR}/${WWWDIR}/data" >> ${PLIST}
	# @${ECHO_CMD} "@mode" >> ${PLIST}
	# @${ECHO_CMD} "@group" >> ${PLIST}
	# @${ECHO_CMD} "@owner" >> ${PLIST}
	${MKDIR} ${STAGEDIR}/${ETCDIR}/rc.conf.d
	${INSTALL} -m0600 ${FILESDIR}/${PORTNAME}_conf.in ${STAGEDIR}/${LOCALBASE}/etc/rc.conf.d/${PORTNAME}.sample

#post-install:

.include <bsd.port.post.mk>
