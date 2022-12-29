PORTNAME=	rustypaste
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.2
PORTREVISION=	3
CATEGORIES=	www

MAINTAINER=	DtxdF@disroot.org
COMMENT=	Minimal file upload/pastebin service
WWW=		https://github.com/orhun/rustypaste/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	orhun
USE_RC_SUBR=	${PORTNAME}

SUB_LIST+=	USER="${USERS:[0]}"

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

PLIST_SUB+=	USER="${USERS:[0]}" \
		GROUP="${GROUPS:[0]}"

UPLOAD_PATH=	/var/db/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e '/^upload_path=/s#=.*#="${UPLOAD_PATH}"#' ${WRKSRC}/config.toml

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}/${UPLOAD_PATH}
	${ECHO_CMD} 'CONFIG="${ETCDIR}/${PORTNAME}.toml"' > ${STAGEDIR}${ETCDIR}/${PORTNAME}.env.sample
	${CP} ${WRKSRC}/config.toml ${STAGEDIR}${ETCDIR}/${PORTNAME}.toml.sample
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
