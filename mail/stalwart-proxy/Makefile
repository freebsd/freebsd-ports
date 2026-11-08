PORTNAME=	stalwart-proxy
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.5
CATEGORIES=	mail

MAINTAINER=	jsi@jules.de
COMMENT=	Multi-protocol e-mail migration proxy for Stalwart
WWW=		https://stalw.art/docs/migration/proxy/

LICENSE=		AGPLv3 SELv2
LICENSE_COMB=		dual
LICENSE_NAME_SELv2=	Stalwart Enterprise License 2.0
LICENSE_FILE_AGPLv3=	${WRKSRC}/LICENSES/AGPL-3.0-only.txt
LICENSE_FILE_SELv2=	${WRKSRC}/LICENSES/LicenseRef-SEL.txt
LICENSE_PERMS_SELv2=	pkg-mirror auto-accept

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	stalwartlabs
GH_PROJECT=	proxy
USE_RC_SUBR=	stalwart_proxy

# These tests start Redis/PostgreSQL containers through testcontainers
CARGO_TEST_AFTER_ARGS=	--skip tests::redis_store:: \
			--skip tests::sql_store::

SUB_FILES=	pkg-message
SUB_LIST=	USERS=${USERS} \
		GROUPS=${GROUPS}

USERS=	stalwart-proxy
GROUPS=	stalwart-proxy

PORTEXAMPLES=	config.dovecot-postfix.toml config.stalwart-upgrade.toml \
		dovecot-postfix-trust.conf migrate_v015_to_plan.py \
		migrate_v016_to_plan.py

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	@${REINPLACE_CMD} -E -e 's|/etc/proxy|${ETCDIR}|g' \
		-e 's|Run with:   proxy |Run with:   ${PORTNAME} |' \
		-e 's|^bind = \["\[::\]:([0-9]+)"\]|bind = ["0.0.0.0:\1", "[::]:\1"]|' \
		${WRKSRC}/resources/*.toml

post-install:
	${MV} ${STAGEDIR}${PREFIX}/bin/proxy ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${MKDIR} ${STAGEDIR}${ETCDIR}/tls
	${INSTALL_DATA} ${WRKSRC}/resources/config.sample.toml \
		${STAGEDIR}${ETCDIR}/config.toml.sample
	${INSTALL_DATA} ${FILESDIR}/mappings.tsv.sample ${STAGEDIR}${ETCDIR}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S|^|${WRKSRC}/resources/|} \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
