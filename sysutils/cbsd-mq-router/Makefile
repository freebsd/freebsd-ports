# $FreeBSD$

PORTNAME=	cbsd-mq-router
PORTVERSION=	0.1
CATEGORIES=	sysutils

MAINTAINER=	olevole@olevole.ru
COMMENT=	CBSD message queue router

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	beanstalkd:net/beanstalkd

USES=		go

USE_GITHUB=	yes
GH_TAGNAME=	1605df2
GH_ACCOUNT=	cbsd
GH_PROJECT=	cbsd-mq-router
USE_RC_SUBR=	cbsd-mq-router

PLIST_FILES=	bin/cbsd-mq-router "@sample etc/cbsd-mq-router.json.sample"

GH_TUPLE=	beanstalkd:go-beanstalk:3bed00be7a17:beanstalkd/src/github.com/beanstalkd/go-beanstalk \
		golang:crypto:5ea612d1eb83:golang_crypto/vendor/golang.org/x/crypto \
		golang:term:6a3ed077a48d:golang_term/vendor/golang.org/x/term \
		golang:sys:9a76102bfb43:golang_sys/vendor/golang.org/x/sys

post-extract:
	${LN} -sf ${WRKSRC}/src ${WRKDIR}
	${LN} -sf ${WRKSRC} ${WRKDIR}/src/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/cbsd-mq-router
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-${GH_TAGNAME}/etc/cbsd-mq-router.json ${STAGEDIR}${PREFIX}/etc/cbsd-mq-router.json.sample

.include <bsd.port.mk>
