PORTNAME=	victoria-logs
PORTVERSION=	0.28.0
DISTVERSIONPREFIX=	v
DISTVERSIONSUFFIX=-victorialogs
PORTREVISION=	1
CATEGORIES=	net-mgmt

MAINTAINER=	samm@FreeBSD.org
COMMENT=	Fast and easy-to-use, open source logs solution
WWW=		https://victoriametrics.com/products/victorialogs/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake go:modules,1.22,no_targets
USE_RC_SUBR?=	${PORTNAME}

MAKE_ENV=	PKG_TAG=v${PORTVERSION} GOOS=${OPSYS:tl} \
		BUILDINFO_TAG=tags-v${PORTVERSION}-victorialogs \
		DATEINFO_TAG=${_GET_DATE:sh} GOFLAGS=-buildvcs=false
ALL_TARGET=	${PORTNAME}-pure

USE_GITHUB=	yes
GH_ACCOUNT=	VictoriaMetrics
GH_PROJECT=	VictoriaMetrics

.include "${.CURDIR}/../victoria-logs/Makefile.deps"

USERS=		victoria-logs
GROUPS=		victoria-logs
VICTORIA_DATA?=	/var/db/victoria-logs

SUB_LIST+=	VICTORIA_DATA=${VICTORIA_DATA} \
		VICTORIA_USER=${USERS}

PLIST_SUB+=	VICTORIA_DATA=${VICTORIA_DATA} \
		VICTORIA_GROUP=${GROUPS} \
		VICTORIA_USER=${USERS}

OPTIONS_DEFINE=	DOCS

.if !defined(MASTERDIR)
do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/bin/${PORTNAME}-pure \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${VICTORIA_DATA}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MV} ${INSTALL_WRKSRC}/docs/VictoriaLogs/* ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>

_GET_DATE=	TZ= ${STAT} -f %Sm -t %Y%m%d-%H%M%S ${WRKSRC}/.gitignore
