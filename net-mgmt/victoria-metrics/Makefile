# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>

PORTNAME?=	victoria-metrics
PORTVERSION=	1.78.1		# don't forget to update BUILDINFO_TAG
DISTVERSIONPREFIX=	v
CATEGORIES=	net-mgmt

MAINTAINER=	danfe@FreeBSD.org
COMMENT?=	Fast, cost-effective, and scalable time series database

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake go:modules,no_targets
USE_RC_SUBR?=	${PORTNAME}
MAKE_ENV=	PKG_TAG=${DISTVERSIONPREFIX}${DISTVERSION} \
		GOOS=${OPSYS:tl} BUILDINFO_TAG=cf849aa \
		DATEINFO_TAG=${_GET_DATE:sh}
ALL_TARGET=	${PORTNAME}-pure

USE_GITHUB=	yes
GH_ACCOUNT=	VictoriaMetrics
GH_PROJECT=	VictoriaMetrics

.include "${.CURDIR}/../victoria-metrics/Makefile.deps"

USERS=		victoria-metrics
GROUPS=		victoria-metrics
VICTORIA_DATA?=	/var/db/victoria-metrics

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
	@cd ${INSTALL_WRKSRC}/docs && ${RM} robots.txt vm*
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MV} ${INSTALL_WRKSRC}/docs/* ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>

_GET_DATE=	TZ= ${STAT} -f %Sm -t %Y%m%d-%H%M%S ${WRKSRC}/.gitignore
