PORTNAME=	cbsd-mq-router
PORTVERSION=	0.2
PORTREVISION=	29
CATEGORIES=	sysutils

MAINTAINER=	olevole@olevole.ru
COMMENT=	CBSD message queue router
WWW=		https://github.com/cbsd/cbsd-mq-router

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	beanstalkd:net/beanstalkd

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	cbsd
USE_RC_SUBR=	cbsd-mq-router

PLIST_FILES=	bin/cbsd-mq-router "@sample etc/cbsd-mq-router.json.sample"

GH_TUPLE=	beanstalkd:go-beanstalk:3bed00be7a17:beanstalkd/src/github.com/beanstalkd/go-beanstalk \
		golang:crypto:5ea612d1eb83:golang_crypto/vendor/golang.org/x/crypto \
		golang:term:6a3ed077a48d:golang_term/vendor/golang.org/x/term \
		golang:sys:v0.5.0:golang_sys/vendor/golang.org/x/sys

post-extract:
	${LN} -sf ${WRKSRC}/src ${WRKDIR}
	${LN} -sf ${WRKSRC} ${WRKDIR}/src/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/cbsd-mq-router
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-${GH_TAGNAME}/etc/cbsd-mq-router.json ${STAGEDIR}${PREFIX}/etc/cbsd-mq-router.json.sample

.include <bsd.port.mk>
