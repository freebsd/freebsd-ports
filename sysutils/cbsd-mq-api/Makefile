PORTNAME=	cbsd-mq-api
PORTVERSION=	0.3
PORTREVISION=	22
CATEGORIES=	sysutils

MAINTAINER=	olevole@olevole.ru
COMMENT=	Simplified API for creating and destroying CBSD virtual environments
WWW=		https://www.bsdstore.ru/

LICENSE=	BSD2CLAUSE

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	cbsd
GH_TUPLE=	beanstalkd:go-beanstalk:3bed00be7a17:beanstalkd/src/github.com/beanstalkd/go-beanstalk \
		gorilla:mux:d07530f46e1e:gorilla_mux/vendor/github.com/gorilla/mux \
		golang:crypto:5ff15b29337e:golang_crypto/vendor/golang.org/x/crypto
USE_RC_SUBR=	cbsd-mq-api

USERS=		cbsd
GROUPS=		cbsd

PLIST_FILES=	bin/cbsd-mq-api \
		"@sample etc/cbsd-mq-api.json.sample"

post-extract:
	${LN} -sf ${WRKSRC}/src ${WRKDIR}
	${LN} -sf ${WRKSRC} ${WRKDIR}/src/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/cbsd-mq-api
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-${GH_TAGNAME}/etc/cbsd-mq-api.json ${STAGEDIR}${PREFIX}/etc/cbsd-mq-api.json.sample

.include <bsd.port.mk>
