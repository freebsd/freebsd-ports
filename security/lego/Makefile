# $FreeBSD$

PORTNAME=	lego
DISTVERSIONPREFIX=	v
DISTVERSION=	2.7.1
CATEGORIES=	security

MAINTAINER=	matt@matthoran.com
COMMENT=	Let's Encrypt client and ACME library written in Go

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USES=		go

GO_PKGNAME=	github.com/go-acme/lego
GO_TARGET=	${GO_PKGNAME}/cmd/lego
GO_BUILDFLAGS=	-ldflags '-X "main.version=${GH_TAGNAME}"'

USE_GITHUB=	yes
GH_ACCOUNT=	go-acme

SAMPLE_FILES=	lego.sh.sample deploy.sh.sample
SUB_FILES=	604.lego pkg-message ${SAMPLE_FILES}
SUB_LIST=	PORTNAME=${PORTNAME} LEGO_USER=${LEGO_USER}

PERIODIC_DIRS=	etc/periodic/weekly
PERIODIC_FILES=	604.lego

LEGO_USER?=	_lego

USERS=		${LEGO_USER}
GROUPS=		${LEGO_USER}

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${PERIODIC_DIRS}
	${INSTALL_SCRIPT} ${WRKDIR}/${PERIODIC_FILES} ${STAGEDIR}${PREFIX}/${PERIODIC_DIRS}/${PERIODIC_FILES}
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/ssl/lego \
		${STAGEDIR}${ETCDIR} ${STAGEDIR}${WWWDIR}
.	for d in ${SAMPLE_FILES}
		${INSTALL_SCRIPT} ${WRKDIR}/${d} ${STAGEDIR}${ETCDIR}/${d}
.	endfor

.include <bsd.port.mk>
