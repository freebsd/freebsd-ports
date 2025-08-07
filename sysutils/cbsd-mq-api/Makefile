PORTNAME=	cbsd-mq-api
DISTVERSION=	0.5
PORTREVISION=	6
CATEGORIES=	sysutils

MAINTAINER=	fbsd-ports@convectix.com
COMMENT=	Simplified API for creating and destroying CBSD virtual environments
WWW=		https://github.com/cbsd/cbsd-mq-api/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	cbsd
GH_TUPLE=	beanstalkd:go-beanstalk:52e4a01:beanstalkd/src/github.com/beanstalkd/go-beanstalk \
		gorilla:mux:v1.8.1:gorilla_mux/vendor/github.com/gorilla/mux \
		golang:crypto:v0.30.0:golang_crypto/vendor/golang.org/x/crypto

USE_RC_SUBR=	cbsd-mq-api

USERS=		cbsd
GROUPS=		cbsd

PLIST_FILES=	bin/cbsd-mq-api \
		"@sample etc/cbsd-mq-api.json.sample" \
		"@sample etc/cbsd_api_cloud_images.json.sample"

post-extract:
	${LN} -sf ${WRKSRC}/src ${WRKDIR}
	${LN} -sf ${WRKSRC} ${WRKDIR}/src/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/cbsd-mq-api
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-${GH_TAGNAME}/etc/cbsd-mq-api.json ${STAGEDIR}${PREFIX}/etc/cbsd-mq-api.json.sample
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-${GH_TAGNAME}/etc/cbsd_api_cloud_images.json ${STAGEDIR}${PREFIX}/etc/cbsd_api_cloud_images.json.sample

.include <bsd.port.mk>
