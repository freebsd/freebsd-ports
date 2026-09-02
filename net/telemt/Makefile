PORTNAME=	telemt
DISTVERSION=	3.5.5
CATEGORIES=	net

MAINTAINER=	vova@zote.me
COMMENT=	MTProxy for Telegram on Rust + Tokio
WWW=		https://github.com/telemt/telemt

LICENSE=	TELEM_PL_3
LICENSE_NAME=	TELEMT PL 3
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		cargo

USE_GITHUB=	yes
USE_RC_SUBR=	${PORTNAME}

USERS=		telemt
GROUPS=		telemt

PLIST_FILES=	bin/${PORTNAME} \
		"@sample ${ETCDIR_REL}/config.toml.sample ${ETCDIR_REL}/config.toml" \
		"@dir(telemt,telemt,0750) /var/db/${PORTNAME}"

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/config.toml ${STAGEDIR}${ETCDIR}/config.toml.sample
	@${MKDIR} ${STAGEDIR}/var/db/${PORTNAME}

.include <bsd.port.options.mk>

.if ${ARCH} == "i386"
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-i386-src_config_load_validate__web.rs
.endif

.include <bsd.port.mk>
