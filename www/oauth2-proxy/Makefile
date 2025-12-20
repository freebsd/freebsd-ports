PORTNAME=	oauth2-proxy
PORTVERSION=	7.13.0
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	OAuth 2.0 proxy server
WWW=		https://github.com/oauth2-proxy/oauth2-proxy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules,1.25+
USE_GITHUB=	yes
USE_RC_SUBR=	oauth2_proxy

GO_MOD_DIST=	github
GO_MODULE=	github.com/${PORTNAME}/${PORTNAME}
GO_BUILDFLAGS=	-v -ldflags="-s -X github.com/${PORTNAME}/${PORTNAME}/v7/pkg/version.VERSION=${PORTVERSION}"

USER=		www
GROUP=		www

VAR_DIR?=	/var
LOG_DIR?=	${VAR_DIR}/log/${PORTNAME}
RUN_DIR?=	${VAR_DIR}/run/${PORTNAME}

SUB_LIST+=	GROUP=${GROUP} \
		LOG_DIR=${LOG_DIR} \
		PORTNAME=${PORTNAME} \
		PREFIX=${PREFIX} \
		RUN_DIR=${RUN_DIR} \
		USER=${USER}

post-install:
	${MKDIR} ${STAGEDIR}${LOG_DIR}
	${MKDIR} ${STAGEDIR}${RUN_DIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/${PORTNAME}.cfg.example ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.cfg.sample

.include <bsd.port.mk>
