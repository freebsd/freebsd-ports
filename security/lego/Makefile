PORTNAME=	lego
DISTVERSIONPREFIX=	v
DISTVERSION=	4.24.0
CATEGORIES=	security

MAINTAINER=	matt@matthoran.com
COMMENT=	Let's Encrypt client and ACME library written in Go
WWW=		https://github.com/go-acme/lego

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USES=		go:1.23,modules
GO_MODULE=	github.com/go-acme/lego/v4
GO_TARGET=	./cmd/lego
GO_BUILDFLAGS=	-ldflags '-X "main.version=${DISTVERSION}"'

SAMPLE_FILES=	deploy.sh.sample lego.sh.sample
SUB_FILES=	${SAMPLE_FILES} 604.lego pkg-message
SUB_LIST=	LEGO_USER=${LEGO_USER} \
		PORTNAME=${PORTNAME}

LEGO_USER?=	_lego

USERS=		${LEGO_USER}
GROUPS=		${LEGO_USER}

PERIODIC_DIRS=	etc/periodic/weekly
PERIODIC_FILES=	604.lego

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${PERIODIC_DIRS}
	${INSTALL_SCRIPT} ${WRKDIR}/${PERIODIC_FILES} ${STAGEDIR}${PREFIX}/${PERIODIC_DIRS}/${PERIODIC_FILES}
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/ssl/lego \
		${STAGEDIR}${ETCDIR} ${STAGEDIR}${WWWDIR}
.	for d in ${SAMPLE_FILES}
		${INSTALL_SCRIPT} ${WRKDIR}/${d} ${STAGEDIR}${ETCDIR}/${d}
.	endfor

.include <bsd.port.mk>
