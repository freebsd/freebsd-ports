PORTNAME=	telemt
DISTVERSION=	3.4.22
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

PLIST_FILES=	bin/${PORTNAME} \
		"@sample ${ETCDIR_REL}/config.toml.sample ${ETCDIR_REL}/config.toml"

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/config.toml ${STAGEDIR}${ETCDIR}/config.toml.sample

.include <bsd.port.mk>
